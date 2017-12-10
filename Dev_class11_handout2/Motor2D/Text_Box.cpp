#include "j1App.h"
#include "j1Render.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Gui.h"
#include "Text_Box.h"


Text_Box::Text_Box(int x, int y, ELEMENT_TYPES types, const char* text) : Elements(x, y, types)
{
	if (text != nullptr)
	{
		boxtext = text;
		BoxText = App->font->Print(boxtext, { 88, 88, 88 }, App->gui->font);
	}

	Box = App->gui->box;
	App->tex->GetSize(Box, x_size, y_size);
}


Text_Box::~Text_Box()
{

}

void Text_Box::Draw()
{
	App->render->Blit(Box, pos.x, pos.y, 2.0f);
	if (!writing)
	{
		App->render->Blit(BoxText, pos.x + x_size / 2, pos.y + y_size / 2);
	}
}

void Text_Box::Write()
{
	int x, y;
	App->input->GetMousePosition(x, y);

	if (x > pos.x && x <pos.x + x_size && y>pos.y && y < pos.y + y_size)
	{
		if (App->input->GetMouseButtonDown(1) == KEY_DOWN)
		{
			writing = true; 
		}
	}

}