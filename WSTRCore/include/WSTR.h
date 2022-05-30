#pragma once

//--Windows API--
//Make sure to include/define additional windows functionality before this header
//Consider WIN32_LEAN_AND_MEAN!
//Use #define WIN_CLASSIC to regain original features that are excluded here

#ifndef WIN_H
	//Post linkage
	#pragma comment(lib, "kernel32")
	#pragma comment(lib, "user32")
	#pragma comment(lib, "gdi32")
	#pragma comment(lib, "comdlg32")

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