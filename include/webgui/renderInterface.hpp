#pragma 
#include <stdint.h>

namespace wg
{
	class RenderInterface
	{
	public:
		//Format of data is RGBA
		virtual uintptr_t CreateTexture(int width, int height, uint8_t* data) = 0;
		virtual void DeleteTexture(uintptr_t handle) = 0;
		virtual uintptr_t CreateBuffer(float* vertices) = 0;
		virtual void DeleteBuffer(uintptr_t handle) = 0;
		virtual void RenderBuffer(uintptr_t bhandle, uintptr_t thandle = 0) = 0;
	};
}