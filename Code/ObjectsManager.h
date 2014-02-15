
#include "object.h"

class ObjectsManager
{
	struct Delimitor : public Object
	{
		void Draw(){}
		void Update(){}
	};

	Delimitor activeobjects;
	Delimitor activeobjectstail;

private:
	enum
	{
		e_NumberOfDelayedPopsToRun=5,
	};
	struct
	{
		unsigned int NbrOfPopsToRun;
		Object	*Args[e_NumberOfDelayedPopsToRun];
	} DelayedPops;

private:
	ObjectsManager();
	ObjectsManager(const ObjectsManager &);
	ObjectsManager & operator=(const ObjectsManager&);

public:

	~ObjectsManager();
	static ObjectsManager & GetInstance() 
	{
		static ObjectsManager instance;
		return instance;
	}

	void PushBack(int classid);
	void PushBack(Object *);

	void FastInsertBefore(Object * newobj, Object * before);
	Object * Remove(Object * obj);
	void Pop(Object * obj,bool immediate=true);

	void reset();
	void Update();
	void Draw();

	Object * GetMaster();

	Object * GetGlobalObject(int classid);
	void RegisterGlobalObject(Object * obj, int classid);
	void UnRegisterGlobalObject(Object * obj);

	void RunDelayedFunctions();

};




#define ImplementCreator(classname)	\
Object * classname##_Creator()		\
{									\
	return new classname;			\
}

#define DeclareCreator(classname)	\
Object * classname##_Creator();


DeclareCreator(Score);
DeclareCreator(CountDown);
DeclareCreator(game);
DeclareCreator(TimeOut);
DeclareCreator(Intro);


