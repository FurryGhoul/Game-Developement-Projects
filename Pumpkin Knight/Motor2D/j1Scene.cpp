#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1Scene.h"
#include "j1Pathfinding.h"
#include "j1EntityManager.h"
#include "Element.h"
#include "Button.h"
#include "j1Gui.h"
#include "Brofiler\Brofiler.h"

using namespace pugi;

j1Scene::j1Scene() : j1Module()
{
	name.create("scene");
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake(pugi::xml_node& config)
{
	LOG("Loading Scene");
	bool ret = true;
	start = true; 
	level1 = false;
	level2 = false;
	credits = false;

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	if (start)
	{
		App->gui->AddBackground(-500, 180, BACKGROUND, { 0,0,1024,768 });

		rect_quit = { 102, 3151, 365, 185 };
		QuitButton = App->gui->AddButton(-400, 280, BUTTON, &rect_quit);
		rect_start = { 484, 3151, 365, 185 };
		StartButton = App->gui->AddButton(-400, 380, BUTTON, &rect_start);
		rect_options = { 868, 3151, 365, 185 };
		Options = App->gui->AddButton(-400, 480, BUTTON, &rect_options);
		rect_credits = { 1256, 3151, 365, 185 };
		Credits = App->gui->AddButton(-400, 580, BUTTON, &rect_credits);

		rect_window = { 1187, 0, 1113, 848 };
		BigWindow = App->gui->AddWindow(-300, 180, WINDOW, &rect_window);

		App->audio->PlayMusic("audio/music/Spooky Scary Skeletons.ogg");
	}

	if (credits)
	{
		App->gui->AddBackground(-500, 180, BACKGROUND, { 0,0,1024,768 });

		rect_window = { 1187, 0, 1113, 848 };
		BigWindow = App->gui->AddWindow(-300, 180, WINDOW, &rect_window);

	}

	if (level1) 
	{
		App->map->Load("level1_v4.tmx");
		App->entity_manager->AddEnemy(WOLF, 1300, 0);
	//	App->entity_manager->AddEnemy(BAT, 500, 100);
		App->entity_manager->AddEnemy(WOLF, 5000, 0);
	}


	if (level2)
	{
		App->map->Load("level2_v2.tmx");
		App->entity_manager->AddEnemy(WOLF, 1000, 0);
		App->entity_manager->AddEnemy(BAT, 1300, 450);
	}

	
	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{
	BROFILER_CATEGORY("PreUpdate Scene", Profiler::Color::Yellow)

	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{


	
	BROFILER_CATEGORY("Update Scene", Profiler::Color::Green)

	if(App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
		App->render->camera.y += 200.0f * dt;

	if(App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
		App->render->camera.y -= 200.0f * dt;

	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
		App->render->camera.x += 200.0f * dt;

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
		App->render->camera.x -= 200.0f * dt;

	if (App->input->GetKey(SDL_SCANCODE_F1)) 
	{
		if (level1 == false) 
		{
			start = false;
			App->map->CleanUp();
			App->gui->CleanUp();
			App->entity_manager->CleanUp();
			App->collisions->Erase_Non_Player_Colliders();
			App->map->Load("level1_v4.tmx");			
			
				if (App->entity_manager->player_entity == nullptr)
				{
					App->entity_manager->player_entity = new Player(100, 200);
					App->entity_manager->player_entity->Awake(App->entity_manager->entity_config);
					App->entity_manager->player_entity->Start();
				}
			}
			App->audio->PlayMusic("audio/music/Darkness.ogg");
			level1 = true;
		}
		else
		{
			//App->entity_manager->player_entity->SetPos(100, 250);
		}
	
	if (App->input->GetKey(SDL_SCANCODE_F2))
	{
		App->entity_manager->player_entity->SetPos(100, 250);
	}
	if (App->input->GetKey(SDL_SCANCODE_F5))
		App->SaveGame();
	
	if (App->input->GetKey(SDL_SCANCODE_F6))
		App->LoadGame();

	//CHANGE LEVEL
	if (level1)
	{
		if (App->entity_manager->player_entity->getX() >= 6200.f)

		{
			level2 = true;
			App->map->CleanUp();
			App->entity_manager->CleanUp();
			App->collisions->Erase_Non_Player_Colliders();
			App->map->Load("level2_v2.tmx");
			App->entity_manager->player_entity->SetPos(100, 250);
			level1 = false;
		}
	}
	

	//App->render->Blit(img, 0, 0);
	App->map->Draw();
	

	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	BROFILER_CATEGORY("PostUpdate Scene", Profiler::Color::Blue)

	if(App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		exit = false;

	return exit;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}

bool j1Scene::MouseEvents(Element* element)

{
	switch (element->event_type)
	{
	case MOUSE_ENTER:
		if (element == StartButton)
		{
		}
		if (element == QuitButton)
		{
		}
		if (element == Options)
		{
		}
		if (element == Credits)
		{
		}
		break;
	case MOUSE_EXIT:
		if (element == StartButton)
		{
		}
		if (element == QuitButton)
		{
		}
		if (element == Options)
		{
		}
		if (element == Credits)
		{
		}
		break;
	case MOUSE_CLICK:
		if (element == StartButton)
		{
		}
		if (element == QuitButton)
		{
		}
		if (element == Options)
		{
		}
		if (element == Credits)
		{
		}
		break;
	case MOUSE_STOP_CLICK:
		if (element == StartButton)
		{
			if (level1 == false)
			{
				start = false;
				App->map->CleanUp();
				App->gui->CleanUp();
				App->entity_manager->CleanUp();
				App->collisions->Erase_Non_Player_Colliders();
				App->map->Load("level1_v4.tmx");

				if (App->entity_manager->player_entity == nullptr)
				{
					App->entity_manager->player_entity = new Player(100, 200);
					App->entity_manager->player_entity->Awake(App->entity_manager->entity_config);
					App->entity_manager->player_entity->Start();
				}
			}
			App->audio->PlayMusic("audio/music/Darkness.ogg");
			level1 = true;
		}
		if (element == QuitButton)
		{
			/*LOG("CY@");
			exit = false;*/
		}
		if (element == Options)
		{
		}
		if (element == Credits)
		{
		}
		break;

	}

	return true;
}

