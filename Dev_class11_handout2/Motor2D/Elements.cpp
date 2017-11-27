#include "j1Module.h"
#include "Elements.h"
#include "j1Gui.h"
#include "j1Textures.h"



Elements::Elements(int x, int y) : pos(x, y), original_pos(x, y), collider_pos(0, 0)
{

}

bool Elements::Awake(pugi::xml_node& entity)
{
	Awake(entity);

	return true;
}

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


	/*for (int i = 0; App->entity_manager->entities[i]; ++i)
	{
	App->entity_manager->entities[i]->collider->SetPos(App->entity_manager->entities[i]->pos.x, App->entity_manager->entities[i]->pos.y);
	App->render->Blit(App->entity_manager->entities[i]->texture, App->entity_manager->entities[i]->pos.x, App->entity_manager->entities[i]->pos.y, 1, 1, false, &App->entity_manager->entities[i]->animation->GetCurrentFrame());
	}*/
}

void Elements::OnCollision(Collider* collider)
{

}
