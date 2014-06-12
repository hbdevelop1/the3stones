
#include "Sprite.h"
#include "TexturesManager.h"
#include "../xml/xml.h"
#include "anim.h"
#include "../mem/MemNew.h"
#include <string>
using namespace std;



/*
Sprite::Sprite(stAnim2 * _a, hb::Points32  _r[]):m_anim(_a)
{
	for(int i=0; i<4; ++i)
		m_r[i]=_r[i];

	m_anim->SetRectangle(m_r);

	//m_texObj=TexturesManager::GetInstance().GetTextureObj(e_tex_timeout);
	;
}
*/
//Sprite::Sprite(hb::Points32 _r[], const char * texname, const char * animationfilename)
Sprite::Sprite(hb::Points32 _r[], const char * animationfilename, const int itex)
{
	for(int i=0; i<4; ++i)
		m_r[i]=_r[i];

	for(int i=0; i<4; ++i)
		m_offset[i]=hb::Points32(0,0);

	m_texObj=TexturesManager::GetInstance().GetTextureObj(itex);

	m_anim.reset(new stAnim2(animationfilename, m_offset));

}

Sprite::Sprite(const Sprite &s)
{
	for(int i=0; i<4; ++i)
		m_r[i]=s.m_r[i];

	for(int i=0; i<4; ++i)
		m_offset[i]=s.m_offset[i];

	m_texObj=s.m_texObj;

	m_anim.swap(const_cast<Sprite &>(s).m_anim); //mutable
}

Sprite::~Sprite()
{
}

void Sprite::Draw()
{
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, m_texObj);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 

	glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex2f (m_r[0].x+m_offset[0].x, m_r[0].y+m_offset[0].y);
        glTexCoord2f(1, 0); glVertex2f (m_r[1].x+m_offset[1].x, m_r[1].y+m_offset[1].y);
        glTexCoord2f(1, 1); glVertex2f (m_r[2].x+m_offset[2].x, m_r[2].y+m_offset[2].y);
        glTexCoord2f(0, 1); glVertex2f (m_r[3].x+m_offset[3].x, m_r[3].y+m_offset[3].y);
    glEnd();
	
	
	glDisable(GL_TEXTURE_2D);
}

void Sprite::Update()
{
	if(m_anim)
		m_anim->Update();
}

void Sprite::Reset()
{
	if(m_anim)
		m_anim->Reset();
}


///////////////////////////////

Sprite2::Sprite2(hb::Points32 _r[], const char * animationfilename, const int itex, const int itex2):
	Sprite(_r, animationfilename,itex),
	m_image(e_ncrg_good)
{
	m_texObj2=TexturesManager::GetInstance().GetTextureObj(itex2);
}

Sprite2::Sprite2(const Sprite2 &s)
{
	assert(0);
}

void Sprite2::Draw()
{
	glEnable(GL_TEXTURE_2D);

	if(m_image==e_ncrg_wow)
		glBindTexture(GL_TEXTURE_2D, m_texObj2);
	else
		glBindTexture(GL_TEXTURE_2D, m_texObj);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 

	glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex2f (m_r[0].x+m_offset[0].x, m_r[0].y+m_offset[0].y);
        glTexCoord2f(1, 0); glVertex2f (m_r[1].x+m_offset[1].x, m_r[1].y+m_offset[1].y);
        glTexCoord2f(1, 1); glVertex2f (m_r[2].x+m_offset[2].x, m_r[2].y+m_offset[2].y);
        glTexCoord2f(0, 1); glVertex2f (m_r[3].x+m_offset[3].x, m_r[3].y+m_offset[3].y);
    glEnd();
	
	
	glDisable(GL_TEXTURE_2D);
}

void Sprite2::SetImage(int type)
{
	assert(type==e_ncrg_wow || type == e_ncrg_good);

	m_image=type;
}

//////////////////////////////

#include "..\ObjectsRectangles.h"

Sprite3::Sprite3(const hb::stRectangle2 *rect, int itex):
	m_rect(*rect),
	m_texObj(TexturesManager::GetInstance().GetTextureObj(itex))
{
	
}
/*
Sprite3::Sprite3(const Sprite3 &s):m_rect(s.m_rect),m_texObj(s.m_texObj)
{
}
*/
Sprite3::~Sprite3()
{
}

void Sprite3::Draw()
{
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, m_texObj);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 

	glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex2f (m_rect.lb.x, m_rect.lb.y);
        glTexCoord2f(1, 0); glVertex2f (m_rect.rb.x, m_rect.rb.y);
        glTexCoord2f(1, 1); glVertex2f (m_rect.rt.x, m_rect.rt.y);
        glTexCoord2f(0, 1); glVertex2f (m_rect.lt.x, m_rect.lt.y);
    glEnd();
	
	
	glDisable(GL_TEXTURE_2D);
}
//////////////////

AnimatedSprite3::AnimatedSprite3(const hb::stRectangle2 *rect, int itex, const char * animationfilename)
	:Sprite3(rect, itex)
{

	for(int i=0; i<4; ++i)
		m_offset[i]=hb::Points32(0,0);

	m_anim.reset(new stAnim2(animationfilename, m_offset));
}

void AnimatedSprite3::Update()
{
	m_anim->Update();
}

void AnimatedSprite3::Draw()
{
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, m_texObj);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 

	glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex2f (m_rect.lb.x+m_offset[0].x, m_rect.lb.y+m_offset[0].y);
        glTexCoord2f(1, 0); glVertex2f (m_rect.rb.x+m_offset[1].x, m_rect.rb.y+m_offset[1].y);
        glTexCoord2f(1, 1); glVertex2f (m_rect.rt.x+m_offset[2].x, m_rect.rt.y+m_offset[2].y);
        glTexCoord2f(0, 1); glVertex2f (m_rect.lt.x+m_offset[3].x, m_rect.lt.y+m_offset[3].y);
    glEnd();
	
	
	glDisable(GL_TEXTURE_2D);
}
///////////////////////////
AnimatedSpriteNcrg::AnimatedSpriteNcrg(const hb::stRectangle2 *rect, int itex1,int itex2, const char * animationfilename)
	:AnimatedSprite3(rect, itex1,animationfilename)
	,m_image( e_ncrg_good)
	,m_texObj1(m_texObj)
	,m_texObj2(TexturesManager::GetInstance().GetTextureObj(itex2))
{
}

void AnimatedSpriteNcrg::SetImage(int type)
{
	assert(type==e_ncrg_wow || type ==  e_ncrg_good);

	m_image=type;
}

void AnimatedSpriteNcrg::Draw()
{
	if(m_image==e_ncrg_wow)
		m_texObj = m_texObj2;
	else
		m_texObj = m_texObj1;


	AnimatedSprite3::Draw();
}
