
#include "Encouragement.h"
#include "graphic/TexturesManager.h"
#include "xml/xml.h"
#include <string>
using namespace std;
#include "mem/MemNew.h"
#include "Score.h"
#include "ObjectsManager.h"
#include "classids.h"

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

	
	if (!rootNode) 
	{
		//todo : endprocess(); roll back allocation and end game
//		MessageBox(NULL,"Problème de données.\nRépertoire \"data\" ou fichier \"map.xml\" introuvable.","SHUTDOWN ERROR",MB_OK | MB_ICONINFORMATION);
		assert(0);
	}

	for (int i = 0; i < rootNode->getChildCount(); i++)
	{
		XmlNodeRef child = rootNode->getChild(i);
/*		if (child->isTag("number"))
		{
			String v = child->getAttribute("value");
			//sscanf(v.c_str(),"%d",&m_nbrofsprites);
		}
		else*/ 
		if (child->isTag("animatedsprite"))
		{

			hb::Points32 points[4];

			String pointstring = child->getAttribute("points");
			sscanf(pointstring.c_str(),"%d %d %d %d %d %d %d %d"
				,&points[0].x,&points[0].y
				,&points[1].x,&points[1].y
				,&points[2].x,&points[2].y
				,&points[3].x,&points[3].y);

			//String texturename = child->getAttribute("texture");
			String animationfile = child->getAttribute("animation");

			assert(m_sprite.get()==NULL);  //no more than one Sprite2 object.

			//m_sprite.reset(new Sprite(points,texturename.c_str(), animationfile.c_str()));
			m_sprite.reset(new Sprite2(points, animationfile.c_str(),e_tex_encrg_good,e_tex_encrg_wow));
		}
	}


	/*
	open file;
	discover the number of animatedsprites in the file;
	discover the content of each animatedsprite
		rectangle (size and relative position)
		nbr of keyframes
		keyframes
		assert the nbr of keyframes is consistant with the keyframes found

	m_nbrofsprites;

	m_sprites.reset(new Sprite[m_nbrofsprites]);
	for(unsigned int i=0; i<m_nbrofsprites; ++i)
	{
		Sprite[i]=new (m_sprites[i].get()) Sprite(animation[i]);
	}
	*/
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

#ifdef _showanimationallthetime_
#else
	if(clock()-starttime4animation>1500)
		m_displayEngouragement=false;
#endif
}

void Encouragement::Update()
{
	if(!m_displayEngouragement)
		return;

/*	each time, check the score;
	if(score>400)
		display encouragement;
		reset score;

	set anim to 0 before launching it;
	*/

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
	starttime4animation=clock();
}