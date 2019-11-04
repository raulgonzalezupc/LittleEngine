#pragma once

#include<list>
#include "Globals.h"
#include "Module.h"

class ModuleRender;
class ModuleWindow;
class ModuleTextures;
class ModuleInput;
class ModuleEngine;
class ModuleProgram;
class ModuleTexture;
class ModuleImgui;

class Application
{
public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

public:
	ModuleRender* renderer = nullptr;
	ModuleWindow* window = nullptr;
	ModuleInput* input = nullptr;
	ModuleEngine* engine = nullptr;
	ModuleProgram* shaders = nullptr;
	ModuleTexture* texture = nullptr;
	ModuleImgui* imgui = nullptr;

private:

	std::list<Module*> modules;

};

extern Application* App;
