#ifndef _MODULEIMGUI_H_
#define _MODULEIMGUI_H_
#include "Module.h"
#include "Globals.h"
#include "Application.h"
#include "SDL.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_sdl.h"


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
	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
};

#endif