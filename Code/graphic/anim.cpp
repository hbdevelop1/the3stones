
#include "anim.h"
#include "../rectangle.h"
#include "../ObjectsRectangles.h"
#include "../xml/xml.h"
#include "../mem/MemNew.h"
#include <stdio.h>

#pragma warning (disable:4996)

stKeyFrame::stKeyFrame()
{
	offset[0]=hb::Points32(0,0);
	offset[1]=hb::Points32(0,0);
	offset[2]=hb::Points32(0,0);
	offset[3]=hb::Points32(0,0);
}

stKeyFrame::stKeyFrame(hb::Points32 p[], clock_t t):time(t)
{
	for(int i=0; i<4; ++i)
		offset[i]=p[i];
}
/*
stAnim::stAnim():durationbetweenframes(200)
{
	stKeyFrame k;
	
	//load animation

	k.offset[2]=hb::Points32(0,0);
	keyframelist.push_back(k);
	k.offset[2]=hb::Points32(5,5);
	keyframelist.push_back(k);
	k.offset[2]=hb::Points32(15,15);
	keyframelist.push_back(k);
	k.offset[2]=hb::Points32(9,5);
	keyframelist.push_back(k);
	k.offset[2]=hb::Points32(0,0);
	keyframelist.push_back(k);

	nbrofkeyframes=keyframelist.size();
	assert(nbrofkeyframes>1); //otherwise an issue at "if(!anim.loop && ++anim.currentKeyFrame==anim.nbrofkeyframes-1)"
	lastframetime=clock();
	currentkeyframe=0;
	loop = true;
	ended=false;

}

void stAnim::Update()
{
	
	const hb::Rectangle & r0=ObjectsRectangles[e_rect_Intro];
	
	hb::Points32 * offset=anim.keyframelist[anim.currentkeyframe].offset;

	r[0]=hb::Points32(r0.l + offset[0].x, r0.b + offset[0].y);
	r[1]=hb::Points32(r0.r + offset[1].x, r0.b + offset[1].y);
	r[2]=hb::Points32(r0.r + offset[2].x, r0.t + offset[2].y);
	r[3]=hb::Points32(r0.l + offset[3].x, r0.t + offset[3].y);
	
	if(anim.ended == false)
	{
		 if(clock()-anim.lastframetime>=anim.durationbetweenframes)
		 {
			anim.lastframetime=clock();
			anim.currentkeyframe++;// 1, 2, 3,4, ...
			if(!anim.loop)
			{
				if(anim.currentkeyframe==anim.nbrofkeyframes-1)
					anim.ended=true;
			}
			else
			{
				if(anim.currentkeyframe>anim.nbrofkeyframes-1)
					anim.currentkeyframe=0;
			}
		 }
	}
	
}
*/
stAnim2::stAnim2(const char * animationfilename, hb::Points32 rparent[]):m_r(rparent)//,animFrameRate(100)
{
	XmlParser xmlParser;
	XmlNodeRef rootNode= xmlParser.parse(animationfilename);
	if (!rootNode) 
	{
		assert(0);
	}

#define _keyframetimeSetInCode_
//_keyframetimeSetInCode_ is to set key frame timing in the code, instead of reading a regular timing from the anim file.
//advantage:quickly test many timing steps

	clock_t lastt=0;
	clock_t t;
	clock_t timing_step=300;
	for (int i = 0; i < rootNode->getChildCount(); i++)
	{
		XmlNodeRef child = rootNode->getChild(i);
		if (child->isTag("keyframe"))
		{
			hb::Points32 offset[4];
			
			String v = child->getAttribute("value");
			sscanf(v.c_str(),"%d %d %d %d %d %d %d %d %d"
				,&offset[0].x,&offset[0].y
				,&offset[1].x,&offset[1].y
				,&offset[2].x,&offset[2].y
				,&offset[3].x,&offset[3].y
				,&t);

#ifdef _keyframetimeSetInCode_
			keyframelist.push_back(stKeyFrame(offset,lastt));
			lastt+=timing_step;
#else
			keyframelist.push_back(stKeyFrame(offset,t));
#endif
		}
	}

	firstkeyframetime = keyframelist.begin()->time;
	assert(firstkeyframetime==0);
	lastkeyframetime = keyframelist.rbegin()->time;
	assert(lastkeyframetime>0);

	starttime=0;
}

stAnim2::~stAnim2()
{
}

void stAnim2::operator=(stAnim2* p)
{
	hb::Points32 *	t;

	t=p->m_r;
	p->m_r=this->m_r;
	this->m_r=t;
}

void stAnim2::Update()
{
	long newframetime;

	if(starttime==0)
	{
		starttime=clock();
		newframetime=0;
	}
	else
	{
		long t=clock();
		newframetime=(t-starttime)%(lastkeyframetime-firstkeyframetime);  //it is modulos not division
	}


	//if(t-starttime > animFrameRate)
	{

		//go through the list of keyframes to find the two keyframes that encompass the newframetime.
	
	
		/*
		1-best solution :the search can be improved. binary search tree maybe
		if(newframetime<next key frame time)
		{
		}
	
		2-second better solution : use find(begin, end, functor())
		*/

		std::vector<stKeyFrame,hb::allocator<stKeyFrame> >::iterator itframe1, itframe2;
		itframe1=itframe2=keyframelist.begin();
		for(; itframe2!=keyframelist.end(); ++itframe2)
		{
			if(newframetime<itframe2->time)
			{
				break;
			}
			else
			{
				itframe1=itframe2;
			}
		}
		assert(itframe2!=keyframelist.end());
	
		Lerp(*itframe1,*itframe2,newframetime);
	}
}

void stAnim2::Lerp(stKeyFrame & frame1, stKeyFrame & frame2, long newframetime)
{
	float t=((float)newframetime-frame1.time)/(frame2.time-frame1.time);

	m_r[0].x=(1-t)*frame1.offset[0].x + t * frame2.offset[0].x;
	m_r[0].y=(1-t)*frame1.offset[0].y + t * frame2.offset[0].y;
	m_r[1].x=(1-t)*frame1.offset[1].x + t * frame2.offset[1].x;
	m_r[1].y=(1-t)*frame1.offset[1].y + t * frame2.offset[1].y;
	m_r[2].x=(1-t)*frame1.offset[2].x + t * frame2.offset[2].x;
	m_r[2].y=(1-t)*frame1.offset[2].y + t * frame2.offset[2].y;
	m_r[3].x=(1-t)*frame1.offset[3].x + t * frame2.offset[3].x;
	m_r[3].y=(1-t)*frame1.offset[3].y + t * frame2.offset[3].y;
	
	
}

void stAnim2::Reset()
{
	starttime=0;
}