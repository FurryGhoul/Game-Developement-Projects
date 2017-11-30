#pragma once
#ifndef __TEXT_H__
#define __TEXT_H__

#include "Elements.h"

class Text : public Elements
{
public:
	Text(int x, int y, ELEMENT_TYPES types, const char* text);
	~Text();

	void Draw();
	//bool Highlight();

private:
	const char* text = nullptr;
	SDL_Texture* Text_tex = nullptr;

	uint x_size;
	uint y_size;
};


#endif // !__TEXT_H__
