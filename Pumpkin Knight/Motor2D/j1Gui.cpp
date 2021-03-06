#include "j1Gui.h"
#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Scene.h"
#include "Element.h"
#include "Background.h"
#include "Button.h"
#include "Text.h"
#include "Window.h"

//#include "Text_Box.h"

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

	background = App->tex->Load("gui/MenuBackground.png");

	fonts.PushBack(App->font->Load("fonts/wow/ARIALN.ttf", 20));

	font = App->font->Load("fonts/wow/ARIALN.ttf", 20);
	return true;
}

// Update all guis
bool j1Gui::PreUpdate()
{

	return true;
}

// Called after all Updates
bool j1Gui::PostUpdate()
{
	p2List_item<Element*>* element = elements.start;

	while (element != nullptr)
	{
		element->data->Draw();
		if (MouseCollision(element->data))
		{
			element->data->mouse_in = true;
			element->data->mouse_out = false;
			element->data->event_type = MOUSE_ENTER;
			App->scene->MouseEvents(element->data);

			if (App->input->GetMouseButtonDown(1) == KEY_DOWN)
			{
				element->data->event_type = MOUSE_CLICK;
				App->scene->MouseEvents(element->data);
			}

			if (App->input->GetMouseButtonDown(1) == KEY_UP)
			{
				element->data->event_type = MOUSE_STOP_CLICK;
				App->scene->MouseEvents(element->data);
			}
		}

		element = element->next;
	}

	return true;
}

// Called before quitting
bool j1Gui::CleanUp()
{
	LOG("Freeing GUI");

	p2List_item<Element*>* item;
	item = elements.start;
	while (item != NULL)
	{
		RELEASE(item->data);
		item = item->next;
	}
	elements.clear();

	return true;
}

// const getter for atlas
SDL_Texture* j1Gui::GetAtlas() const
{
	return atlas;
}

SDL_Texture* j1Gui::GetBackground() const
{
	return background;
}

SDL_Texture* j1Gui::GetButton() const
{
	return button;
}


void j1Gui::AddBackground(int x, int y, ElementType type, SDL_Rect rec)
{
	Element* elem = new Background(x, y, type, rec);
	elements.add(elem);
}

Element* j1Gui::AddButton(int x, int y, ElementType type, SDL_Rect* TexRect, const char* text)
{
	Element* elem = new Button(x, y, type, TexRect, text);
	elements.add(elem);

	return elem;
}

Element* j1Gui::AddText(int x, int y, ElementType type, const char* text)
{
	Element* elem = new Text(x, y, type, text);
	elements.add(elem);

	return elem;
}

Element* j1Gui::AddWindow(int x, int y, ElementType type, SDL_Rect* rec)
{
	Element* elem = new Window(x, y, type, rec);
	elements.add(elem);

	return elem;
}

bool j1Gui::MouseCollision(Element* element)
{
	
	bool ret = false;
	if (element->type == BUTTON)
	{
		int x, y;
		App->input->GetMousePosition(x, y);

		int posx = element->pos.x + App->render->camera.x;
		int posy = element->pos.y + App->render->camera.y;

		if (x > posx && x < posx + element->tex_width*0.5f
			&& y > posy && y < posy + element->tex_height*0.5f)
		{
			ret = true;
		}
	}
	return ret;
}