#pragma once

//--Windows API--
//Consider WIN32_LEAN_AND_MEAN!
//Use #define WIN_CLASSIC to regain original features that are excluded here

#ifndef WIN_H
	#define WIN_H

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

#endif
//--Windows API--

//--Winsock API--
//Use #define WIN_SOCK to access
//Note: deprecated
#ifdef WIN_SOCK
#ifndef WINSOCK_H
	#define WINSOCK_H

	//Post linkage
	#pragma comment(lib, "ws2_32")

	#define _WINSOCK_DEPRECATED_NO_WARNINGS //Deprecated but intent towards use has been clear

	//Library includes
	#include <stdio.h>
	#include <winsock2.h>
	#include <WS2tcpip.h>
	#include <MSWSock.h>

#endif
#endif
//--Winsock API--

//--GDI(+) API--

//Activate GDI with GDI+
#ifdef GDI_PLUS
	#define WIN_GDI
#endif

//GDI API
//Use #define WIN_GDI to access
#ifdef WIN_GDI
#ifndef WIN_GDI_H
	#define WIN_GDI_H

	//Post linkage
	#pragma comment (lib,"gdi32")

	//Library includes

#endif
#endif

//GDI+ API
//Use #define GDI_PLUS to access
#ifdef GDI_PLUS
#ifndef GDI_PLUS_H
	#define GDI_PLUS_H

	//Post linkage
	#pragma comment (lib,"Gdiplus")

	//Library includes
	#include <objidl.h>
	#include <gdiplus.h>

#endif
#endif
//--GDI(+) API--