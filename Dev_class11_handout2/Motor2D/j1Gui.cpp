#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Gui.h"
#include "j1Collisions.h"
#include "Elements.h"

j1Gui::j1Gui() : j1Module()
{
	name.create("gui");
}

// Destructor
j1Gui::~j1Gui()
{}

// Called before render is available
bool j1Gui::Awake(pugi::xml_node& conf)
{
	LOG("Loading GUI atlas");
	bool ret = true;

	atlas_file_name = conf.child("atlas").attribute("file").as_string("");

	return ret;
}

// Called before the first frame
bool j1Gui::Start()
{
	atlas = App->tex->Load(atlas_file_name.GetString());

	return true;
}

// Update all guis
bool j1Gui::PreUpdate()
{
	for (uint i = 0; i < MAX_ELEMENTS; ++i)
	{
		if (queue[i].type != ELEMENT_TYPES::NO_TYPE)
		{
			if (queue[i].y * SCREEN_SIZE > App->render->camera.y)
			{

				LOG("Spawning enemy at %d", queue[i].y* SCREEN_SIZE);
				SpawnElement(queue[i]);
				queue[i].type = ELEMENT_TYPES::NO_TYPE;

			}
		}
	}
	return true;
}

bool j1Gui::Update()
{
	for (uint i = 0; i < MAX_ELEMENTS; ++i)
	{
		if (elements[i] != nullptr)
		{
			
		}
	}

	return true;
}

// Called after all Updates
bool j1Gui::PostUpdate()
{
	for (uint i = 0; i < MAX_ELEMENTS; ++i)
	{
		if (elements[i] != nullptr)
		{
			if ((abs((int)App->render->camera.y) + SCREEN_HEIGHT) < elements[i]->pos.y)
			{
				LOG("DeSpawning enemy at %d", elements[i]->pos.y * SCREEN_SIZE);
				delete elements[i];
				elements[i] = nullptr;
			}
		}
	}
	return true;
}

// Called before quitting
bool j1Gui::CleanUp()
{
	LOG("Freeing GUI");

	return true;
}

// const getter for atlas
const SDL_Texture* j1Gui::GetAtlas() const
{
	return atlas;
}

void j1Gui::SpawnElement(const ElementInfo& info)
{
	// find room for the new enemy
	uint i = 0;
	for (; elements[i] != nullptr && i < MAX_ELEMENTS; ++i);

	if (i != MAX_ELEMENTS)
	{
		switch (info.type)
		{
		
		}
	}
}

bool j1Gui::AddElement(ELEMENT_TYPES type, int x, int y)
{
	bool ret = false;

	for (uint i = 0; i < MAX_ELEMENTS; ++i)
	{
		if (queue[i].type == ELEMENT_TYPES::NO_TYPE)
		{
			queue[i].type = type;
			queue[i].x = x;
			queue[i].y = y;

			ret = true;
			break;
		}
	}

	return ret;
}

void j1Gui::OnCollision(Collider* c1, Collider* c2)
{

	for (uint i = 0; i < MAX_ELEMENTS; ++i)
	{
		if (elements[i] != nullptr && elements[i]->GetCollider() == c1)
		{
			
		}
	}

}
// class Gui ---------------------------------------------------

