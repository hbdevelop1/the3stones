


#include "object.h"
#include "common.h"
#include <list>
#include "rectangle.h"
#include "mem/allocator.h"

class Sprite;

class Encouragement : public Object
{//derives from Object so it can be pushed to the list of objects and updated and drawn by ObjectsManager

	//boost::scoped_array<Sprite>	m_sprites;
	std::list<Sprite, hb::allocator<Sprite> >	m_listofsprites;
	//const 
		unsigned int			m_nbrofsprites;

public:
	Encouragement(char * filename);
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