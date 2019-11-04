#ifndef _MODULEIMGUI_H_
#define _MODULEIMGUI_H_
#include "Module.h"
#include "Globals.h"
#include "Application.h"
#include "SDL.h"


class ModuleImgui : public Module
{
public:
	ModuleImgui();
	~ModuleImgui();

	bool Init();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	SDL_GLContext imguiglcontext;
};

#endif