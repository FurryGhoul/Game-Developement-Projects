#ifndef __j1GUI_H__
#define __j1GUI_H__

#define CURSOR_WIDTH 2

#include "p2List.h"
#include "p2Log.h"
#include "j1Module.h"
#include "p2DynArray.h"


// TODO 1: Create your structure of classes
enum ElementType
{
	BACKGROUND,
	WINDOW,
	BUTTON,
	TEXT,
	NOTYPE,
};

enum UIEvents
{
	MOUSE_ENTER,
	MOUSE_EXIT,
	MOUSE_CLICK,
	MOUSE_STOP_CLICK
};

class Element;
struct SDL_Texture;
struct SDL_Rect;
struct _TTF_Font;

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

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	// TODO 2: Create the factory methods
	// Gui creation functions
	bool MouseCollision(Element* element);

	//void MouseEvent(Element* element);

	void AddBackground(int x, int y, ElementType type, SDL_Rect rec);
	Element* AddButton(int x, int y, ElementType type, SDL_Rect* TexRect, const char* text = nullptr);
	Element* AddText(int x, int y, ElementType type, const char* text);
	Element* AddWindow(int x, int y, ElementType type, SDL_Rect* rec);

public:

	SDL_Texture* GetAtlas() const;
	SDL_Texture* GetBackground() const;
	SDL_Texture* GetButton() const;

	p2List<Element*> elements;
	p2DynArray<_TTF_Font*> fonts;

	SDL_Texture* button = nullptr;
	SDL_Texture* box = nullptr;
	_TTF_Font* font = nullptr;

private:

	SDL_Texture* background = nullptr;
	SDL_Texture* atlas;
	p2SString atlas_file_name;
};

#endif // __j1GUI_H__