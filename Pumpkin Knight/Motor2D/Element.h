#ifndef __ELEMENT_H__
#define __ELEMENT_H__

#include "p2Point.h"
#include "SDL/include/SDL.h"
#include "j1Gui.h"


class Element : public j1Gui
{
public:
	Element(int x, int y, ElementType type);
	~Element();

	virtual void Draw() {}
	//virtual void OnClick() {}
	//virtual void OnEntry() {}
	//virtual void OnExit() {}

public:

	iPoint pos;
	ElementType type;
	UIEvents event_type;

	uint tex_width;
	uint tex_height;

	bool mouse_in = false;
	bool mouse_out = false;

	SDL_Rect element_rect;

};

#endif // !__ELEMENT_H__
