#include <windows.h>

#include <GL/gl.h>
#include <glut\glut.h>

#include "rectangle.h"
#include "game.h"
#include "board.h"
#include "classids.h"
#include "objectsmanager.h"
#include "objectsrectangles.h"
#include "common.h"

#include "Mem/MemNew.h"

void AtExit()
{
	ObjectsManager::GetInstance().Clear();

	/*freeing memory this way is not efficient as it doesn't remove Intro, TimeOut and Countdown if they are running on. 
	use ObjectsManager::GetInstance().Clear()

	Object * o =ObjectsManager::GetInstance().GetGlobalObject(CLASSID_game);	
	ObjectsManager::GetInstance().Pop(o,true);
	*/
#ifdef _use_my_mem_tracker_
	hbhash::DumpUnfreed();
#endif
}

void game_init()
{


	if(atexit (AtExit))
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
				ObjectsManager::GetInstance().GetMaster()->
					OnClick(static_cast<uint32>(x),static_cast<uint32>(ObjectsRectangles[e_rect_window].t - y));
		}
	}
}

void display(void)
{
/*  clear all pixels  */
    glClear (GL_COLOR_BUFFER_BIT);

	++g_currentframe;
	ObjectsManager::GetInstance().Update();
	ObjectsManager::GetInstance().Draw();
	ObjectsManager::GetInstance().RunDelayedFunctions();
	
 glutSwapBuffers ( );

}

void init (void) 
{
    glClearColor (0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluOrtho2D(	ObjectsRectangles[e_rect_window].l,ObjectsRectangles[e_rect_window].r,
				ObjectsRectangles[e_rect_window].b,ObjectsRectangles[e_rect_window].t);
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