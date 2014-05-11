
#include "Encouragement.h"
#include "graphic/TexturesManager.h"
#include "xml/xml.h"
#include "graphic/Sprite.h"
#include <string>
using namespace std;
#include "mem/MemNew.h"

Encouragement::~Encouragement()
{
#ifdef _listofobjects_
#else
#ifdef _listofpointers_
	Sprite * g;
	for(auto it=m_listofsprites.begin(); it!=m_listofsprites.end(); ++it)
	{
		delete *it;
	}

	m_listofsprites.clear();
#else
#endif _listofpointers_
#endif _listofobjects_
}
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
	/*
#ifdef _listofobjects_
			m_listofsprites.push_back(Sprite(points,texturename.c_str(), animationfile.c_str()));
#else
#ifdef _listofpointers_
			m_listofsprites.push_back(new Sprite(points,texturename.c_str(), animationfile.c_str()));
#else
	m_listofsprites.reset(new std::list<Sprite *, hb::allocator<Sprite *> > );
#endif _listofpointers_
#endif _listofobjects_
	*/
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

			String texturename = child->getAttribute("texture");
			String animationfile = child->getAttribute("animation");

#ifdef _listofobjects_
			m_listofsprites.push_back(Sprite(points,texturename.c_str(), animationfile.c_str()));
#else
#ifdef _listofpointers_
			m_listofsprites.push_back(new Sprite(points,texturename.c_str(), animationfile.c_str()));
#else
/*			m_listofsprites.get()->push_back(new Sprite(points,texturename.c_str(), animationfile.c_str()));
			(*m_listofsprites).push_back(new Sprite(points,texturename.c_str(), animationfile.c_str()));*/
			m_listofsprites->push_back(new Sprite(points,texturename.c_str(), animationfile.c_str()));
#endif _listofpointers_
#endif _listofobjects_
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
/*#ifdef _listofobjects_

#ifdef _listofpointers_
#else
*/
	for(auto it=m_listofsprites.begin(); it!=m_listofsprites.end(); ++it)
	{
#ifdef _listofobjects_
		(*it).Draw();
#else
#ifdef _listofpointers_
		(*it)->Draw();
#endif _listofpointers_
#endif _listofobjects_
	}
//#endif
}

void Encouragement::Update()
{
	for(auto it=m_listofsprites.begin(); it!=m_listofsprites.end(); ++it)
	{
#ifdef _listofobjects_
		(*it).Draw();
#else
#ifdef _listofpointers_
		(*it)->Update();
#endif _listofpointers_
#endif _listofobjects_
	}
}
