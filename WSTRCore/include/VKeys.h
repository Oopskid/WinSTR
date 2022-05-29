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

		void keyDown(char vkey);
		void keyUp(char vkey);
		void clearPresses();

		bool isKeyDown(char vkey);
		bool isKeyPress(char vkey); //End of press
		bool isKeyJustDown(char vkey); //Beginning of press

		private:
		void resetKeys();

		static constexpr size_t KEY_COUNT = 0xFF + 1;
		char keyEvents[KEY_COUNT]; //b0 = isDown, b1 = press/end of down, b2 = press/begin of down

		std::list<char> onceEvents;
	};
}