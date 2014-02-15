
#include "common.h"
#include "object.h"

#ifdef _use_my_mem_tracker_
#define new new(__FILE__,__LINE__)
#endif //_use_my_mem_tracker_

Object::Object():next(NULL),prev(NULL),flag(e_FLAG_NOTHING)
{
}

Object::~Object()
{
}

void operator|=(Object::FLAGS & f,Object::FLAGS l)
{
	hbassert(Object::e_FLAG_NOTHING<l && l<Object::e_FLAG_END);
	* reinterpret_cast<unsigned int*>(&f) |= static_cast<unsigned int>(l);
}

void Object::SetFlag(FLAGS f)
{
//	flag |= f;
	hbassert(Object::e_FLAG_NOTHING<f && f<Object::e_FLAG_END);
	* reinterpret_cast<unsigned int*>(&flag) |= static_cast<unsigned int>(f);
}

void Object::UnSetFlag(FLAGS f)
{
	hbassert(Object::e_FLAG_NOTHING<f && f<Object::e_FLAG_END);
	* reinterpret_cast<unsigned int*>(&flag) &= static_cast<unsigned int>(~f);
}

Object::FLAGS Object::GetFlag()
{
	return flag;
}