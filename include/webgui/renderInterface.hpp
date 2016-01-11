#pragma once
#include <stdint.h>
#include "visibility.hpp"

namespace wg
{
	class WG_API RenderInterface
	{
	public:
		struct Vertex
		{
			float x, y, u, v;
		};

		//Format of data is 8-bit Alphamask
		virtual uintptr_t CreateFontAtlas(int width, int height, uint8_t* data) = 0;
		virtual void DeleteFontAtlas(uintptr_t handle) = 0;
		//Format of data is RGBA
		virtual uintptr_t CreateTexture(int width, int height, uint8_t* data) = 0;
		virtual void DeleteTexture(uintptr_t handle) = 0;
		virtual uintptr_t CreateBuffer(Vertex* vertices) = 0;
		virtual void DeleteBuffer(uintptr_t handle) = 0;
		virtual void RenderBuffer(uintptr_t bhandle, uintptr_t thandle = 0) = 0;
	};
}