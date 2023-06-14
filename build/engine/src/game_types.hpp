#pragma once

#include"core/application.hpp"

/**
 * Represents the basic game state in a game.
 * Called for creation in the application.
 */
namespace Yazh::Game {
	class _Game {
		// The application configuration.
		Application::config appConfig;
		
		public:
			// Virtual function to game's initialize function.
			virtual bool initialize() { return nullptr; } ;
			
			// Virtual function to game's update function.
			virtual bool update(f32 deltaTime) { return nullptr; };
			
			// Virtual function to game's render function.
			virtual bool render(f32 deltaTime) { return nullptr; } ;
			
			// Virtual function to handle resizes, If applicable.
			virtual void onResize(u32 width, u32 height) {};
	};
} // namespace Yazh