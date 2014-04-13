
#include "Encouragement.h"
#include "graphic/TexturesManager.h"
#include "xml/xml.h"
#include "graphic/Sprite.h"
#include <string>
using namespace std;
#include "mem/MemNew.h"

Encouragement::Encouragement(char * filename)
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
			String pointstring = child->getAttribute("rectangle");
			sscanf(pointstring.c_str(),"%d %d %d %d %d %d %d %d"
				,&points[0].x,&points[0].y
				,&points[1].x,&points[1].y
				,&points[2].x,&points[2].y
				,&points[3].x,&points[3].y);

			String texturename = child->getAttribute("texture");
			String animationfile = child->getAttribute("animation");

			m_listofsprites.push_back(Sprite(points,texturename.c_str(), animationfile.c_str()));
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
	return;
	for(unsigned int i=0; i<m_nbrofsprites; ++i)
	{
		//m_sprites[i].Draw();
	}
}

void Encouragement::Update()
{
	return;
	for(unsigned int i=0; i<m_nbrofsprites; ++i)
	{
		//m_sprites[i].Update();
	}
}
