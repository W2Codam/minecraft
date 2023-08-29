// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#pragma once
#include "engine/core/compiler.hpp"

// Common types and definitions used throughout the engine and platforms.
// ============================================================================

// Unsigned
using u8 = unsigned char;
using u16 = unsigned short;
using u32 = unsigned int;
using u64 = unsigned long long;

// Signed
using i8 = signed char;
using i16 = signed short;
using i32 = signed int;
using i64 = signed long long;

// Misc
using byte = u8;
using intptr = i64;
using uintptr = u64;
constexpr const i32 PTR_SIZE = 8;
#ifndef PLATFORM_WINDOWS
using char_t = wchar_t;
# define TEXT(x) L##x
#elif defined(PLATFORM_UTF16)
using char_t = char16_t;
# define TEXT(x) u##x
#else
using char_t = char;
# define TEXT(x) u8##x
#endif
