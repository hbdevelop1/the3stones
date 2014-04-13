#include "xml.h"

#include <assert.h>

void printXml( XmlNodeRef node ) {
	String str = node->getXML();
	printf( "%s",str.c_str() );
}

void main() {
	XmlParser xmlParser;
	XmlNodeRef root = xmlParser.parse( 
		//"test.xml" 
		"..\..\map.xml" 
		);

	if (root) {
		printXml( root );
	}
	else
	{
		assert(0);		
	}

	if (root) 
	{
		for (int i = 0; i < root->getChildCount(); i++) 
		{
			XmlNodeRef child = root->getChild(i);
			if (child->isTag("world")) 
			{
				if (child->getAttribute("name") == "blah") 
				{
				}
			}
		}
	}

}