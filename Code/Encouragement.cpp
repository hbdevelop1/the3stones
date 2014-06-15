
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
Encouragement::Encouragement(char * filename):m_displayEngouragement(true)
{
	ObjectsManager::GetInstance().RegisterGlobalObject(this,CLASSID_Encouragement);

	XmlParser xmlParser;
	XmlNodeRef rootNode= xmlParser.parse(filename);

	
	if (!rootNode) 
	{
		//todo : endprocess(); roll back allocation and end game
//		MessageBox(NULL,"Problème de données.\nRépertoire \"data\" ou fichier \"map.xml\" introuvable.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		assert(0);
	}

	for (int i = 0; i < rootNode->getChildCount(); i++)
	{
		XmlNodeRef child = rootNode->getChild(i);

		if (child->isTag("animatedsprite"))
		{
			hb::stRectangle2 rect;

			String pointstring = child->getAttribute("points");

			sscanf(pointstring.c_str(),"%d %d %d %d %d %d %d %d"
				,&rect.lb.x,&rect.lb.y
				,&rect.rb.x,&rect.rb.y
				,&rect.rt.x,&rect.rt.y
				,&rect.lt.x,&rect.lt.y);

			//String texturename = child->getAttribute("texture");
			String animationfile = child->getAttribute("animation");

			m_rect.reset(new hb::stRectangle2(rect));

			assert(m_sprite.get()==NULL);  //no more than one object.

			m_sprite.reset(new AnimatedSpriteNcrg(m_rect.get(),e_tex_encrg_good,e_tex_encrg_wow, animationfile.c_str()));
		}
	}
}

void Encouragement::Reset()
{
	//m_displayEngouragement=false;
}

void Encouragement::Draw()
{
	if(!m_displayEngouragement)
		return;

	m_sprite->Draw();

#ifdef _showanimationallthetime_
#else
	if(clock()-m_animationStartTime>1500)
		m_displayEngouragement=false;
#endif
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