


#include "object.h"
#include "common.h"
#include "smartptrs/scoped_array.hpp"


class Graphic
{

public:
	void Draw();
	void Update();
};

class Encouragement : public Object
{//derives from Object so it can be pushed to the list of objects and updated and drawn by ObjectsManager

	boost::scoped_array<Graphic>	m_elements;
	const unsigned int				m_nbrofelements;

public:
	Encouragement(unsigned int n);
	void Draw();
	void Update();
};

class Good : public Encouragement
{

public:
	Good():Encouragement(5) //Good !
	{
	}
};

class Wow : public Encouragement
{

public:
	Wow():Encouragement(4)  //Wow !
	{
	}
};