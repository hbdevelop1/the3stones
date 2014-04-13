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
	hb::Points32 offset[4];//the displacement offset for each vertex in the rectangle, counter clockwise.

	stKeyFrame();
	stKeyFrame(hb::Points32 p[]);
};
/*
struct stAnim 
{
	std::vector<stKeyFrame,hb::allocator<stKeyFrame> >  keyframelist;
	const clock_t		durationbetweenframes; //duration between two consecutive frames, interpolated or key.
	clock_t				lastframetime; //this is to decide whether to interpolate the next frame.
	unsigned char		nbrofkeyframes;//nbr of frames in the anim including the first and last resting positions
	unsigned char		currentkeyframe;//needed to know the next key frame to go to
	bool				loop;
	bool				ended;	//if !loop, ended=true when currentkeyframe==nbrofkeyframes-1



	stAnim(const char * animationfilename);
	void Update();

} ;
*/
struct stAnim2
{
	std::vector<stKeyFrame,hb::allocator<stKeyFrame> > keyframelist;
	clock_t				lastframetime; //this is to decide whether to interpolate the next frame.
	unsigned char		nbrofkeyframes;//nbr of frames in the anim including the first and last resting positions
	unsigned char		currentkeyframe;//needed to know the next key frame to go to
	bool				loop;
	bool				ended;	//if !loop, ended=true when currentkeyframe==nbrofkeyframes-1


	stAnim2(const char * animationfilename);
	~stAnim2();
	void Update();
	void SetRectangle(hb::Points32  _r[]);

} ;


#endif _ANIM_H_