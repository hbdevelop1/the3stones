
#include "classids.h"
#include "objectsmanager.h"
#include "common.h"

#include "MemNew.h"

typedef Object * (*ObjectsCreators)(void);

static ObjectsCreators objectscreators[]=
{
	NULL,
	NULL,
	NULL,
	CountDown_Creator,
	game_Creator,
	TimeOut_Creator,
	Intro_Creator,
};

Object * globalobjects[CLASSIDS];


ObjectsManager::ObjectsManager()
{
	for(int i=0;i<CLASSIDS;++i)
		globalobjects[i]=NULL;

	reset();
}

ObjectsManager::~ObjectsManager()
{
}

void ObjectsManager::reset()
{
	activeobjectstail.next=&activeobjects;
	activeobjectstail.prev=&activeobjects;

	activeobjects.next=&activeobjectstail;
	activeobjects.prev=&activeobjectstail;
#if (DEBUGMODE & TESTING)
	activeobjectstail.name='t';
	activeobjects.name='a';
#endif //DEBUGMODE & TESTING

	DelayedPops.NbrOfPopsToRun=0;
}

void ObjectsManager::FastInsertBefore(Object * newobj, Object * before)
{
	newobj->prev=before->prev;
	newobj->next=before;
	newobj->prev->next=newobj;
	before->prev=newobj;
}
void ObjectsManager::PushBack(int classid)
{
	hbassert(classid);
	hbassert(objectscreators[classid]);

	Object * newobj = objectscreators[classid]();
	newobj->SetFlag(Object::e_FLAG_DELETE_ON_POP);

	PushBack(newobj);
}


void ObjectsManager::PushBack(Object * obj)
{
//sanity check:what if i push an object already pushed ?
//#if DEBUGMODE
	hbassert(obj);

	Object *o;
	for(o=activeobjectstail.next;o!=&activeobjectstail;o=o->next)
	{
		if(o==obj)
			break;
	}
	hbassert(o!=obj);
//#endif //DEBUGMODE

	if(obj->GetFlag() & Object::e_FLAG_MASTER)
	{

		for(o=activeobjects.next;o!=&activeobjectstail;o=o->next)
		{
			o->WhenDeactivated();
		}

		activeobjects.next->prev=activeobjects.prev;
		activeobjects.prev->next=activeobjects.next;

		activeobjects.next=&activeobjectstail;
		activeobjects.prev=activeobjectstail.prev;
		activeobjectstail.prev->next=&activeobjects;
		activeobjectstail.prev=&activeobjects;
		//activeobjectstail.next;

	}

	FastInsertBefore(obj,&activeobjectstail);

	obj->WhenPushed();

	hbassert(activeobjects.next->GetFlag() & Object::e_FLAG_MASTER);
}

void ObjectsManager::Update()
{
	Object *obj;
	for(obj=activeobjects.next;obj!=&activeobjectstail;obj=obj->next)
	{
		obj->Update();
	}
}

void ObjectsManager::Draw()
{
	Object *obj;
	for(obj=activeobjectstail.next;obj!=&activeobjectstail;obj=obj->next)
	{
		obj->Draw();
	}
}

Object * ObjectsManager::Remove(Object * obj)
{
	obj->WhenPopped();

	Object * prev=obj->prev;

	obj->next->prev=obj->prev;
	obj->prev->next=obj->next;

	if(obj->GetFlag() & Object::e_FLAG_DELETE_ON_POP)
#ifdef _use_my_mem_tracker_
		deleteo<Object>(obj);
#else //_use_my_mem_tracker_
		delete obj;
#endif //_use_my_mem_tracker_


	return prev;
}


void ObjectsManager::RunDelayedFunctions()
{
	for(unsigned int i=0; i<DelayedPops.NbrOfPopsToRun; ++i)
	{
		Pop(DelayedPops.Args[i],true);
	}
	DelayedPops.NbrOfPopsToRun=0;
}

void ObjectsManager::Pop(Object * obj,bool immediate)
{
	if(!immediate)
	{
		hbassert(DelayedPops.NbrOfPopsToRun<e_NumberOfDelayedPopsToRun);

		DelayedPops.Args[DelayedPops.NbrOfPopsToRun]=obj;
		DelayedPops.NbrOfPopsToRun++;

		return;
	}

	Object *o;

//sanity check:make sure the object is really in the list. otherwise i'll have infinite looping
//#if DEBUGMODE
	hbassert(obj);

	for(o=activeobjectstail.next;o!=&activeobjectstail;o=o->next)
	{
		if(o==obj)
			break;
	}
	hbassert(o==obj);
//#endif //_DEBUG_

	if(obj->GetFlag() & Object::e_FLAG_MASTER)
	{
		if(obj==activeobjects.next)
		{
			for(o=activeobjectstail.prev;o!=&activeobjects;)
			{
				o=Remove(o);
			}

			for(o=activeobjects.prev;o!=&activeobjectstail;o=o->prev)
			{
				if(o->GetFlag() & Object::e_FLAG_MASTER)
				{
					Remove(&activeobjects);
					FastInsertBefore(&activeobjects,o);

					for(o=activeobjects.next;o!=&activeobjectstail;o=o->next)
					{
						o->WhenActivated();
					}

					break;
				}
			}

			if(o==&activeobjectstail)
			{
				hbassert(activeobjects.prev==&activeobjectstail); 
			}
		}
		else
		{
			for(o=obj;;o=o->next)
			{
				if(o->next==&activeobjects || o->next->GetFlag() & Object::e_FLAG_MASTER)
				{
					while(o!=obj)
					{
						o=Remove(o);
					}
					Remove(o);//o==obj
					break;
				}
			}
		}
	}
	else
		Remove(o);
}

Object * ObjectsManager::GetMaster()
{
	return activeobjects.next;
}

Object * ObjectsManager::GetGlobalObject(int classid)
{
	hbassert(classid<CLASSIDS);
	
	return globalobjects[classid];
}

void ObjectsManager::RegisterGlobalObject(Object * obj, int classid)
{
	hbassert(classid<CLASSIDS);
	
	globalobjects[classid]=obj;
}

void ObjectsManager::UnRegisterGlobalObject(Object * obj)
{
	hbassert(obj);

	for(int i=0; i<CLASSIDS; ++i)
		if(globalobjects[i]==obj)
		{
			globalobjects[i]=NULL;
			return;
		}
	
	hbassert(0);
}


