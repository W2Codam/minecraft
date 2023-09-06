// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#pragma once
#include <windows.h>
#include <core/types/common.hpp>
#include <platform/base/file_base.hpp>

// ============================================================================

namespace core::filesystem {

/**
 * @brief File class for reading and writing files.
 * TODO: Implement this class.
 */
class File : public AFileBase {
private:
	HANDLE m_handle;
};

} // namespace Core
