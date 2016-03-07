#ifndef _ANIM_H_
#define _ANIM_H_

#include <vector>
#include <time.h>
#include "../Common.h"
#include "../mem/allocator.h"
#include "../rectangle.h"


//using namespace std;
/*
#define new new(__FILE__,__LINE__)
namespace hb
{
	
template<class _Ty> inline
	_Ty *_Allocate(size_t _Count, _Ty  *)
	{	// allocate storage for _Count elements of type _Ty
	void *_Ptr = 0;

	if (_Count <= 0)
		_Count = 0;
	else if (((size_t)(-1) / sizeof (_Ty) < _Count)
		  || (_Ptr = new char[sizeof(_Ty) *_Count]) == 0)
#if _MSC_VER = 1700
          throw new std::bad_alloc;
#elif _MSC_VER = 1600
		_THROW_NCEE(std::bad_alloc, 0);
#endif


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

	typename std::allocator<_Ty>::pointer allocate(typename std::allocator<_Ty>::size_type _Count)
		{
		return (hb::_Allocate(_Count, (std::allocator<_Ty>::pointer)0));
		}
};
}//hb



*/













//the first resting position (default position) is a keyframe
struct stKeyFrame
{
	hb::Points32	offset[4];//the displacement offset for each vertex in the rectangle, counter clockwise.
	clock_t			time;

	stKeyFrame();
	stKeyFrame(hb::Points32 p[], clock_t t);
};

class Anim
{
	std::vector<stKeyFrame,hb::allocator<stKeyFrame> > m_keyFrameList;
	hb::Points32		*m_r;

	clock_t				m_firstKeyFrameTime;
	clock_t				m_lastKeyFrameTime;
	clock_t				m_startTime;

private:

	void Init();
	void Lerp(stKeyFrame & frame1, stKeyFrame & frame2, long );

public:

	Anim(const char * animationfilename, hb::Points32 []);
	~Anim();
	void Update();
	void Reset();

} ;


#endif _ANIM_H_