#include <windows.h>

#include <GL/gl.h>
#include <glut\glut.h>

#include "rectangle.h"
#include "game.h"
#include "board.h"
#include "classids.h"
#include "objectsmanager.h"
#include "ObjectsRectangles.h"
#include "common.h"
#include "graphic/TexturesManager.h"

#include "Mem/MemNew.h"

namespace hb
{
void DrawText(const char *txt, signed int x, signed int y)
{
	if(x>-1 && y>-1)
		glRasterPos2f(x, y);

	const char* p= txt;
	while (*p != '\0') glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
}
}

LARGE_INTEGER	g_frequency;
LARGE_INTEGER	g_start;
LARGE_INTEGER	g_end;
LONGLONG diffMax=-1;
LONGLONG diffMin=MAXLONGLONG;
double timeinSecondsMax;
double timeinSecondsMin;
		char timeinSecondsMaxbuf[80];
		char timeinSecondsMinbuf[80];

void AtExit()
{
	ObjectsManager::GetInstance().Clear();

	hb::DumpUnfreed();
}

void game_init()
{
	if(atexit (AtExit))
		exit(1);

	if(!TexturesManager::GetInstance().TexInit())
		exit(1);

	ObjectsManager::GetInstance().PushBack(CLASSID_game,true);
	
}
void game_deinit()
{
}

void onMouse( int button, int state, int x, int y) 
{
	if(button==GLUT_LEFT_BUTTON)
	{
		if(state==GLUT_DOWN)
		{
			ObjectsManager::GetInstance().GetMaster()->OnClick(
				static_cast<unsigned int>(x),
				static_cast<unsigned int>(ObjectsRectangles[e_rect_window].t - y));
		}
	}
}


void display(void)
{
/*  clear all pixels  */
    glClear (GL_COLOR_BUFFER_BIT);

	QueryPerformanceCounter(&g_start);

	ObjectsManager::GetInstance().Update();
	ObjectsManager::GetInstance().Draw();
	ObjectsManager::GetInstance().RunDelayedFunctions();

	QueryPerformanceCounter(&g_end);

	LONGLONG diff = g_end.QuadPart - g_start.QuadPart;
	if(diffMax<diff)
	{
		diffMax=diff;
		timeinSecondsMax = (double)diffMax/g_frequency.QuadPart;

		sprintf(timeinSecondsMaxbuf,"%E",timeinSecondsMax );
	}

	glColor3f (1.0, 1.0, 1.0);

	hb::DrawText(timeinSecondsMaxbuf,ObjectsRectangles[e_rect_window].l+2, ObjectsRectangles[e_rect_window].b+60);

	double timeinSeconds = (double)diff/g_frequency.QuadPart;
	char buf[80];
	sprintf(buf,"%E",timeinSeconds);
	hb::DrawText(buf,ObjectsRectangles[e_rect_window].l+2, ObjectsRectangles[e_rect_window].b+40);

	if(diffMin>diff)
	{
		diffMin=diff;
		timeinSecondsMin = (double)diffMin/g_frequency.QuadPart;

		sprintf(timeinSecondsMinbuf,"%E",timeinSecondsMin );
	}
	hb::DrawText(timeinSecondsMinbuf,ObjectsRectangles[e_rect_window].l+2, ObjectsRectangles[e_rect_window].b+20);

 glutSwapBuffers ( );

}

void init (void) 
{
    glClearColor (0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluOrtho2D(	ObjectsRectangles[e_rect_window].l,ObjectsRectangles[e_rect_window].r,
				ObjectsRectangles[e_rect_window].b,ObjectsRectangles[e_rect_window].t);


	QueryPerformanceFrequency(&g_frequency);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (	
		static_cast<int>(ObjectsRectangles[e_rect_window].r)-static_cast<int>(ObjectsRectangles[e_rect_window].l),
		static_cast<int>(ObjectsRectangles[e_rect_window].t)-static_cast<int>(ObjectsRectangles[e_rect_window].b)
		);

    glutInitWindowPosition (0, 0);
    glutCreateWindow ("The Three Stones");
    init ();
	game_init();
    glutDisplayFunc(display); 
	glutMouseFunc( onMouse);

	glutIdleFunc		  ( display );
    glutMainLoop();
	game_deinit();
    return 0; 
}

