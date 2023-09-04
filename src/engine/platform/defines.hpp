// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#pragma once
#include <core/types/common.hpp>

// Overall system specific defines
// ============================================================================

// Platform detection
#ifdef PLATFORM_APPLE
# include <platform/unix/darwin/defines.hpp>
#elif defined(PLATFORM_WINDOWS)
# include <platform/win32/defines.hpp>
#elif defined(PLATFORM_LINUX)
# include <platform/unix/linux/defines.hpp>
#endif

