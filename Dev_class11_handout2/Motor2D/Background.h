#pragma once
#ifndef __BACKGROUND_H__
#define __BACKGROUND_H__

#include "Elements.h"

class Background : public Elements
{
public:
	Background(int x, int y, ELEMENT_TYPES types);
	~Background();

	void Draw();
};


#endif // !__BACKGROUND_H__



