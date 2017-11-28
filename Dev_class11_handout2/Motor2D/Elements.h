#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "j1Module.h"
#include "p2Point.h"
#include "p2DynArray.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Collisions.h"

class Elements
{

public:
	Elements(int x, int y);
	~Elements();

	const Collider* GetCollider() const;

	//virtual bool Awake(pugi::xml_node&);

	virtual void Draw(SDL_Texture* sprite);

	virtual void OnCollision(Collider* collider);
	
	virtual void MoveEnemy(float dt) {};

public:

	SDL_Texture* sprites = nullptr;

	fPoint pos;
	fPoint collider_pos;
	fPoint original_pos;
	fPoint speed;

	Collider* collider = nullptr;


	int x_scale;
	int y_scale;

	bool flip;
};
#endif // !_ENTITY_H_
