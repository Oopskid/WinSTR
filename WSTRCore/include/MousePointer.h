#pragma once

//Framework
#include "WSTR.h"

namespace WSTR
{
	//Pointer input manager
	class MousePointer
	{
		public:
		MousePointer();

		short getX();
		short getY();
		short getDX();
		short getDY();

		void setGlobalOffset(int gX, int gY);
		void setMousePosition(short localX, short localY);

		void onMouseMove(short mX, short mY);

		bool isMoved();

		void clearEvents();

		private:
		bool moved;

		short x, y; //Local position
		short dx, dy; //Difference in position between frames
		int globalX, globalY; //Offset to global position
	};
}