#include "pch.h"
#include "MousePointer.h"

using namespace WSTR;

MousePointer::MousePointer()
{
	moved = false;

	x = 0;
	y = 0;
	dx = 0;
	dy = 0;
	globalX = 0;
	globalY = 0;
}

short MousePointer::getX()
{
	return x;
}

short MousePointer::getY()
{
	return y;
}

short MousePointer::getDX()
{
	return dx;
}

short MousePointer::getDY()
{
	return dy;
}

void MousePointer::setGlobalOffset(int gX, int gY)
{
	globalX = gX;
	globalY = gY;
}

void MousePointer::setMousePosition(short localX, short localY)
{
	x = localX;
	y = localY;

	SetCursorPos(localX + globalX, localY + globalY);
}

void MousePointer::onMouseMove(short mX, short mY)
{
	dx += mX - x; //Multiple message protection
	dy += mY - y;

	x = mX;
	y = mY;

	moved = dx || dy; //Mouse set loop protection
}

bool MousePointer::isMoved()
{
	return moved;
}

void MousePointer::clearEvents()
{
	moved = false;
	dx = 0;
	dy = 0;
}
