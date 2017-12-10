#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Gui.h"
#include "Button.h"


Button::Button(int x, int y, ELEMENT_TYPES types, const char* text) : Elements(x, y, types)
{
	if (text != nullptr)
	{
		buttontext = text;
		ButtonText = App->font->Print(buttontext, { 255, 255, 0 }, App->gui->font);
	}

	ButtonBox = App->gui->button;
	App->tex->GetSize(ButtonBox, x_size, y_size);
}


Button::~Button()
{

}

void Button::Draw()
{
	App->render->Blit(ButtonBox, pos.x , pos.y, 2.0f);
	App->render->Blit(ButtonText, pos.x + x_size / 2, pos.y + y_size / 2);

}