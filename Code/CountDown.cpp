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

	m_texObj=TexturesManager::GetInstance().GetTextureObj(e_tex_countdown);

	counter=3001;
	color_index=2;

	t0=0;
	currentframe=-1;
	currentfigure=3;
}

CountDown::~CountDown()
{
}

void CountDown::Update()
{
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

