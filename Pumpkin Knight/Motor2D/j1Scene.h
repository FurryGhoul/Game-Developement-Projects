#ifndef __j1SCENE_H__
#define __j1SCENE_H__

#include "j1Module.h"
#include "p2DynArray.h"
#include "p2Point.h"

class Element;
struct SDL_Texture;
struct SDL_Rect;

class j1Scene : public j1Module
{
public:

	j1Scene();

	// Destructor
	virtual ~j1Scene();

	// Called before render is available
	bool Awake(pugi::xml_node&);

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	bool MouseEvents(Element* element);

	p2DynArray<iPoint> path;

	bool start = true;

private:

	bool exit = true;
	bool level1 = false;
	bool level2 = false;
	bool credits = false;

	SDL_Rect rect_start;
	SDL_Rect rect_quit;
	SDL_Rect rect_options;
	SDL_Rect rect_credits;
	SDL_Rect rect_window;

	Element* StartButton =  nullptr;
	Element* QuitButton = nullptr;
	Element* Options = nullptr;
	Element* Credits = nullptr;
	Element* BigWindow = nullptr;
};

#endif // __j1SCENE_H__