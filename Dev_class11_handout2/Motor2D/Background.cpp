#include "Background.h"
#include "Elements.h"


Background::Background(int x, int y) : Elements(x, y)
{
	sprites = App->tex->Load("gui/login_background.png");
}


Background::~Background()
{
}
