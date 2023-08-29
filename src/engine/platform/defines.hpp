// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#pragma once

// ============================================================================

/** @brief The different supported platforms. */
enum class Platform {
	Windows,
	Linux,
	Apple,
};

/** @brief The different available architectures. */
enum class Architecture {
	x86,
	x64,
	arm,
	arm64,
};

#ifndef EXIT_SUCCESS
# define EXIT_SUCCESS 0
#endif
#ifndef EXIT_FAILURE
# define EXIT_FAILURE 1
#endif

// Platform detection
#ifdef __APPLE__
# define PLATFORM_APPLE 1
# define PLATFORM_LINUX 0
# define PLATFORM_WINDOWS 0
# include "darwin/defines.hpp"
#elif defined(_WIN32) && defined(MSVC)
# define PLATFORM_APPLE 0
# define PLATFORM_LINUX 0
# define PLATFORM_WINDOWS 1
# include "windows/defines.hpp"
#elif defined(__linux__)
# define PLATFORM_APPLE 0
# define PLATFORM_LINUX 1
# define PLATFORM_WINDOWS 0
# include "linux/defines.hpp"
#else
# error "Unknown platform or not supported!"
#endif
#define PLATFORM_32 (!PLATFORM_64)
