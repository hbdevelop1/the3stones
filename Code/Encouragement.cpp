
#include "Encouragement.h"
#include "graphic/TexturesManager.h"
#include "xml/xml.h"
#include <string>
using namespace std;
#include "mem/MemNew.h"
#include "Score.h"
#include "ObjectsManager.h"
#include "classids.h"

Encouragement::~Encouragement()
{
}
Encouragement::Encouragement(char * filename, int itex):m_displayEngouragement(false),m_lasttime_checkscore(clock())
{
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
		if (child->isTag("number"))
		{
			String v = child->getAttribute("value");
			//sscanf(v.c_str(),"%d",&m_nbrofsprites);
		}
		else if (child->isTag("animatedsprite"))
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

			//m_sprite.reset(new Sprite(points,texturename.c_str(), animationfile.c_str()));
			m_sprite.reset(new Sprite(points, itex, animationfile.c_str()));
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

void Encouragement::Draw()
{
	if(m_displayEngouragement)
	{
		m_sprite->Draw();
	}
}

void Encouragement::Update()
{
	long t=clock();

	if(t-m_lasttime_checkscore>1500)
	{
		Score *o = dynamic_cast<Score *>(ObjectsManager::GetInstance().GetGlobalObject(CLASSID_Score));
		if(o->GetScore()-m_lastscoremade>200)
		{
			m_lastscoremade=o->GetScore();

			m_displayEngouragement=true;
			starttime4animation=clock();
		}
	}
/*	each time, check the score;
	if(score>400)
		display encouragement;
		reset score;

	set anim to 0 before launching it;
	*/

	if(m_displayEngouragement)
	{
		if(clock()-starttime4animation>2000)
			m_displayEngouragement=false;
	}

	if(m_displayEngouragement)
		m_sprite->Update();
}
