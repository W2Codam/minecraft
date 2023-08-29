// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#pragma once

// ============================================================================
// NOTE: 10.14 Mojave is the last version to support 32bit apps

#ifdef PLATFORM_APPLE
	#define PLATFORM_64 1
	#define PLATFORM_TYPE PlatformType::Mac
	#define PLATFORM_SEPARATOR "/"
	#define PLATFORM_NEWLINE "\n"
	#if __aarch64__
		#define PLATFORM_ARCH ArchitectureType::ARM64
	#else
		#define PLATFORM_ARCH ArchitectureType::x64
	#endif
#endif
