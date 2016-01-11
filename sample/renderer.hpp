#pragma once
#include "../include/webgui/renderInterface.hpp"

class Renderer : public wg::RenderInterface
{
public:
	Renderer();
	void Clear();
	uintptr_t CreateFontAtlas(int width, int height, uint8_t* data);
	void DeleteFontAtlas(uintptr_t handle);
	uintptr_t CreateTexture(int width, int height, uint8_t* data);
	void DeleteTexture(uintptr_t handle);
	uintptr_t CreateBuffer(Vertex* vertices);
	void DeleteBuffer(uintptr_t handle);
	void RenderBuffer(uintptr_t bhandle, uintptr_t thandle = 0);
};