#pragma once
#ifndef __TEXTBOX_H__
#define __TEXTBOX_H__

#include "Elements.h"

class Text_Box : public Elements
{
public:
	Text_Box(int x, int y, ELEMENT_TYPES types, const char* text);
	~Text_Box();

	void Draw();
	void Write();

private:
	const char* boxtext = nullptr;
	SDL_Texture* Box = nullptr;
	SDL_Texture* BoxText = nullptr;

	bool writing = false;

	uint x_size;
	uint y_size;
};


#endif // !__TEXTBOX_H__