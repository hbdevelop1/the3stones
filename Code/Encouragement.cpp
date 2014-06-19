
#include "Encouragement.h"
#include "graphic/TexturesManager.h"
#include "xml/xml.h"
#include <string>
using namespace std;
#include "mem/MemNew.h"
#include "Score.h"
#include "ObjectsManager.h"
#include "classids.h"
#include "ObjectsRectangles.h"

#pragma warning (disable:4996)


Encouragement::~Encouragement()
{
	ObjectsManager::GetInstance().UnRegisterGlobalObject(this);

}
Encouragement::Encouragement(char * filename):m_displayEngouragement(false)
{
	ObjectsManager::GetInstance().RegisterGlobalObject(this,CLASSID_Encouragement);

	XmlParser xmlParser;
	XmlNodeRef rootNode= xmlParser.parse(filename);

	assert(rootNode);

	for (int i = 0; i < rootNode->getChildCount(); i++)
	{
		XmlNodeRef child = rootNode->getChild(i);

		if (child->isTag("animatedsprite"))
		{
			hb::Rectangle rect;

			String pointstring = child->getAttribute("points");

			sscanf(pointstring.c_str(),"%d %d %d %d %d %d %d %d"
				,&rect.l,&rect.b
				,&rect.r,&rect.b
				,&rect.r,&rect.t
				,&rect.l,&rect.t);

			//String texturename = child->getAttribute("texture");
			String animationfile = child->getAttribute("animation");

			m_rect.reset(new hb::Rectangle(rect));

			assert(m_sprite.get()==NULL);  //no more than one object.

			m_sprite.reset(new AnimatedSpriteNcrg(m_rect.get(),e_tex_encrg_good,e_tex_encrg_wow, animationfile.c_str()));
		}
	}
}

void Encouragement::Reset()
{
	m_displayEngouragement=false;
}

void Encouragement::Draw()
{
	if(!m_displayEngouragement)
		return;

	m_sprite->Draw();

	if(clock()-m_animationStartTime>1500)
		m_displayEngouragement=false;
}

void Encouragement::Update()
{
	if(!m_displayEngouragement)
		return;

	m_sprite->Update();
}

void Encouragement::Display(int type)
{
	if(type==e_ncrg_good)
	{
		m_sprite->SetImage(e_ncrg_good);
	}
	else
	{
		m_sprite->SetImage(e_ncrg_wow);
	}

	m_displayEngouragement=true;
	m_animationStartTime=clock();
}