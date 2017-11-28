#include "j1Module.h"
#include "Elements.h"
#include "j1Gui.h"
#include "j1Textures.h"



Elements::Elements(int x, int y) : pos(x, y), original_pos(x, y), collider_pos(0, 0)
{

}

//bool Elements::Awake(pugi::xml_node& entity)
//{
//	Awake(entity);
//
//	return true;
//}

Elements::~Elements()
{
	if (collider != nullptr)
		collider->to_delete = true;
}

const Collider* Elements::GetCollider() const
{
	return collider;
}

void Elements::Draw(SDL_Texture* sprite)
{
	if (collider != nullptr)
	{
		collider->SetPos(pos.x, pos.y);
	}

	SDL_Rect r = { pos.x, pos.y, 1920, 1080 };
	sprite = sprites;
	App->render->Blit(sprite, pos.x, pos.y, &r);
}

void Elements::OnCollision(Collider* collider)
{

}
