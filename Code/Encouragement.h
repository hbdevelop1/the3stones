


#include "object.h"
#include "common.h"
#include <list>
#include "rectangle.h"
#include "mem/allocator.h"

#include <boost/smart_ptr/scoped_ptr.hpp>

#include "graphic\Sprite.h"



class Encouragement : public Object
{//derives from Object so it can be pushed to the list of objects and updated and drawn by ObjectsManager

	boost::scoped_ptr<Sprite>	m_sprite;

public:
	Encouragement(char * filename, int itex);
	~Encouragement();
	void Draw();
	void Update();
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