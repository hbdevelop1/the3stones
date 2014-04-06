
#ifndef _INTRO_
#define _INTRO_

#include <stdio.h>
#include "rectangle.h"
#include "object.h"
#include "allocator.h"

#define _anim_ 1

#if _anim_==1
#include <vector>
#include <time.h>
//using namespace std;
#endif _anim_==1


/*
namespace hb
{
template<class _Ty> inline
	_Ty *_Allocate(size_t _Count, _Ty  *)
	{	// allocate storage for _Count elements of type _Ty
	void *_Ptr = 0;

	if (_Count <= 0)
		_Count = 0;
	else if (((size_t)(-1) / sizeof (_Ty) < _Count)
		//|| (_Ptr = ::operator new(_Count * sizeof (_Ty))) == 0)
		  || (_Ptr = new _Ty[_Count]) == 0)
		_THROW_NCEE(bad_alloc, 0);

	return ((_Ty *)_Ptr);
	}

template<class _Ty> class allocator : public std::allocator<_Ty>
{
public:
	template<class _Other>
		struct rebind
		{
		typedef allocator<_Other> other;
		};

	allocator() throw ()
		{
		}

	allocator(const allocator<_Ty>&) throw ()
		{	
		}

	template<class _Other> allocator(const allocator<_Other>&) throw ()
		{
		}

	pointer allocate(size_type _Count)
		{
			char * ii= //::operator new(16)
							new char[4]
				//0
			;

		return (hb::_Allocate(_Count, (pointer)0));
		}
};
}//hb
*/


#if _anim_==1

//the first resting position (default position) is a keyframe
struct stKeyFrame
{
	hb::Points32 offset[4];//the displacement offset for each vertex in the rectangle, counter clockwise.
	stKeyFrame()
	{
		offset[0]=hb::Points32(0,0);
		offset[1]=hb::Points32(0,0);
		offset[2]=hb::Points32(0,0);
		offset[3]=hb::Points32(0,0);
	}
};
struct stAnim 
{
	std::vector<stKeyFrame,hb::allocator<stKeyFrame> > keyframelist;
	const clock_t		durationbetweenframes; //duration between two consecutive frames, interpolated or key.
	clock_t			lastframetime; //this is to decide whether to interpolate the next frame.
	unsigned char	nbrofkeyframes;//nbr of frames in the anim including the first and last resting positions
	unsigned char	currentkeyframe;//needed to know the next key frame to go to
	bool			loop;
	bool			ended;	//if !loop, ended=true when currentkeyframe==nbrofkeyframes-1



	stAnim():durationbetweenframes(200)
	{
		stKeyFrame k;

		k.offset[2]=hb::Points32(0,0);
		keyframelist.push_back(k);
		k.offset[2]=hb::Points32(5,5);
		keyframelist.push_back(k);
		k.offset[2]=hb::Points32(15,15);
		keyframelist.push_back(k);
		k.offset[2]=hb::Points32(9,5);
		keyframelist.push_back(k);
		k.offset[2]=hb::Points32(0,0);
		keyframelist.push_back(k);

		nbrofkeyframes=keyframelist.size();
		assert(nbrofkeyframes>1); //otherwise an issue at "if(!anim.loop && ++anim.currentKeyFrame==anim.nbrofkeyframes-1)"
		lastframetime=clock();
		currentkeyframe=0;
		loop = true;
		ended=false;

	}
} ;
#endif _anim_==1


class Intro : public Object
{
#if _anim_>0
	hb::Points32 r[4];
#else
	const hb::Rectangle & r;
#endif

	hb::Rectangle rplay;
	stAnim anim;
	unsigned int m_texObj;

	enum
	{
		e_msg_rules,
		e_msg_arrange,
		e_msg_position,
		e_msg_if,
		e_msg_win,

		e_msg_nbroftextmsgs
	};

public:
	enum
	{
		e_width=100,
		e_height=60,
	};
public:
	Intro();
	~Intro();

	void Update();
	void Draw();

	void OnClick(uint32 x,uint32 y);
};

#endif //_Intro_