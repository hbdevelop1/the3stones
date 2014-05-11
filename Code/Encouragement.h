


#include "object.h"
#include "common.h"
#include <list>
#include "rectangle.h"
#include "mem/allocator.h"

class Sprite;

#define _listofobjects_
//#define _listofpointers_

#ifdef _listofobjects_
#else
	#ifdef _listofpointers_
	#else
		#include <boost/smart_ptr/scoped_ptr.hpp>
	#endif _listofpointers_
#endif _listofobjects_



class Encouragement : public Object
{//derives from Object so it can be pushed to the list of objects and updated and drawn by ObjectsManager

	//boost::scoped_array<Sprite>	m_sprites;
#ifdef _listofobjects_
	std::list<Sprite , hb::allocator<Sprite > >	m_listofsprites;
#else
#ifdef _listofpointers_
	std::list<Sprite *, hb::allocator<Sprite *> >	m_listofsprites;
/*	is more efficient than
	std::list<Sprite , hb::allocator<Sprite > >	m_listofsprites;
	because the earlier there is no copy constructor involved;
	use of list of pointers to avoid the swap of objects which members points to dead objects when copy constructor uses scoped_ptr::swap
	but needs explicit call of list::clear
	better use a smart-ptr holding the list
	*/
#else
	//use boost::scoped_ptr of a std::list to avoid having to write Encouragement destructor. 
	//and use a list of pointers to avoid using the copy constructor.
	boost::scoped_ptr<std::list<Sprite *, hb::allocator<Sprite *> >	> m_listofsprites;
#endif _listofpointers_
#endif _listofobjects_
	//const 

public:
	Encouragement(char * filename);
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