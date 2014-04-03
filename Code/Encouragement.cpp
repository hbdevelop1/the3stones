
#include "Encouragement.h"


Encouragement::Encouragement(unsigned int n):m_nbrofelements(n)
{
	m_elements.reset(new Graphic[m_nbrofelements]);
}

void Encouragement::Draw()
{
	for(unsigned int i=0; i<m_nbrofelements; ++i)
	{
		m_elements[i].Draw();
	}
}

void Encouragement::Update()
{
	for(unsigned int i=0; i<m_nbrofelements; ++i)
	{
		m_elements[i].Update();
	}
}



void Graphic::Draw()
{
}

void Graphic::Update()
{
}

