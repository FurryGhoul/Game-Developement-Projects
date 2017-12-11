#include "Button.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Window.h"
#include "j1Fonts.h"
#include "j1Gui.h"

Button::Button(int x, int y, ElementType types, SDL_Rect* TexRect, const char* text) : Element(x, y, types)
{
	if (text != nullptr)
	{
		buttontext = text;
		ButtonText = App->font->Print(buttontext, { 255, 255, 0 }, App->gui->font);
	}

	texture_rect = TexRect;

	ButtonBox = App->gui->GetAtlas();
	tex_width = texture_rect->w;
	tex_height = texture_rect->h;
}


Button::~Button()
{

}

void Button::Draw()
{
	App->render->Blit(ButtonBox, pos.x, pos.y, 0.5f, 0.5f, false, texture_rect);
	App->render->Blit(ButtonText, pos.x + tex_width / 2, pos.y + tex_height / 2, 1, 1, false);

}
