#pragma once

//Structures
#include <list>

namespace WSTR
{
	//Virtual key input manager
	class VKeys
	{
		public:
		VKeys();

		void keyDown(unsigned char vkey);
		void keyUp(unsigned char vkey);
		void clearPresses();

		bool isKeyDown(unsigned char vkey);
		bool isKeyPress(unsigned char vkey); //End of press
		bool isKeyJustDown(unsigned char vkey); //Beginning of press

		private:
		void resetKeys();

		static constexpr size_t KEY_COUNT = 0xFF + 1;
		char keyEvents[KEY_COUNT]; //b0 = isDown, b1 = press/end of down, b2 = press/begin of down

		std::list<unsigned char> onceEvents;
	};
}