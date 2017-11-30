#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Gui.h"
#include "Text.h"


Text::Text(int x, int y, ELEMENT_TYPES types, const char* text) : Elements(x, y, types)
{
	if (text != nullptr)
	{
		this->text = text;
		Text_tex = App->font->Print(text, { 255, 255, 0 }, App->gui->font);
	}

}


Text::~Text()
{

}

void Text::Draw()
{
	App->render->Blit(Text_tex, pos.x, pos.y);
}