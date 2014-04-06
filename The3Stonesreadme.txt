
squares are independent elements
	they can be drawn anywhere in the game
	this means they hold their own position! they do not use Positions'. their resting position coincides with a Position.
	otherwise I will have to take the trouble of updating their corresponding position
	a Position has the id of the square sitting on it

shouldn't the board be singleton ?

a square should be able to be drawn anywhere in the board.
at the end of a transition, the square should rest in a position.
	when resting in a position, it should know the location pixel-wise
	when resting, it has the location of a positioninboard

7-when a tile is moving, its current, as opposite to destined, position is not marked fred. only when it has reached the destined position
does it swap marking.
this late marking of the free space prevents a descending/resting tile from moving until the one below has rested. 
this will help in obtaining the cascading actions.
but we loose control if we need to remove this cascading movement.

8-PositionInBoard[0][0] is occupied by the tile that is drawn at row 0 and column 0
PositionInBoard are not visible objects. there corresponding tiles get drawn at location relative to row and column of the PositionInBoard.

9-Board: we need to determine the tile corresponding to positions[i][j]. in order to ask it to move
the best idea is position->tile and vice versa tile->position
this needs a lot of update
bugs can slip when half updates are done.

10-
when X free positions are found, how to ask tiles to move X positions down.
	-should the board ask the first found up and instruct it to move 1 positions, and the next one to move 3 postions,etc ... 
	instructing each tile to move a number of positions depending on the number of free positions below it.
	we will have to keep track of the number of positions free
	we will have to tell this to each tile above until the generated ones.
	we will have to decide where each tile has to rest.
	-should the board instruct just one tile, which will pass the info on to the tiles above it.
	-should the board only order the generated ones to move a number of times and these will 'push' the other on board
	-should a tile move by itself when a position is free
	-the board could be informed when a position becomes free.
choosing a solution might mean a lot of change in the code when the solution is found to be not viable.
which choice is most viable, that fits for all cases.

thoughts triggered by :
	//start from below, for free positions, inform tile above it, to move to it
	for(uint i=0; i<e_RowSize; ++i)
		for(uint j=0; j<e_ColumnSize; ++j)
			if (positions[i][j].tile==NULL)
			{
				positions[i][j+1].tile move to positions[i][j];
				find the first tile on the way up and move to positions[i][j];
			}

10.1-selected the solution of the tile checking and moving automatically to the next position
if (pFreePositionToMoveTo=b.GetFreePositionBelow(loc))
has a limitiation:it does not look beyond the imediate next position

