// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#pragma once

// Compiler specific defines and macros
// ============================================================================

#if defined(__clang__)
# define IS_CLANG
# define STDCALL __attribute__((stdcall))
# define CDECL __attribute__((cdecl))
# define RESTRICT __restrict__
# define INLINE inline
# define FORCE_INLINE inline
# define FORCE_NOINLINE __attribute__((noinline))
# define NO_RETURN __attribute__((noreturn))
# define DEPRECATED [[deprecated]]
# define DLLEXPORT __attribute__((__visibility__("default")))
# define DLLIMPORT
#elif defined(__GNUC__)
# define IS_GCC
# define STDCALL __attribute__((stdcall))
# define CDECL __attribute__((cdecl))
# define RESTRICT __restrict__
# define INLINE inline
# define FORCE_INLINE inline
# define FORCE_NOINLINE __attribute__((noinline))
# define NO_RETURN __attribute__((noreturn))
# define DEPRECATED __attribute__((deprecated))
# define DLLEXPORT __attribute__((__visibility__("default")))
# define DLLIMPORT
#elif defined(_MSC_VER)
# define IS_MSVC
# if _MSC_VER < 1920
#	error "Please use Visual Studio 2019 or later"
# endif
# define STDCALL __stdcall
# define CDECL __cdecl
# define RESTRICT __restrict
# define INLINE __forceinline
# define FORCE_INLINE __forceinline
# define FORCE_NOINLINE __declspec(noinline)
# define NO_RETURN __declspec(noreturn)
# define DEPRECATED __declspec(deprecated)
# define DLLEXPORT __declspec(dllexport)
# define DLLIMPORT __declspec(dllimport)
#else
# error "Unsupported compiler"
#endif
