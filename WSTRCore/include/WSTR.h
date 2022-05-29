#pragma once

//--Windows API--
//Make sure to include/define additional windows functionality before this header
//Consider WIN32_LEAN_AND_MEAN!
//Use #define WIN_CLASSIC to regain original features that are excluded here

#ifndef WIN_H
	#include <windows.h>

	#ifndef WIN_CLASSIC
		//Remove nasty archaic preprocessors
		#undef min
		#undef max
		
		//Use helpers
		#include "Windowsx.h"
	#endif

	#define WIN_H
#endif
//--Windows API--