11
Board::Board():r(0.5f,  0.5f,
				0.5f+Board::e_ColumnSize*Square::e_Width,
				0.5f+Board::e_RowSize*Square::e_Height)
{
	//note-optim-possibility to optimize out the assignment operator. using an array of pointers or static incrementer

12
optimze out the rectangle of position, which is used to determine whether a tile has arrived to a position.
from the rectangle of position we only need the bottom and the top.
void Tile::Behavior_Move()
{
...
	UPDATE_BEHAVIOR_BEGIN
	{
		r.b--; r.t--;
		if(r.b == pCurrentPosition->r.b)

12.1 optimize out the desctructive part in behaviors
DESTRUCT_BEHAVIOR_BEGIN
{
}
DESTRUCT_BEHAVIOR_END

12.2
each function, accesses fields in a data structure in a different order.
for cache friendly data, use the order of fields required by most frequent accesses.

12.3 optimize
bool Tile::CheckMatches()

12.4 optimize using bit-wise operations

12.5 write a profiler. to assess the difference before and after optimization.

12.6 optimize out the divisions in TimeCounter::Update

13-
used draw1312281114 for basics and movement
using draw1312301204 created for mouse.
clicking on the tiles is correct in draw1312301204
using draw1312302135 for swapping
using draw1401021316 to carry on the work done in draw1312302135, which is incomplete
using draw1401021316 to carry on the work done in draw1312302135, which is incomplete
draw1401031541 reflects the core of the game
draw1401041219 same as draw1401031541 
draw1401050937 to work on text. text and individual done
draw1401061210 to work on global score. done
draw1401062124 to work on the time
draw1401122021 closed the loop on the game.
draw1401122022 is for texturing and animating the countdown
draw1401122022 is saved in draw1401132126.7z
draw1401132127 is derived ffrom draw1401122022 at 1401132127
draw1401142138 is the outcome of the work on draw1401132127 until 1401142138.
draw1401142139
hb::auto_ptr,

14- point and r should be constants
struct PositionInBoard
{
	hb::Pointu8	point;
	Tile		*tile;
	hb::Rectangle r;

15-
draw1312302135, doing swap, destruction, swap back, match
the board is Behavior_Stable. 
receives a click
then a second
the board is in Behavior_Swapping
	two tiles go to Behavior_Swapping. the other tiles are in Behavior_Resting
the board finds match
	three tiles are disappearing
	there can't be a state where the ones below them have disappeared. because the board haven't been receiving clicks since a while
		because when tiles were ordered to disappear, the board could not have received new clicks

17-
a fine line between 
	using the same behavior/function for many situation: this yields a long and complexe function
	using many little functions for each little situation. a lot of duplications, a bug in many places
17.2
coding is a series of decisions: will timeout be a class or code part of game. 
if it is a class will it have full access to game the inverse ?
will it be global or will game be ?

16-test cases for swap&match
swap&match the corners
swap&match the corners with matches
	vertically
	horizontally
	vertically & horizontally
swap&match in the midle w&w/o matches
	vertically
	horizontally
	vertically & horizontally



1 2 3 4 5 1 2 3
4 5 1 2 3 4 5 1
2 3 4 5 1 2 3 4
5 1 2 3 4 5 1 2
3 4 5 1 2 3 4 5
1 2 3 4 5 1 2 3
4 5 1 2 3 4 5 1
2 3 4 5 1 2 3 4

1 2 3 4 5 3 2 3
4 5 1 2 3 4 3 1
2 3 4 5 5 5 3 4
5 1 2 3 4   1 2
3 4 5 1 2 3 4 5
1 2 3 4 5 1 2 3
4 5 1 2 3 4 5 1
2 3 4 5 1 2 3 4

121
212

12
21
12

21122
12314
2

1213
1134
   3

121
232 (1)
343 

1211 (1)
2322 

non displaced ones-
	waiting for swap
	waiting for destruction, from moved tiles
	waiting for free room, due to the desctruction

involved in movement-
	checking for matches
		if found destruction issued
	waiting for destruction from moved tiles, using non-displaced tiles
	waiting for free room, due to the desctruction
	

4,3
4,3
4,2
5,0
5,2
5,3
3,0
6,0
4,1
5,5
0,4
2,5



4,4
4,4
4,2
5,0
5,2
5,?
1,3
3,2
5,1
3,2
3,4
2,5
4,4
3,6
1,6


Board::Behavior_Swapping
	Board::Behavior_InTransition
		Board::Behavior_Stable
	tile s to destory
	tiles stable
	
	
	
	Board::Behavior_SwappingBack

19-clean coding
------------
19.1- going from one scale ot another, from loc to rectangle, should generate a warning or an error.
so that we are forced to consciously manipulate the level we are handling. going from values from one scale to another 
should be careful.
pay attention to warning C4309: truncation of constant value. assigning 0xffffff to char may not be what we want. 
solutions : seperate usage or combination of the two following ways:
19.1.1-catching warnings
warning C4365: '=' : conversion from 'uint' to 'sint32', signed/unsigned mismatch
warning C4245: 'argument' : conversion from 'int' to 'uint', signed/unsigned mismatch
19.1.2-using data structure/class where the assignment/conversion operator is not defined from one type to the 
other: Pointu8 to Pointu32.

void Board::OnClick(uint32 x, uint32 y) is better than
void Board::OnClick(int x, int y). because i know that (1) x,y are bigger than those in hb::Pointu8 (2) x,y can go to hb::Pointu32 

void IndividualScore::AddScore(char *s,hb::Pointu32 sp) is better than
void IndividualScore::AddScore(char *s,int x, int y). because i know that sp should receive uint32 and not uint8 values.

    glutInitWindowSize (	 i am controling the conversion. it was a warning issued at level all
		static_cast<int>(windowRectangle.r)-static_cast<int>(windowRectangle.l),
		static_cast<int>(windowRectangle.t)-static_cast<int>(windowRectangle.b)

19.2-after compiling to fix errors, recompile the code with all warnings activated to detect probable errors 

19.3-it is enjoyable to code when:
-you analyze correctly, give yoursefl time, and then discover cases you didn't supect existed. 
your glad of yourself. this indicates that analysis and the 
time it takes is not a waste. and because these are one more bugs to deal with during the first tests.
-you discover that the code behaves exactly the way you have expected it.	
-you just code, with only very little debugging to do.
19.3
coding is a nightmare when you code a little and debug all the time crashes and incoherences. 
just to discover that you haven't given yourself time to think
about the proper desing, or forgot to set all fields in some data structure.

19.4
19.4.1-write the pseudo code. with the big picture in the mind. while enumerating all the cases
19.4.2-enumerate all the fields
		activeobjects.next;
		activeobjects.prev;
		activeobjects.next.prev;
		activeobjects.prev.next;

19.4.3-enumatate all fields and see how they should be modified for each new function.
struct.a;
struct.b;

19.4.4-a new field in a struct should be evaluated how it modified in every function
struct.a;
struct.b;


20-properties of the code
extensible ?
maintenable ?

20.1
GlobalObject is used instead of providing a function in game to wrap the fields function
GlobalObject is used instead of giving access to game.fields;
GlobalObject is also useful for any object in the system.

21-
when does notick happen?
FactoryCreateObject?

21.1 
SwitchRootContext.
	popall
	pushback
		create, via FactoryCreateObject, an unnamed object when passed a classid. it will be deleted on pop
		insertbefore active tail.
in the list of inactive contexts, the last set of contexts that were last ticking are delimited by MASTERs

22-
load the graphics of the game
interaction with the difficulty menu.
menu dissmissed
countdown
game is playable.
time out
feedback
show scores
	restart



23
the following function should ideally run pops or pushback in the order they were registered 
void ObjectsManager::RunDelayedFunctions()
{
	for(int i=0; i<NbrOfPopsToRun; ++i)
	{
//		PopsToRun[i].*pf(PopsToRun[i].arg1,true);
//		Pop(PopsToRun[i].arg,true);
		Pop(PopsArgs[i],true);
	}

	for(int i=0; i<NbrOfPushBacksToRun; ++i)
	{
		Push(PopsArgs[i],true);
	}
}

23.1-
game::WhenPushed()
the code in this function can be removed by using DelayedPushes
use DelayedPushes to make it popular

23.2
Score::WhenDeactivated()
the code in this function is necessary and can't go anywhere else or delayed.

23.3
ObjectsManager::GetInstance().PushBack(CLASSID_game,true);
game is constructed and pushed immediately
game constructor should not contain objects pushed immediately. they will be at the head of the list, so without a master object.
(removal, desactivation,... are done starting from the master)
ObjectsManager

23.4
delayed push/pop are mandatory when pushing a master
the list will end up with the new master pushed ....????? 
Q:read the push/pop function and see how the list will end up.

23.5
struct DelayedFunctionInfo
{
...
	enum
	{
		e_NumberOfDelayedFunctionsToRun=4, //at a moment there is board, score, timer and intro waiting to be pushed
	};										this value acts as a first shield against objects being pushed indifinitely by mistake


23.6-ObjectsManager::GetInstance()

can not update the list when issued by an element from the list 
problematic updates of the list are: add a master. remove the current master or current object (this).

23.7
todo explain this code
		void operator()()
		{
			(mo->*mf)(marg1,marg2);
		}
	
24
memory management in 
boost
books
ubiengines
internet

make sure the new[] and delete[] calls are correct.
make sure the overloaded new[] and delete[] calls are correct. 
	my overlaoded delete[] uses and address different from the one new[] returns
	either new[] returns incorrect. or called wrongly
	or delete[] receives incorrect.

24.1
how to test 
1>code\TexturesManager.cpp(21): warning C4291: 'void *operator new[](size_t,const char *,int)' : no matching operator delete found; memory will not be freed if initialization throws an exception
1>          c:\data2\code\c\king\thethreestones1401161557\code\MemTracker.h(17) : see declaration of 'operator new[]'





30
template<> class scoped_array<unsigned int>
{
	typedef unsigned int T;

	_hbPart1oftheclass_;

/* implicit conversion to "bool"*/											
#include <boost/smart_ptr/detail/operator_bool.hpp>							
																			
	_hbPart2oftheclass_;

i am defining _hbPart1oftheclass_ and _hbPart2oftheclass_ just because i don't want to rewrite the whole code from the 
principale class template.
Q:Why "#include <boost/smart_ptr/detail/operator_bool.hpp>" is not part of the macro ?

30.1.memory management
---------------------
	boost::scoped_array<TileTex> tiles;
	#define new new(__FILE__,__LINE__)
	tiles.reset(new TileTex [e_RowSize*e_ColumnSize]);
the above code uses the smart pointer 'tiles' so mem will be deallocated when it is destructed.
the allocated mem is also tracked my the mem tracker, so it will be reported at the end of the game if for whatever reason it is not deallocated.

30.2.memory management issue
---------------------
Encouragement freeing crashes. it might be because it is viewed an array of Graphic elements at desctruction is not viewed as such at allocation

30.3.memory management
---------------------
in each array row in allocations, the elements are just not used to store mem info. only the next elements are.
could need changing

struct lALLOC_INFO					+---NULL
	lALLOC_INFO * next -------------+				
struct lALLOC_INFO				+---struct lALLOC_INFO					+---struct lALLOC_INFO					
	lALLOC_INFO * next ---------+       long address;					|		long address;				+---NULL
struct lALLOC_INFO				        long size;						|		long size;					|		
	lALLOC_INFO * next ---------+       char file[FILENAMELEN+1];		|		char file[FILENAMELEN+1];	|		
	          					| 		long line;						|		long line;					|		
								|		lALLOC_INFO * next;-------------+		lALLOC_INFO * next;---------+	
								|	
								+---struct lALLOC_INFO
 										long address;
 										long size;
 										char file[FILENAMELEN+1];
 										long line;
 										lALLOC_INFO * next;

30.4-
explain when my overloaded new operator is called.
explain why using ::operator new[] does not create a infinite loop ?
why new and not malloc ?

void * operator new[](size_t size, char *filename, int line)
{
	void *ptr = //(void *)malloc(size);
		::operator new[](size);

	AddTrack((long)ptr, size,filename, line);
	hbhash::AddTrack((long)ptr, size,filename, line);
	return(ptr);
};
 
30.6
i overload the global operator new, operator delete, array new, or array delete
to detect memory leaks
for code that uses the standard global operator new as used by Deque, no checking is done at their destruction when the overload (my version) global operator delete is called.
it is not important that i assert if an address is not found in the array at its delete.
but it important that any registered address is deleted.
I take care that my allocation are registered by invoking the overloaded operator new and array new.

30.5
Not all arrays need to be pointed to by scoped_array
this is required for classes defining a destructor
for buit-in type arrays and classes without destructor, scoped_ptr should be used.
or scoped_array specialized and it destructor is redefined to use deleteo<>








300-todo: 
301-remove hbassert
302-common.h to include MemNew.h
303-
use smart ptr in this macro
	#define ImplementCreator(classname)	\
	Object * classname##_Creator()		\
	{									\
		return new classname;			\
	}








ACTIVE,board, tiles, score, timecounter, INACTIVE,menu pause, 
ACTIVE,show scores,restart,INACTIVE,feedback,board, tiles, score, timecounter, menu pause, 

still to do:
at the end of the game, pop objects pushed


done
-text "points" in the score window
-text "time" in the timecounter

todo

-increment of the global score.
-timecounter is a count down

-exiting. may be use the windows way.
-countdown animation	++
-shaded board				multitexturing, 
-countdown alpha color-key	++  
	or countdown image is of the size of the board, with alpha! or something

-timeout
	shaded board
	last score vs highest score		++
	replay ? yes quit				++

-review code.cpp, assert(TextInit),	++

-anim of tiles at setting, curve or trick(place each tile at a specific pos)	
-glow of tiles


-review destruction of the game. see if everything is undone.
-for maintenance :review and make coherent enum naming. e_type1,e_FLAG_...
-reduce the inclusion of header files. use as much as possible things like : 
class TimeCounter;
-check that for each new there is a corresponding delete
-add a mem allocator. to make sure no leak is there and to showcase knowledge
-how to write #ifdef DEBUGMODE && TESTING
-DelayedFunctionsToRun see 23

-how to modulate between texture and a color


grep -e 'board.cpp' -e 'tile.cpp' -e 'rectangle.cpp' -e 'IndividualScore.cpp' -e 'code.cpp' -e 'boardtest.cpp' -e 'board.h' -e 'tile.h' -e 'rectangle.h' -e 'IndividualScore.h' -e 'code.h' -e 'boardtest.h'   /cygdrive/c/data2/code/c/king/draw1401050937/output.txt > /cygdrive/c/data2/code/c/king/draw1401050937/output2.txt









abdoterbaoui@gmail.com

Hello Aaron,

Last week, I estimated that I would submit the project today.
Unfortunately, I still need to work on it for two more days.

I will submit it on Wednesday.

Please tell me if this delay may jeopardize my application.

Thank you and Sorry

Hassan Boulmarouf

is a problem to you  
I would be grateful to know the impact of this delay on 

Hello Emilie,

I have been working recently on a little game. 
And I thought Game Loft might be interested in taking a look at a sample of my code.

So, please find enclosed the source code of the game.
The name of the game is "TheThreeStones".

-To play it, decompress the archive to find the executable in TheThreeStones\EXE
-The source code is found in TheThreeStones\code
-The file TheThreeStones\Readme-Overview.txt gives a brief overview of the main elements in the code.
-The file TheThreeStones\Readme-Technical_features.txt gives the three main important technical features used to implement the game.

Best Regards,

Hassan Boulmarouf

Hello Rebecca,

Please find enclosed the source code for the test.
The name of the game is "TheThreeStones".

-To play it, decompress the archive to find the executable in TheThreeStones\EXE
-The source code is found in TheThreeStones\code
-The file TheThreeStones\Readme.txt gives a brief overview of the main elements in the code.

Best Regards,

Hassan Boulmarouf

Hello Rebecca,

I have improved the test game a little bit.
And I thought that King might be interested in considering this version over the previous one.
So, please find the attached improved version.

-To play it, decompress the archive to find the executable in "TheThreeStones\EXE"
-The source code is found in "TheThreeStones\code"
-The file "TheThreeStones\Readme-Overview.txt" gives a brief overview of the main elements in the code.
-The file "TheThreeStones\Readme-Technical_features.txt" gives the most important technical features used in the game.

Best Regards,

Hassan Boulmarouf

Hello 

I have been working recently on a little game. 
And I thought Rockstar might be interested in taking a look at a sample of my code.

So, please find enclosed the source code of the game. The name of the game is "TheThreeStones".

-To play it, decompress the archive to find the executable in TheThreeStones\EXE
-The source code is found in TheThreeStones\code
-The file TheThreeStones\Readme-Overview.txt gives a brief overview of the main elements in the code.
-The file TheThreeStones\Readme-Technical_features.txt gives the three main important technical features used to implement the game.

Best Regards,

Hassan Boulmarouf
