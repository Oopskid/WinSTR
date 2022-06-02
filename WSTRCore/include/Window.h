#pragma once

//Dependencies
#include <iostream>

//Structures
#include <string>
#include <thread>

//Framework
#include "WSTR.h"

namespace WSTR
{
	//Window manager
	class Window
	{
		public:
		Window();
		~Window();

		void appContext(const wchar_t* appName);
		void create();
		void create(const std::wstring title, size_t wWidth, size_t wHeight);
		void show();
		void run();

		void setPixelFormat(const PIXELFORMATDESCRIPTOR* format);
		void applyPixelFormat();

		size_t getWidth();
		size_t getHeight();

		size_t getX();
		size_t getY();

		protected:
		virtual void onCreate() {  }

		virtual void onResize() {  }
		virtual void onStart() {  }
		virtual void onDraw() {  }
		virtual void main() { std::cout << "live"; }
		virtual void onEnd() {  }

		virtual void onMove() {  }
		virtual void onKeyDown(char vkey) {  }
		virtual void onKeyUp(char vkey) {  }
		virtual void onMouseMove(short x, short y) {  }

		HDC devCon;
		HWND wHandle;

		private:
		static constexpr PIXELFORMATDESCRIPTOR defaultPFormat = {
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW |
		PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		24, //Colour depth bits
		0, 0, 0, 0, 0, 0,
		0,
		0,
		0,
		0, 0, 0, 0,
		16, //Depth buffer bits
		0,
		0,
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
		};;

		static LRESULT CALLBACK routine(HWND handle, UINT message, WPARAM wParam, LPARAM lParam);
		WNDCLASS winClass;

		const PIXELFORMATDESCRIPTOR* pForm;
		DWORD styleEx;
		DWORD style;

		size_t x, y, width, height;
		std::wstring title;
		bool open;
	};
}