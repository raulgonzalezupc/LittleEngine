#include "ModuleProgram.h"
#include "Application.h"
#include "Globals.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "SDL.h"

ModuleProgram::ModuleProgram()
{

}

ModuleProgram::~ModuleProgram()
{

}

bool ModuleProgram::Init()
{
	//init vertex shader
	const char *vertex_shader_file = loadFile(VERTEX_SHADER_PATH);
	vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex_shader, 1, &vertex_shader_file, NULL);
	delete vertex_shader_file;
	glCompileShader(vertex_shader);

	//init fragment shader
	const char *fragment_shader_file = loadFile(FRAGMENT_SHADER_PATH);
	fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment_shader, 1, &fragment_shader_file, NULL);
	delete fragment_shader_file;
	glCompileShader(fragment_shader);

	int check = NULL;
	char checkok[512];
	glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &check);
	if (!check) {
		glGetShaderInfoLog(fragment_shader, 512, NULL, checkok);
		LOG("error compilando shader");
		LOG(checkok);
	}
	//Creating shader program
	shader_program = glCreateProgram();

	//Attaching vertex shader to shader program
	glAttachShader(shader_program, vertex_shader);

	//Attaching fragment shader to shader program
	glAttachShader(shader_program, fragment_shader);

	//Linking shader program
	glLinkProgram(shader_program);
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
	return true;
}

update_status ModuleProgram::PreUpdate()
{
	return UPDATE_CONTINUE;
}

update_status ModuleProgram::Update()
{
	

	return UPDATE_CONTINUE;
}

update_status ModuleProgram::PostUpdate()
{
	return UPDATE_CONTINUE;
}

bool ModuleProgram::CleanUp()
{
	LOG("Deleting vertex shader");
	glDeleteShader(vertex_shader);

	LOG("Deleting fragment shader");
	glDeleteShader(fragment_shader);
	return true;
}
const char* ModuleProgram::loadFile(const char* file_name)
{
	char* data = nullptr;
	FILE* file = nullptr;
	fopen_s(&file, file_name, "rb");
	if (file)
	{
		fseek(file, 0, SEEK_END);
		int size = ftell(file);
		rewind(file);
		data = (char*)malloc(size + 1);
		fread(data, 1, size, file);
		data[size] = 0;
		fclose(file);
	}

	return data;
}