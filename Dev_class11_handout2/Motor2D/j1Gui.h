#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"

#define SCREEN_SIZE 1
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define CURSOR_WIDTH 2
#define MAX_ELEMENTS 1000

// TODO 1: Create your structure of classes

enum ELEMENT_TYPES
{
	TEXT_BOX,
	BUTTON,
	IMAGE,
	BACKGROUND,
	TEXT,
	NO_TYPE
};

class Elements;

struct ElementInfo
{
	ELEMENT_TYPES type = ELEMENT_TYPES::NO_TYPE;
	int x, y;
};

// ---------------------------------------------------
class j1Gui : public j1Module
{
public:

	j1Gui();

	// Destructor
	virtual ~j1Gui();

	// Called when before render is available
	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	bool Update(float dt);

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	void SpawnElement(const ElementInfo& info);

	bool AddElement(ELEMENT_TYPES type, int x, int y);

	//void OnCollision(Collider* c1, Collider* c2);
	// TODO 2: Create the factory methods
	// Gui creation functions

	const SDL_Texture* GetAtlas() const;
	ElementInfo queue[MAX_ELEMENTS];
	Elements* elements[MAX_ELEMENTS];

private:

	
	SDL_Texture* atlas;
	p2SString atlas_file_name;
};

#endif // __j1GUI_H__