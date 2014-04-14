
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
Sprite::Sprite(hb::Points32 _r[], const char * texname, const char * animationfilename)
{
	for(int i=0; i<4; ++i)
		m_r[i]=_r[i];
	m_texObj=TexturesManager::GetInstance().GetTextureObj(e_tex_timeout);

	m_anim.reset(new stAnim2(animationfilename));

}

Sprite::Sprite(const Sprite &s)
{
	for(int i=0; i<4; ++i)
		m_r[i]=s.m_r[i];
	m_texObj=s.m_texObj;

	m_anim.swap(const_cast<Sprite &>(s).m_anim);
}

void Sprite::Draw()
{
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, m_texObj);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 

	glBegin(GL_POLYGON);
        glTexCoord2f(0, 0); glVertex2f (m_r[0].x, m_r[0].y);
        glTexCoord2f(1, 0); glVertex2f (m_r[1].x, m_r[1].y);
        glTexCoord2f(1, 1); glVertex2f (m_r[2].x, m_r[2].y);
        glTexCoord2f(0, 1); glVertex2f (m_r[3].x, m_r[3].y);
    glEnd();
	
	
	glDisable(GL_TEXTURE_2D);
}

void Sprite::Update()
{
	if(m_anim)
		m_anim->Update();
}

