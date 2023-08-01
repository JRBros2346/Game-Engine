#pragma once

#include"defines.hpp"
#include"platform.hpp"

#if YPLATFORM_WINDOWS
#	include<windows.h>
#	include<windowsx.h> // param input extraction

namespace Yazh {
	class YAPI Platform : VirtualPlatform {
		static LRESULT CALLBACK Win32ProcessMessage(HWND, u32, WPARAM, LPARAM);
		
		HINSTANCE hInstance;
		HWND hWnd;
		static DWORD dwPrevOutMode;

		public:
			// Clock
			static f64 clock_frequency;
			static LARGE_INTEGER start_time;

			bool startup(const char*, i32, i32, i32, i32);
			void shutdown();
			bool pumpMessages();

			static void* allocate(ysize, bool);
			static void free(void*, ysize, bool);
			static void* zeroMemory(void*, ysize);
			static void* copyMemory(void*, const void*, ysize);
			static void* setMemory(void*, i32, ysize);
	};
} // namespace Yazh

#endif // YPLATFORM_WINDOWS
