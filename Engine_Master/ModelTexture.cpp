#include "ModuleTexture.h"
#include "Globals.h"


ModuleTexture::ModuleTexture()
{

}

ModuleTexture::~ModuleTexture()
{

}

bool ModuleTexture::Init()
{
	if (ilGetInteger(IL_VERSION_NUM) < IL_VERSION) {
		printf("DevIL version is different...exiting!\n");
		return 1;
	}
	ilInit();
	ilGenImages(1, &ImageName);
	ilBindImage(ImageName);
	bool imageLoaded = ilLoadImage(IMAGE_NAME);
	ilEnable(IL_FILE_OVERWRITE);
	if (imageLoaded == true)
	{
		LOG("Image loaded");
		return true;
	}
	else {
		LOG("Image not loaded");
		return false;
	}
	ILubyte *Data = ilGetData();
	ILuint Width, Height;
	Width = ilGetInteger(IL_IMAGE_WIDTH);
	Height = ilGetInteger(IL_IMAGE_HEIGHT);
	glGenTextures(1, &ImageName);
	glBindTexture(GL_TEXTURE_2D, ImageName);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, Width, Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, Data);

	return true;
}

update_status ModuleTexture::PreUpdate()
{
	return UPDATE_CONTINUE;
}

update_status ModuleTexture::Update()
{
	return UPDATE_CONTINUE;
}

update_status ModuleTexture::PostUpdate()
{
	return UPDATE_CONTINUE;
}

bool ModuleTexture::CleanUp()
{
	ilDeleteImages(1, &ImageName);
	glDeleteTextures(1, &ImageName);
	return true;
}