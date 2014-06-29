
#include "Sprite.h"
#include "TexturesManager.h"
#include "../xml/xml.h"
#include "anim.h"
#include "../mem/MemNew.h"
#include <string>
using namespace std;

#include "..\ObjectsRectangles.h"

Sprite::Sprite(const hb::Rectangle *rect, int itex):
	m_rect(rect),
	m_texObj(TexturesManager::GetInstance().GetTextureObj(itex))
{
	
}
/*
Sprite::Sprite(const Sprite &s):m_rect(s.m_rect),m_texObj(s.m_texObj)
{
}
*/
Sprite::~Sprite()
{
}

void Sprite::Draw()
{
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, m_texObj);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 

	glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex2i (m_rect->l, m_rect->b);
        glTexCoord2f(1, 0); glVertex2i (m_rect->r, m_rect->b);
        glTexCoord2f(1, 1); glVertex2i (m_rect->r, m_rect->t);
        glTexCoord2f(0, 1); glVertex2i (m_rect->l, m_rect->t);
    glEnd();
	
	
	glDisable(GL_TEXTURE_2D);
}
//////////////////

AnimatedSprite::AnimatedSprite(const hb::Rectangle *rect, int itex, const char * animationfilename)
	:Sprite(rect, itex)
{

	for(int i=0; i<4; ++i)
		m_offset[i]=hb::Points32(0,0);

	m_anim.reset(new Anim(animationfilename, m_offset));
}

void AnimatedSprite::Update()
{
	m_anim->Update();
}

void AnimatedSprite::Draw()
{
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, m_texObj);

	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 

	const hb::sRectangle *rect = reinterpret_cast<const hb::sRectangle *>(m_rect);

	glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex2i (rect->l+m_offset[0].x, rect->b+m_offset[0].y);
        glTexCoord2f(1, 0); glVertex2i (rect->r+m_offset[1].x, rect->b+m_offset[1].y);
        glTexCoord2f(1, 1); glVertex2i (rect->r+m_offset[2].x, rect->t+m_offset[2].y);
        glTexCoord2f(0, 1); glVertex2i (rect->l+m_offset[3].x, rect->t+m_offset[3].y);
    glEnd();	


	glDisable(GL_TEXTURE_2D);
}
///////////////////////////
AnimatedSpriteNcrg::AnimatedSpriteNcrg(const hb::Rectangle *rect, int itex1,int itex2, const char * animationfilename)
	:AnimatedSprite(rect, itex1,animationfilename)
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


	AnimatedSprite::Draw();
}
