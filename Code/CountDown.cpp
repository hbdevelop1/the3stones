#include "common.h"
#include "countdown.h"
#include "objectsmanager.h"
#include "classids.h"
#include "objectsrectangles.h"
#include "graphic/TexturesManager.h"



#include "Mem/MemNew.h"

ImplementCreator(CountDown)

CountDown::CountDown():r(ObjectsRectangles[e_rect_countdown]),
						rf(r.l+25, r.b+25, r.l+25+25, r.b+25+25)
{

	SetFlag(e_FLAG_MASTER);

#ifdef DEBUGMODE
#ifdef TESTING
//for tests only
	UnSetFlag(e_FLAG_MASTER);
	ObjectsManager::GetInstance().RegisterGlobalObject(this, CLASSID_CountDown);
#else
	assert(ObjectsManager::GetInstance().GetGlobalObject(CLASSID_CountDown)==0);
	assert(GetFlag() & e_FLAG_MASTER);

#endif //TESTING


#endif //DEBUGMODE

	m_texObj=TexturesManager::GetInstance().GetTextureObj(e_tex_countdown);

	counter=3001;
	color_index=2;

	t0=0;
	currentframe=-1;
	currentfigure=3;
}

CountDown::~CountDown()
{

#if DEBUGMODE & TESTING

	ObjectsManager::GetInstance().UnRegisterGlobalObject(this);

#endif //DEBUGMODE TESTING
}

void CountDown::Update()
{
	/*
	--counter;

	if(counter>2000)
	{
		color_index=2;
	}
	else if(counter>1000)
	{
		color_index=1;
	}
	else
	{
		color_index=0;
	}

	if(counter<=0)
	{
		ObjectsManager::GetInstance().Pop(this,false);
	}
	*/
	DWORD t=timeGetTime();
	
	if(t0==0)
	{
		t0=timeGetTime();
	}
	else
	{
		t=t-t0;
		if(t>e_timeperframe)
		{
			t0=timeGetTime();

			currentframe++;
			if(currentframe>=e_nbrframes)
			{
				if(currentfigure>1)
				{
					currentfigure--;
					currentframe=0;
				}
				else
				{
					currentframe--; //to avoid drawing e_nbrframes frame
					ObjectsManager::GetInstance().Pop(this,false);
				}
			}
		}
	}

}


void CountDown::Draw()
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



	if(currentframe<0)
		return;




	int fx = (currentframe % e_nbrframes) * e_tilewidth;
	int fy =e_tileheight*(currentfigure-1);

	GLfloat rtxl=((GLfloat)fx)/e_imagewidth;
	GLfloat rtxb=((GLfloat)fy)/e_imageheight;
	GLfloat rtxr=((GLfloat)fx+e_tilewidth)/e_imagewidth;
	GLfloat rtxt=((GLfloat)fy+e_tileheight)/e_imageheight;




	glEnable(GL_TEXTURE_2D);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER,0);

	glBindTexture(GL_TEXTURE_2D, m_texObj);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 

	glBegin(GL_POLYGON);
        glTexCoord2f(rtxl, rtxb); glVertex2f (r.l, r.b);
        glTexCoord2f(rtxr, rtxb); glVertex2f (r.r, r.b);
        glTexCoord2f(rtxr, rtxt); glVertex2f (r.r, r.t);
        glTexCoord2f(rtxl, rtxt); glVertex2f (r.l, r.t);
    glEnd();
	
	glDisable(GL_ALPHA_TEST);
	
	glDisable(GL_TEXTURE_2D);
    
}


void CountDown::Animate()
{
	//currentframe : 0,1,2
	//currentfigure:3,2,1
	/*
	int fx = (currentframe % e_nbrcolumns) * e_tilewidth;
	int fy =e_tileheight*(currentfigure-1);


	l=((GLfloat)fx)/e_imagewidth;
	b=((GLfloat)fy)/e_imageheight;
	r=((GLfloat)fx+e_tilewidth)/e_imagewidth;
	t=((GLfloat)fy+e_tileheight)/e_imageheight;
	*/
}


/*
void CountDown::Draw()
{
    glColor3f (0.0, 0.0, 1.0);

    glBegin(GL_POLYGON);
        glVertex2f (r.l, r.b);
        glVertex2f (r.r, r.b);
        glVertex2f (r.r, r.t);
        glVertex2f (r.l, r.t);
    glEnd();

    glColor3f (figures[color_index].r, figures[color_index].g, figures[color_index].b);

    glBegin(GL_POLYGON);
        glVertex2f (rf.l, rf.b);
        glVertex2f (rf.r, rf.b);
        glVertex2f (rf.r, rf.t);
        glVertex2f (rf.l, rf.t);
    glEnd();

}
*/
