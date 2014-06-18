#ifndef _ANIM_H_
#define _ANIM_H_

#include <vector>
#include <time.h>
#include "../Common.h"
#include "../mem/allocator.h"
#include "../rectangle.h"


//using namespace std;


//the first resting position (default position) is a keyframe
struct stKeyFrame
{
	hb::Points32	offset[4];//the displacement offset for each vertex in the rectangle, counter clockwise.
	clock_t			time;

	stKeyFrame();
	stKeyFrame(hb::Points32 p[], clock_t t);
};

class Anim
{
	std::vector<stKeyFrame,hb::allocator<stKeyFrame> > m_keyFrameList;
	hb::Points32		*m_r;

	clock_t				m_firstKeyFrameTime;
	clock_t				m_lastKeyFrameTime;
	clock_t				m_startTime;

private:

	void Init();
	void Lerp(stKeyFrame & frame1, stKeyFrame & frame2, long );

public:

	Anim(const char * animationfilename, hb::Points32 []);
	~Anim();
	void Update();
	void Reset();

} ;


#endif _ANIM_H_