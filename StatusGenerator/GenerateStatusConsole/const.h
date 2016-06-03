﻿#ifndef _CONST_H_
#define _CONST_H_

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define new ::new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define CHECKLEAK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_DELAY_FREE_MEM_DF|_CRTDBG_CHECK_ALWAYS_DF|_CRTDBG_LEAK_CHECK_DF);
#else
#define CHECKLEAK 
#endif

#define DECLARE_INHERIT_CLASS( Base ) typedef Base Super;
#endif
