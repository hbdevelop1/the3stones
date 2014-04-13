
#ifndef _INTRO_
#define _INTRO_

#include <stdio.h>
#include "rectangle.h"
#include "object.h"

#define _anim_ 0



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
#include "anim.h"
#endif _anim_==1


class Intro : public Object
{
#if _anim_>0
	hb::Points32 r[4];
#else
	const hb::Rectangle & r;
#endif

	hb::Rectangle rplay;
#if _anim_>0
	stAnim anim;
#endif
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