#ifndef _MODULESHADERS_H_
#define _MODULESHADERS_H_

#include "Module.h"
#include "Globals.h"
#include "glew/include/GL/glew.h"

class ModuleProgram :public Module {

public:

	ModuleProgram();
	~ModuleProgram();

	bool Init();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();
	GLuint shader_program;
private:
	const char* loadFile(const char* file_name);
	GLuint vertex_shader;
	GLuint fragment_shader;
	
};


#endif