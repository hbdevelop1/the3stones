
#include "anim.h"
#include "../rectangle.h"
#include "../ObjectsRectangles.h"
#include "../xml/xml.h"
#include "../mem/MemNew.h"
#include <stdio.h>

stKeyFrame::stKeyFrame()
{
	offset[0]=hb::Points32(0,0);
	offset[1]=hb::Points32(0,0);
	offset[2]=hb::Points32(0,0);
	offset[3]=hb::Points32(0,0);
}

stKeyFrame::stKeyFrame(hb::Points32 p[])
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
stAnim2::stAnim2(const char * animationfilename)
{
	XmlParser xmlParser;
	XmlNodeRef rootNode= xmlParser.parse(animationfilename);
	if (!rootNode) 
	{
		assert(0);
	}

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

			keyframelist.push_back(stKeyFrame(offset));
		}
	}
}

stAnim2::~stAnim2()
{
}
void stAnim2::Update()
{
}

void stAnim2::SetRectangle(hb::Points32  _r[])
{
}

