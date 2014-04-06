
#include "object.h"
#include "Common.h"
#include "MemNew.h"

struct DelayedFunctionInfo
{
	struct FunctionInfoBase
	{
		virtual void operator()()=0;
	};

	enum
	{
		e_NumberOfDelayedFunctionsToRun=4,
	};
	int 				nbroffi;
	FunctionInfoBase 	*arrayoffi[e_NumberOfDelayedFunctionsToRun];
	
	DelayedFunctionInfo():nbroffi(0)
	{
	}
	
	template<class O, class FunctionType, class Arg1, class Arg2> 
	struct FunctionInfo2: public FunctionInfoBase
	{
		FunctionType		 	mf;
		O						*mo;
		Arg1					marg1;
		Arg2					marg2;
		FunctionInfo2(O *o, FunctionType f, Arg1 arg1, Arg2 arg2):mo(o),mf(f),marg1(arg1),marg2(arg2)
		{
		}
		void operator()()
		{
			(mo->*mf)(marg1,marg2);
		}
	}; //can register any function with two arguments

	template<class O, class FunctionType, class Arg1, class Arg2> 
	void RegisterFunction(O *o, FunctionType f, Arg1 arg1, Arg2 arg2)
	{
		arrayoffi[nbroffi++]=new FunctionInfo2<O,FunctionType,Arg1,Arg2>(o,f,arg1,arg2);
		hbassert(nbroffi<=e_NumberOfDelayedFunctionsToRun);
	}

	void execute()
	{
		for(int i=0; i<nbroffi;i++)
		{
			(*arrayoffi[i])();
			delete arrayoffi[i];
		}
		nbroffi=0;
	}
};


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

	DelayedFunctionInfo	dfi;
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

	void PushBack(int classid, bool immediate);
	void PushBack(Object *, bool immediate);

	void FastInsertBefore(Object * newobj, Object * before);
	Object * Remove(Object * obj);
	void Pop(Object * obj,bool immediate);

	void reset();
	void Update();
	void Draw();
	void Clear();

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


