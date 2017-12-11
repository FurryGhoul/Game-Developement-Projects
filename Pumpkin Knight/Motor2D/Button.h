#pragma once
#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "Element.h"

class Button : public Element
{
public:
	Button(int x, int y, ElementType types, SDL_Rect* TexRect, const char* text);
	~Button();

	void Draw();
	//bool Highlight();

private:
	const char* buttontext = nullptr;
	SDL_Texture* ButtonBox = nullptr;
	SDL_Texture* ButtonText = nullptr;

	SDL_Rect* texture_rect;
};


#endif // !__BUTTON_H__
