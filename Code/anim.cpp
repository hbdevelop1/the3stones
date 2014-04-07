
#include "anim.h"
#include "rectangle.h"

stKeyFrame::stKeyFrame()
{
	offset[0]=hb::Points32(0,0);
	offset[1]=hb::Points32(0,0);
	offset[2]=hb::Points32(0,0);
	offset[3]=hb::Points32(0,0);
}

stAnim::stAnim():durationbetweenframes(200)
{
	stKeyFrame k;

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
