


#include "object.h"
#include "common.h"
#include <list>
#include "rectangle.h"
#include "mem/allocator.h"

#include <boost/smart_ptr/scoped_ptr.hpp>

#include "graphic\Sprite.h"



class Encouragement : public Object
{//derives from Object so it can be pushed to the list of objects and updated and drawn by ObjectsManager

	boost::scoped_ptr<Sprite2>	m_sprite;
	bool						m_displayEngouragement;
	clock_t						starttime4animation;

public:
	Encouragement(char * filename);
	~Encouragement();
	void Draw();
	void Update();
	void Reset();
	void Display(int type);
};
//
//class Good : public Encouragement
//{
//
//public:
//	Good():Encouragement(5) //Good !
//	{
//	}
//};
//
//class Wow : public Encouragement
//{
//
//public:
//	Wow():Encouragement(4)  //Wow !
//	{
//	}
//};