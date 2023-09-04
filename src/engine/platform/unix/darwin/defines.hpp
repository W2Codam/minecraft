// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#pragma once

// ============================================================================
// NOTE: 10.14 Mojave is the last version to support 32bit apps

#if PLATFORM_APPLE
	#define PLATFORM_64 1
	#define PLATFORM_TYPE Platform::Mac
	#define PLATFORM_SEPARATOR "/"
	#define PLATFORM_NEWLINE "\n"
	#if __aarch64__
		#define PLATFORM_ARCH Architecture::ARM64
	#else
		#define PLATFORM_ARCH Architecture::x64
	#endif
#endif
