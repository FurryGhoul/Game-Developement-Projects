#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "j1Gui.h"
#include "p2Point.h"

class Elements : public j1Gui
{

public:
	Elements(int x, int y, ELEMENT_TYPES types);
	~Elements();

	virtual void Draw() {};

public:
	SDL_Rect elemrect;

	fPoint pos;

	uint x_size;
	uint y_size;

	ELEMENT_TYPES type;
};
#endif // !_ENTITY_H_
