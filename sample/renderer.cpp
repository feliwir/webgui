#include "renderer.hpp"
#include "flextGL.h"

Renderer::Renderer()
{
	flextInit();
}

void Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);
}

uintptr_t Renderer::CreateFontAtlas(int width, int height, uint8_t * data)
{
	GLuint handle = 0;
	glGenTextures(1, &handle);
	glBindTexture(GL_TEXTURE_2D, handle);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_R8,width, height, 0, GL_RED, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	return uintptr_t(handle);
}

void Renderer::DeleteFontAtlas(uintptr_t handle)
{
	glDeleteTextures(1, reinterpret_cast<GLuint*>(&handle));
}

uintptr_t Renderer::CreateTexture(int width, int height, uint8_t * data)
{
	GLuint handle = 0;
	glGenTextures(1, &handle);
	glBindTexture(GL_TEXTURE_2D, handle);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, width, height, 0, GL_ALPHA, GL_UNSIGNED_BYTE, data);
	return uintptr_t(handle);
}

void Renderer::DeleteTexture(uintptr_t handle)
{
	glDeleteTextures(1, reinterpret_cast<GLuint*>(&handle));
}

uintptr_t Renderer::CreateBuffer(Renderer::Vertex* vertices)
{
	GLuint handle = 0;
	glGenBuffers(1, &handle);
	return uintptr_t();
}

void Renderer::DeleteBuffer(uintptr_t handle)
{
}

void Renderer::RenderBuffer(uintptr_t bhandle, uintptr_t thandle)
{
}
