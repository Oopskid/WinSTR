#include "pch.h"
#include "VKeys.h"

using namespace WSTR;

VKeys::VKeys()
{
	resetKeys();
}

void VKeys::keyDown(char vkey)
{
	keyEvents[vkey] |= 0b0000101;

	//Pressed flag register (on down)
	onceEvents.push_back(vkey);
}

void VKeys::keyUp(char vkey)
{
	//Up flag
	keyEvents[vkey] &= 0b11111110;

	//Pressed flag (on up)
	keyEvents[vkey] |= 0b00000010;
	onceEvents.push_back(vkey);
}

void VKeys::clearPresses()
{
	while (onceEvents.size() > 0)
	{
		keyEvents[*onceEvents.begin()] &= 0b11111001;
		onceEvents.pop_front();
	}
}

bool VKeys::isKeyDown(char vkey)
{
	return keyEvents[vkey] & 0b00000001;
}

bool VKeys::isKeyPress(char vkey)
{
	return keyEvents[vkey] & 0b00000010;
}

bool VKeys::isKeyJustDown(char vkey)
{
	return keyEvents[vkey] & 0b00000100;
}

void VKeys::resetKeys()
{
	for (size_t i = 0; i < KEY_COUNT; i++) { keyEvents[i] = NULL; }
	onceEvents.clear();
}
