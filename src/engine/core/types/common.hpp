// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#pragma once

/** @brief The different supported platforms. */
enum class PlatformType {
	Windows,
	Linux,
	Apple,
};

/** @brief The different available architectures. */
enum class ArchitectureType {
	x86,
	x64,
	arm,
	arm64,
};


#ifdef __APPLE__
# define PLATFORM_APPLE 1
#elif defined(_WIN32) || defined(MSVC)
# define PLATFORM_WINDOWS 1
#elif defined(__linux__)
# define PLATFORM_LINUX 1
#else
# error "Unknown platform or not supported!"
#endif
#define PLATFORM_32 (!PLATFORM_64)
#include <cstddef>
#include <platform/compiler.hpp>
#include <platform/defines.hpp>

// Common types and definitions used throughout the engine and platforms.
// ============================================================================

using byte = unsigned char;

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

// Floating point
using f32 = float;
using f64 = double;

// Limits
#define U8_MIN ((u8) 0x00)
#define U16_MIN ((u16) 0x0000)
#define U32_MIN ((u32) 0x00000000)
#define U64_MIN ((u64) 0x0000000000000000)
#define U8_MAX ((u8) 0xff)
#define U16_MAX ((u16) 0xffff)
#define U32_MAX ((u32) 0xffffffff)
#define U64_MAX ((u64) 0xffffffffffffffff)

#define I8_MIN ((i8) -128)
#define I16_MIN ((i16) -32768)
#define I32_MIN -((i32) 2147483648)
#define I64_MIN -((i64) 9223372036854775808)
#define I8_MAX ((i8) 127)
#define I16_MAX ((i16) 32767)
#define I32_MAX ((i32) 2147483647)
#define I64_MAX ((i64) 9223372036854775807)

#define F32_MIN -(3.402823466e+38f)
#define F64_MIN -(1.7976931348623158e+308)
#define F32_MAX (3.402823466e+38f)
#define F64_MAX (1.7976931348623158e+308)

// Pointers
#ifdef PLATFORM_64
using intptr = i64;
using uintptr = u64;
constexpr const i32 PTR_SIZE = 8;
#else
using intptr = i32;
using uintptr = u32;
constexpr const i32 PTR_SIZE = 4;
#endif

#define UTF16(x) u##x
using utf16 = char16_t;
#define UTF8(x) u8##x
using utf8 = char8_t;
#define ANSI(x) x
using ansi = char;
