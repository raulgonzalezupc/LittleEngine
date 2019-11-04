#ifndef _MODULETEXTURE_H_
#define _MODULETEXTURE_H_
#include "Globals.h"
#include "Module.h"
#include "il.h"
#include "glew/include/GL/glew.h"

class ModuleTexture : public Module {
public:
	ModuleTexture();
	~ModuleTexture();

	bool Init();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

public:
	ILuint ImageName;
};

#endif