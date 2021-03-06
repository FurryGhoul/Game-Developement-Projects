#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Gui.h"
#include "Elements.h"
#include "Background.h"
#include "Button.h"
#include "Text.h"
#include "Text_Box.h"

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

	background = App->tex->Load("gui/background.png");
	button = App->tex->Load("gui/button_panel.png");
	box = App->tex->Load("gui/text_box.png");

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
	p2List_item<Elements*>* element = elements.start;
	
	while (element != nullptr)
	{
		element->data->Draw();
		if (MouseCollision(element->data))
		{

		}
		element = element->next;
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

SDL_Texture* j1Gui::GetBackground() const
{
	return background;
}

SDL_Texture* j1Gui::GetButton() const
{
	return button;
}


void j1Gui::AddBackground(int x, int y, ELEMENT_TYPES types)
{
	Elements* element = new Background(x, y, types);
	elements.add(element);
}

void j1Gui::AddButton(int x, int y, ELEMENT_TYPES types, const char* text)
{
	Elements* element = new Button(x, y, types, text);
	elements.add(element);
}

void j1Gui::AddText(int x, int y, ELEMENT_TYPES types, const char* text)
{
	Elements* element = new Text(x, y, types, text);
	elements.add(element);
}

void j1Gui::AddTextBox(int x, int y, ELEMENT_TYPES types, const char* text)
{
	Elements* element = new Text_Box(x, y, types, text);
	elements.add(element);
}

bool j1Gui::MouseCollision(Elements* element)
{
	bool ret = false;
	int x, y;

	App->input->GetMousePosition(x, y);

	if (x > element->pos.x && x < element->pos.x + element->x_size && y > element->pos.y && y < element->pos.y + element->y_size)
	{
		ret = true;
	}

	return ret;
}
// class Gui ---------------------------------------------------

