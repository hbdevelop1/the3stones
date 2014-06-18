
#ifndef _OBJECT_
#define _OBJECT_

#include <boost/noncopyable.hpp>

class ObjectsManager;

class Object  : private boost::noncopyable
{
#if DEBUGMODE & TESTING
	public:
		char name;
#endif //DEBUGMODE & TESTING
public:

	enum FLAGS
	{
		e_FLAG_NOTHING			=0x000,
		e_FLAG_MASTER			=0x001,
		e_FLAG_DELETE_ON_POP	=0x010,
		e_FLAG_END
	};

private:
	FLAGS flag;
	Object * prev;
	Object * next;

public:
	Object();
	virtual ~Object();

	void SetFlag(FLAGS f);
	void UnSetFlag(FLAGS f);
	FLAGS GetFlag();

	virtual void Draw()=0;
	virtual void Update()=0;
	virtual void OnClick(unsigned int, unsigned int){}
/*	virtual void WhenPushed(){}
	virtual void WhenPopped(){}
	virtual void WhenDeactivated(){}
	virtual void WhenActivated(){}
	*/


	friend class ObjectsManager;
	friend void operator|=(Object::FLAGS & f,Object::FLAGS l);
};

#endif //_OBJECT_
