// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#pragma once

// ============================================================================

#ifdef PLATFORM_LINUX
# define PLATFORM_NEWLINE "\n"
# define PLATFORM_SEPARATOR "/"
# define PLATFORM_TYPE PlatformType::Linux
# ifdef _LINUX64
#	define PLATFORM_64 1
#	define PLATFORM_ARCH ArchitectureType::x64
# else
#	define PLATFORM_64 0
#	define PLATFORM_ARCH ArchitectureType::x86
# endif
#endif
