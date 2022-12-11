#include "pch.h"
#include "Window.h"

using namespace WSTR;

Window::Window()
{
	winClass = {};
	wHandle = nullptr;
	open = false;

	devCon = nullptr;

	pForm = &defaultPFormat;

	styleEx = WS_EX_CLIENTEDGE;
	style = WS_OVERLAPPEDWINDOW;

	x = CW_USEDEFAULT;
	y = CW_USEDEFAULT;
	width = 1;
	height = 1;
}

Window::~Window()
{

}

void Window::appContext(const wchar_t* appName)
{
	winClass.lpfnWndProc = &routine;
	winClass.hInstance = GetModuleHandleW(NULL); //Application instance
	winClass.lpszClassName = appName;

	RegisterClassW(&winClass); //Register this
}

void Window::create()
{
	wHandle = CreateWindowExW(
		styleEx, //Expanded window style
		winClass.lpszClassName, //Class name
		title.c_str(), //Window title
		style, //Window style
		x, y,
		width, height,
		NULL,       // Parent window    
		NULL,       // Menu
		winClass.hInstance,  //Instance handle
		nullptr
	);

	SetWindowLongPtrW(wHandle, GWLP_USERDATA, LONG_PTR(this)); //This class instance

	devCon = GetDC(wHandle); //Device context
	applyPixelFormat();

	onCreate();
}
void Window::create(const std::wstring wTitle, size_t wWidth, size_t wHeight)
{
	width = wWidth;
	height = wHeight;
	title = wTitle;

	create();
}


void Window::show()
{
	ShowWindow(wHandle, SW_NORMAL);
}

void Window::run()
{
	open = true;

	onStart();
	while (open)
	{
		MSG msg;
		while (PeekMessageW(&msg, wHandle, 0, 0, PM_REMOVE))
		{
			//TranslateMessageW(&msg); not required/inefficient
			DispatchMessageW(&msg);
		}

		main();
	}
	onEnd();
}

void Window::setPixelFormat(const PIXELFORMATDESCRIPTOR* format)
{
	pForm = format;
}

void Window::applyPixelFormat()
{
	int match = ChoosePixelFormat(devCon, pForm);
	SetPixelFormat(devCon, match, pForm);
}

size_t Window::getWidth()
{
	return width;
}

size_t Window::getHeight()
{
	return height;
}

size_t Window::getX()
{
	return x;
}

size_t Window::getY()
{
	return y;
}

LRESULT Window::routine(HWND handle, UINT message, WPARAM wParam, LPARAM lParam)
{
	Window* window = reinterpret_cast<Window*>(GetWindowLongPtrW(handle, GWLP_USERDATA));

	switch (message)
	{
		case WM_CLOSE:
			window->open = false;
			break;

		case WM_SIZE:
			window->width = LOWORD(lParam);
			window->height = HIWORD(lParam);
			window->onResize();
			break;
		case WM_MOVE:
			window->x = LOWORD(lParam);
			window->y = HIWORD(lParam);
			window->onMove();
			break;
		case WM_KEYDOWN:
			window->onKeyDown(wParam & 0xFF); //Note: virtual keycode
			break;
		case WM_KEYUP:
			window->onKeyUp(wParam & 0xFF); //Note: virtual keycode
			break;
		//Mouse buttons (yeah I don't get it)
		case WM_LBUTTONDOWN: window->onKeyDown(VK_LBUTTON); break;
		case WM_LBUTTONUP: window->onKeyUp(VK_LBUTTON); break;
		case WM_RBUTTONDOWN: window->onKeyDown(VK_RBUTTON); break;
		case WM_RBUTTONUP: window->onKeyUp(VK_RBUTTON); break;

		case WM_MOUSEMOVE:
			window->onMouseMove(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
			break;

		//case WM_NCHITTEST: return HTCLIENT; //TEMP
	}

	return DefWindowProcW(handle, message, wParam, lParam);
}