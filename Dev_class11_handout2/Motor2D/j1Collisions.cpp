#include "j1App.h"
#include "j1Input.h"
#include "j1Render.h"
#include "j1Collisions.h"
#include "j1Gui.h"
j1Collisions::j1Collisions() : j1Module()
{
	name.create("colliders");

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
		colliders[i] = nullptr;

}

// Destructor
j1Collisions::~j1Collisions()
{

}

bool j1Collisions::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

bool j1Collisions::PreUpdate()
{
		// Remove all colliders scheduled for deletion
		for (uint i = 0; i < MAX_COLLIDERS; ++i)
		{
			if (colliders[i] != nullptr && colliders[i]->to_delete == true)
			{
				delete colliders[i];
				colliders[i] = nullptr;
			}
		}

	return true;
}

// Called before render is available
bool j1Collisions::Update(float dt)
{
	Collider* c1;
	Collider* c2;

	float enemygravity;
	float force;

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		// skip empty colliders
		if (colliders[i] == nullptr || colliders[i]->type == COLLIDER_NONE)
			continue;

		c1 = colliders[i];

		// avoid checking collisions already checked
		for (uint k = i + 1; k < MAX_COLLIDERS; ++k)
		{
			// skip empty colliders
			if (colliders[k] == nullptr)
				continue;

			c2 = colliders[k];

			
		}
	}

	DebugDraw();

	return true;
}

void j1Collisions::DebugDraw()
{
	if (App->input->GetKey(SDL_SCANCODE_F9) == KEY_DOWN) {
		LOG("You can see the colliders");
		debug = !debug;
	}

	if (debug == false) {
		return;
	}
	else {

		Uint8 alpha = 255;
		for (uint i = 0; i < MAX_COLLIDERS; ++i)
		{
			if (colliders[i] == nullptr)
				continue;

			switch (colliders[i]->type)
			{
			
			}
		}
	}
}

bool j1Collisions::checkColisionList(Collider * enemCollider)
{
	for (uint i = 0; i < MAX_COLLIDERS; ++i) {
		if (colliders[i] == nullptr)
			continue;
		if (enemCollider->CheckCollision(colliders[i]->rect))
			return true;
	}
	return false;
}

// Called before quitting
bool j1Collisions::CleanUp()
{
	LOG("Freeing all colliders");

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] != nullptr)
		{
			delete colliders[i];
			colliders[i] = nullptr;
		}
	}

	return true;
}

Collider* j1Collisions::AddCollider(SDL_Rect rect, COLLIDER_TYPE type, j1Module* callback)
{
	Collider* ret = nullptr;

	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] == nullptr)
		{
			ret = colliders[i] = new Collider(rect, type, callback);
			break;
		}
	}

	return ret;
}

bool j1Collisions::EraseCollider(Collider* collider)
{
	for (uint i = 0; i < MAX_COLLIDERS; ++i)
	{
		if (colliders[i] == collider)
		{
			delete colliders[i];
			colliders[i] = nullptr;
			return true;
		}
	}

	return false;
}

//void j1Collisions::Erase_Non_Player_Colliders()
//{
//	for (uint i = 0; i < MAX_COLLIDERS; ++i)
//	{
//		if (colliders[i] != nullptr && colliders[i]->type != COLLIDER_PLAYER)
//		{
//			delete colliders[i];
//			colliders[i] = nullptr;
//		}
//	}
//}
// -----------------------------------------------------

bool Collider::CheckCollision(const SDL_Rect& r) const
{
	if (r.y + r.h > rect.y - 2 && r.y < rect.y + rect.h && r.x + r.w >= rect.x  && r.x <= rect.x + rect.w)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool Collider::CheckCollisionDownwards(const SDL_Rect& r, float& gravity, float dt)
{
	if (r.y + r.h > rect.y - 2 && r.y < rect.y + rect.h && r.x + r.w >= rect.x  && r.x <= rect.x + rect.w)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool Collider::CheckCollisionForward(const SDL_Rect& r, float& force, float dt)
{
	if (r.y + r.h  > rect.y && r.y + r.h < rect.y + rect.h && r.x + r.w >= rect.x && r.x + r.w < rect.x + rect.w)
	{
		return true;

	}

	else
	{
		return false;
	}
}

bool Collider::CheckCollisionBackward(const SDL_Rect& r, float& force, float dt)
{
	if (r.y + r.h < rect.y + rect.h && r.y + r.h > rect.y && r.x >= rect.x + rect.w && r.x > rect.x)
	{
		return true;
	}

	else
	{
		return false;
	}
}