#pragma once
#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "Elements.h"

class Button : public Elements
{
public:
	Button(int x, int y, ELEMENT_TYPES types, const char* text);
	~Button();

	void Draw();
	//bool Highlight();

private:
	const char* buttontext = nullptr;
	SDL_Texture* ButtonBox = nullptr;
	SDL_Texture* ButtonText = nullptr;

	uint x_size;
	uint y_size;
};


#endif // !__BUTTON_H__

