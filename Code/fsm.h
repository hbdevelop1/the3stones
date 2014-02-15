#ifndef _FSM_
#define _FSM_

enum State
{
	e_Starting=1,
	e_Ticking,
	e_Ending
};

#define CONSTRUCT_BEHAVIOR_BEGIN	\
	if(m_state == e_Starting) \
	{\

#define CONSTRUCT_BEHAVIOR_END		\
		m_state = e_Ticking; \
	}\
	else

#define UPDATE_BEHAVIOR_BEGIN	\
	if(m_state == e_Ticking) \
	{\

#define UPDATE_BEHAVIOR_END		\
	}\
	else

#define DESTRUCT_BEHAVIOR_BEGIN		\
	if(m_state == e_Ending) \
	{\

#define DESTRUCT_BEHAVIOR_END		\
		m_state = e_Starting; \
	}



#define START_BEHAVIOR(Class,newbehavior)  \
{ \
	m_state = e_Starting;	\
	m_currentbehavior = & Class::newbehavior;	\
}
//m_currentbehavior = & Class::Behavior_##newbehavior;	\

#define CHANGE_BEHAVIOR(Class,newbehavior)  \
{ \
	m_state = e_Ending;	\
	(this->*m_currentbehavior)();\
	m_currentbehavior = & Class::newbehavior;	\
	(this->*m_currentbehavior)(); \
}
//no code should run after calling CHANGE_BEHAVIOR



#endif //_FSM_
