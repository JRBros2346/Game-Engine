#pragma once

#include"defines.hpp"
#include<iostream>

namespace Yazh::Core::Logger {
#define LOG_WARN_ENABLED true
#define LOG_INFO_ENABLED true
#define LOG_DEBUG_ENABLED true
#define LOG_TRACE_ENABLED true

#if YRELEASE == 1
#	define LOG_DEBUG_ENABLED false
#	define LOG_TRACE_ENABLED false
#endif

	// FATAL, ERROR, WARN, INFO, DEBUG, TRACE
	enum class LogLevel {
		FTL,
		ERR,
		WRN,
		INF,
		DBG,
		TRC
	};
	static const char colors[6][6] = {
		"\033[41m", // Red Background 
		"\033[31m", // Red
		"\033[33m", // Yellow
		"\033[32m", // Green
		"\033[34m", // Blue
		"\033[37m"  // White
	};
	YAPI std::ostream& operator<<(std::ostream&, const LogLevel&);

	bool initialize();
	void shutdown();

	template<typename... Args>
	constexpr void logOutput(LogLevel, std::string, Args&&...);

	template<typename... Args>
	constexpr void Fatal(std::string, Args&&...);
	template<typename... Args>
	constexpr void Error(std::string, Args&&...);
	template<typename... Args>
	constexpr void Warn(std::string, Args&&...);
	template<typename... Args>
	constexpr void Info(std::string, Args&&...);
	template<typename... Args>
	constexpr void Debug(std::string, Args&&...);
	template<typename... Args>
	constexpr void Trace(std::string, Args&&...);
} // namespace Yazh::Core::Logger

#include"logger.tcc"
