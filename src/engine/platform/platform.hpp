// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#pragma once
#include <platform/defines.hpp>

// ============================================================================

#if PLATFORM_WINDOWS
# include <windows.h>
#elif defined(PLATFORM_LINUX) || defined(PLATFORM_APPLE)
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#endif
