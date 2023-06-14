#pragma once

#include"defines.hpp"

#include"platform/platform_win32.cpp"
#include"platform/platform_linux.cpp"

namespace Yazh {
	class YAPI Application {
		static bool isRunning;
		static bool isSuspended;
		static Platform platform;
		static i16 width;
		static i16 height;
		static f64 last_time;
	
		public:
			// Application configuration.
			typedef struct {
				// Window starting position x axis. If applicable.
				i16 startPosX;
				
				// Window starting position y axis. If applicable.
				i16 startPosY;
				
				// Window starting width. If applicable.
				i16 startWidth;
				
				// Window starting height. If applicable.
				i16 startHeight;
				
				// The application name used in windowing. If applicable.
				char* name;
			} config;

			static bool initialized;
			
			bool create(config*);
			
			bool run();
	};
	bool Application::isRunning;
	bool Application::isSuspended;
	Platform Application::platform;
	i16 Application::width;
	i16 Application::height;
	f64 Application::last_time;
	
	bool Application::initialized = false;
} // namespace Yazh
