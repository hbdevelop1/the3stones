
#include "Intro.h"
#include "objectsmanager.h"
#include "classids.h"
#include "ObjectsRectangles.h"
#include "graphic/TexturesManager.h"
#include "common.h"




ImplementCreator(Intro)

const char *Introtextmsgs[]=
{
	"Rules of the game :",

	"Click on one tile, then click on a neigbooring one to swap",
	"their positions.",
	"If three tiles of the same color are lined up, vertically",
	"or horizontally, you win 100 points.",
};

#if _anim_==1
Intro::Intro():rplay(ObjectsRectangles[e_rect_Intro_startbutton])
#else
Intro::Intro()://r(ObjectsRectangles[e_rect_Intro]),
	Sprite(& ObjectsRectangles2[e_rect_Intro], e_tex_Intro)
	//,rplay(ObjectsRectangles[e_rect_Intro_startbutton])
	,rplay(& ObjectsRectangles2[e_rect_Intro_startbutton])
#endif
{
	SetFlag(e_FLAG_MASTER);


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
#if _anim_==1
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
#endif //_anim_==1
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

	Sprite::Draw();

	glColor3f (0.0, 0.0, 1.0);


	
	unsigned int line,column_left; 
#if _anim_==1
	const hb::Rectangle & r0=ObjectsRectangles[e_rect_Intro];
	line=r0.t-30;
	column_left=r0.l+25;
#else 
	line=m_rect->lt.y-30;
	column_left=m_rect->lt.x+25;
#endif _anim_==1

	int i=e_msg_rules;
	hb::DrawText(Introtextmsgs[i++],column_left, line);
	
	line-=30;
	hb::DrawText(Introtextmsgs[i++],column_left, line);
	line-=20;
	hb::DrawText(Introtextmsgs[i++],column_left, line);
		
	line-=30;
	hb::DrawText(Introtextmsgs[i++],column_left, line);
	line-=20;
	hb::DrawText(Introtextmsgs[i++],column_left, line);



	//button

    glColor3f (1.0, 1.0, 0.2);

    glBegin(GL_POLYGON);
        glVertex2f (rplay->lb.x, rplay->lb.y);
        glVertex2f (rplay->rb.x, rplay->lb.y);
        glVertex2f (rplay->rb.x, rplay->rt.y);
        glVertex2f (rplay->lt.x, rplay->rt.y);
    glEnd();

	glColor3f (0.0, 0.0, 1.0);
	hb::DrawText("Start",rplay->lb.x+10, rplay->lb.y+(rplay->lt.y-rplay->lb.y)/2);



}

void Intro::OnClick(int x,int y)
{
	if(rplay->lb.x<=x && x<=rplay->rb.x && rplay->rb.y<=y && y<=rplay->rt.y)
	{
		ObjectsManager::GetInstance().Pop(this,false);
	}
}