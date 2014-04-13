#ifndef _HB_ALLOCATOR_H_
#define _HB_ALLOCATOR_H_

#include "MemNew.h"

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
		  //|| (_Ptr = new _Ty[_Count]) == 0) needs either delete or delete [] and there is no way to know
		  || (_Ptr = new char[sizeof(_Ty) *_Count]) == 0)
		_THROW_NCEE(std::bad_alloc, 0);

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
	/*
	no need of this because new char[sizeof(_Ty) *_Count]
	//because i am allocating objects as array, deallocation shoud deallocate an array as well
	void deallocate(typename std::allocator<_Ty>::pointer _Ptr, typename std::allocator<_Ty>::size_type)
		{	// deallocate object at _Ptr, ignore size
		//::operator delete(_Ptr);
			delete [] _Ptr;
		}
		*/
};
}//hb

#endif //_HB_ALLOCATOR_H_