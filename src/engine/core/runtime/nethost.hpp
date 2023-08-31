// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================
// This file is a modified version of the original file from the .NET Core
// Runtime repository. The original file is licensed under the MIT license.
// See: https://github.com/dotnet/runtime/blob/main/src/native/corehost
// ============================================================================

#pragma once
#include "engine/core/types/common.hpp"

// ============================================================================

#ifdef PLATFORM_WINDOWS
# ifdef NETHOST_EXPORT
#	define NETHOST_API DLLEXPORT
# else
#	ifdef NETHOST_USE_AS_STATIC
#	 define NETHOST_API
#	else
#	 define NETHOST_API DLLIMPORT
#	endif
# endif
#else
# ifdef NETHOST_EXPORT
#	define NETHOST_API DLLEXPORT
# else
#	define NETHOST_API
# endif

# ifdef __cplusplus
extern "C" {
# endif

// ============================================================================

// Parameters for get_hostfxr_path
//
// Fields:
//   size
//     Size of the struct. This is used for versioning.
//
//   assembly_path
//     Path to the compenent's assembly.
//     If specified, hostfxr is located as if the assembly_path is the apphost
//
//   dotnet_root
//     Path to directory containing the dotnet executable.
//     If specified, hostfxr is located as if an application is started using
//     'dotnet app.dll', which means it will be searched for under the
//     dotnet_root path and the assembly_path is ignored.
//
struct getHostFXRParams {
	// Size of the struct as passed to the API
	size_t size;
	// Path to the component's assembly
	const char_t* assembly_path;
	// Path to directory containing the dotnet executable
	const char_t* dotnet_root;
};

//
// Get the path to the hostfxr library
//
// Parameters:
//   buffer
//     Buffer that will be populated with the hostfxr path, including a null
//     terminator.
//
//   buffer_size
//     [in] Size of buffer in char_t units.
//     [out] Size of buffer used in char_t units. If the input value is too
//     small
//           or buffer is nullptr, this is populated with the minimum required
//           size in char_t units for a buffer to hold the hostfxr path
//
//   getHostFXRParams
//     Optional. Parameters that modify the behaviour for locating the hostfxr
//     library. If nullptr, hostfxr is located using the enviroment variable or
//     global registration
//
// Return value:
//   0 on success, otherwise failure
//   0x80008098 - buffer is too small (HostApiBufferTooSmall)
//
// Remarks:
//   The full search for the hostfxr library is done on every call. To minimize
//   the need to call this function multiple times, pass a large buffer (e.g.
//   PATH_MAX).
//
NETHOST_API int get_hostfxr_path(
	char_t* buffer, size_t* buffer_size, const getHostFXRParams* parameters);

# ifdef __cplusplus
} // extern "C"
# endif
