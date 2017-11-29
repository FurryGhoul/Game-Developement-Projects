#include "j1App.h"
#include "j1Render.h"
#include "j1Gui.h"
#include "Background.h"


Background::Background(int x, int y, ELEMENT_TYPES types) : Elements(x, y, types)
{
}


Background::~Background()
{
}

void Background::Draw()
{
	App->render->Blit(App->gui->GetBackground(), pos.x, pos.y);
}
