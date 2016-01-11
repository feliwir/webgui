#pragma once

#ifndef WEBGUI_STATIC
#if defined(_WIN32) && defined(_MSC_VER)
	#ifdef webgui_EXPORTS
	/** From DLL side, we must export
	*/
	#define WG_API __declspec(dllexport)
	#else
	/** From client application side, we must import
	*/
	#define WG_API __declspec(dllimport)
#endif
#else
#define WG_API
#endif
#else

#define WG_API
#endif