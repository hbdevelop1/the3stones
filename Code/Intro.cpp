
#include "Intro.h"
#include "objectsmanager.h"
#include "classids.h"
#include "objectsrectangles.h"
#include "TexturesManager.h"
#include "common.h"

#include "MemNew.h"


ImplementCreator(Intro)

const char *Introtextmsgs[]=
{
	"Rules of the game :",
	"Arrange three tiles of the same color",
	"to win 100 points.",
};

#if _anim_==1

//the first resting position (default position) is a keyframe
struct stKeyFrame
{
	hb::Points32 offset[4];//the displacement offset for each vertex in the rectangle, counter clockwise.
	stKeyFrame()
	{
		offset[0]=hb::Points32(0,0);
		offset[1]=hb::Points32(0,0);
		offset[2]=hb::Points32(0,0);
		offset[3]=hb::Points32(0,0);
	}
};
struct stAnim
{
	vector<stKeyFrame> keyframelist;
	const clock_t		durationbetweenframes; //duration between two consecutive frames, interpolated or key.
	clock_t			lastframetime; //this is to decide whether to interpolate the next frame.
	unsigned char	nbrofkeyframes;//nbr of frames in the anim including the first and last resting positions
	unsigned char	currentkeyframe;//needed to know the next key frame to go to
	bool			loop;
	bool			ended;	//if !loop, ended=true when currentkeyframe==nbrofkeyframes-1



	stAnim():durationbetweenframes(200)
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
} anim;
#endif _anim_==1

#if _anim_==1
Intro::Intro():rplay(ObjectsRectangles[e_rect_Intro_start])
#else
Intro::Intro():r(ObjectsRectangles[e_rect_Intro]),
					rplay(ObjectsRectangles[e_rect_Intro_start])
#endif
{
	SetFlag(e_FLAG_MASTER);

	m_texObj=TexturesManager::GetInstance().GetTextureObj(e_tex_Intro);

#if _anim_==1
	const hb::Rectangle & r0=ObjectsRectangles[e_rect_Intro];

	r[0]=hb::Points32(r0.l,r0.b);
	r[1]=hb::Points32(r0.r,r0.b);
	r[2]=hb::Points32(r0.r,r0.t);
	r[3]=hb::Points32(r0.l,r0.t);
#endif _anim_==1
}

Intro::~Intro()
{
}


void Intro::Update()
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

void Intro::Draw()
{
	const hb::Rectangle & rDim(ObjectsRectangles[e_rect_board]);
	
	glEnable(GL_BLEND); 
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	
	glColor4f (0.0, 0.0, 0.0,.25);

	glBegin(GL_POLYGON);
        glVertex2f (rDim.l, rDim.b);
        glVertex2f (rDim.r, rDim.b);
        glVertex2f (rDim.r, rDim.t);
        glVertex2f (rDim.l, rDim.t);
    glEnd();

	glDisable(GL_BLEND); 


	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, m_texObj);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 

	glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex2f (r[0].x, r[0].y);
        glTexCoord2f(1, 0); glVertex2f (r[1].x, r[1].y);
        glTexCoord2f(1, 1); glVertex2f (r[2].x, r[2].y);
        glTexCoord2f(0, 1); glVertex2f (r[3].x, r[3].y);
    glEnd();
	
	
	glDisable(GL_TEXTURE_2D);

	glColor3f (0.0, 0.0, 1.0);


	
	unsigned int line,column_left; 
#if _anim_==1
	const hb::Rectangle & r0=ObjectsRectangles[e_rect_Intro];
	line=r0.t-30;
	column_left=r0.l+25;
#else 
	line=r.t-30;
	column_left=r.l+25;
#endif _anim_==1
	hb::DrawText(Introtextmsgs[e_msg_rules],column_left, line);

	line-=30;
	hb::DrawText(Introtextmsgs[e_msg_arrange],column_left, line);
		
	line-=30;
	hb::DrawText(Introtextmsgs[e_msg_win],column_left, line);



	//button

    glColor3f (1.0, 1.0, 0.2);

    glBegin(GL_POLYGON);
        glVertex2f (rplay.l, rplay.b);
        glVertex2f (rplay.r, rplay.b);
        glVertex2f (rplay.r, rplay.t);
        glVertex2f (rplay.l, rplay.t);
    glEnd();

	glColor3f (0.0, 0.0, 1.0);
	hb::DrawText("Start",rplay.l+10, rplay.b+(rplay.t-rplay.b)/2);



}

void Intro::OnClick(uint32 x,uint32 y)
{
	if(rplay.l<=x && x<=rplay.r && rplay.b<=y && y<=rplay.t)
	{
		ObjectsManager::GetInstance().Pop(this,false);
	}

}