
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

Anim::Anim(const char * animationfilename, hb::Points32 rparent[]):m_r(rparent)
{
	XmlParser xmlParser;
	XmlNodeRef rootNode= xmlParser.parse(animationfilename);
	if (!rootNode) 
	{
		assert(0);
	}

	clock_t lastt=0;
	clock_t timing_step=300;
	for (int i = 0; i < rootNode->getChildCount(); i++)
	{
		XmlNodeRef child = rootNode->getChild(i);
		if (child->isTag("keyframe"))
		{
			hb::Points32 offset[4];
			
			String v = child->getAttribute("value");
			sscanf(v.c_str(),"%d %d %d %d %d %d %d %d"
				,&offset[0].x,&offset[0].y
				,&offset[1].x,&offset[1].y
				,&offset[2].x,&offset[2].y
				,&offset[3].x,&offset[3].y);

			m_keyFrameList.push_back(stKeyFrame(offset,lastt));
			lastt+=timing_step;
		}
	}

	m_firstKeyFrameTime = m_keyFrameList.begin()->time;
	assert(m_firstKeyFrameTime==0);
	m_lastKeyFrameTime = m_keyFrameList.rbegin()->time;
	assert(m_lastKeyFrameTime>0);

	m_startTime=0;
}

Anim::~Anim()
{
}

void Anim::Update()
{
	long newframetime;

	if(m_startTime==0)
	{
		m_startTime=clock();
		newframetime=0;
	}
	else
	{
		long t=clock();
		newframetime=(t-m_startTime)%(m_lastKeyFrameTime-m_firstKeyFrameTime);  //it is modulos not division
	}


	std::vector<stKeyFrame,hb::allocator<stKeyFrame> >::iterator itframe1, itframe2;
	itframe1=itframe2=m_keyFrameList.begin();
	for(; itframe2!=m_keyFrameList.end(); ++itframe2)
	{
		if(newframetime==0)
		{
			char r;
			r=1;
		}
		if(newframetime<itframe2->time)
		{
			break;
		}
		else
		{
			itframe1=itframe2;
		}
	}
	assert(itframe2!=m_keyFrameList.end());
	
	Lerp(*itframe1,*itframe2,newframetime);
}

void Anim::Lerp(stKeyFrame & frame1, stKeyFrame & frame2, long newframetime)
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

void Anim::Reset()
{
	m_startTime=0;
}