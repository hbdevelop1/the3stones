


#include "object.h"
#include "common.h"
#include <l	ist>
#include "rectangle.h"
#include "mem/allocator.h"

#include <boost/smart_ptr/scoped_ptr.hpp>

#include "graphic\Sprite.h"



class Encouragement : public Object
{//derives from Object so it can be pushed to the list of objects and updated and drawn by ObjectsManager

	boost::scoped_ptr<AnimatedSpriteNcrg>	m_sprite;
	bool									m_displayEngouragement;
	clock_t									m_animationStartTime;
	boost::scoped_ptr<hb::Rectangle>		m_rect; //the loaded rect. Sprite expects a pointer to rect

public:
	Encouragement(char * filename);
	~Encouragement();
	void Draw();
	void Update();
	void Reset();
	void Display(int type);
};
