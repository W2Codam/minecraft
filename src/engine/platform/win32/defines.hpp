// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#pragma once

// ============================================================================

#if PLATFORM_WINDOWS
# define PLATFORM_NEWLINE "\r\n"
# define PLATFORM_SEPARATOR "\\"
# define PLATFORM_TYPE PlatformType::Windows
# ifdef _WIN64 || defined(__WIN64__) || defined(_M_X64)
#	define PLATFORM_64 1
#	define PLATFORM_ARCH ArchitectureType::x64
# else
#	define PLATFORM_64 0
#	define PLATFORM_ARCH ArchitectureType::x86
# endif
#endif
