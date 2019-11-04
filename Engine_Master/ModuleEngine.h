#ifndef _MODULEENGINE_H_
#define _MODULEENGINE_H_

#include "Module.h"
#include "il.h"
#include "glew/include/GL/glew.h"
#include "MathGeoLib/include/Math/float4x4.h"


class ModuleEngine:public Module {

	public:

		ModuleEngine();
		~ModuleEngine();

		bool Init();
		update_status PreUpdate();
		update_status Update();
		update_status PostUpdate();
		bool CleanUp();
		float4x4 proj;
		float4x4 model;
		float4x4 view;
		
	private:
		GLuint vbo;
		GLuint ebo;
		
};


#endif