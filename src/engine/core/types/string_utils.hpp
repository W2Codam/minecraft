
// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#pragma once
#include <core/types/common.hpp>
#include <core/types/string.hpp>

using namespace core;

// ============================================================================

namespace core::utils {

/**
 * @brief Converts a UTF-8 string to UTF-16 string.
 * 
 * @param src The UTF-8 string.
 * @param srcLen The length of the UTF-8 string.
 * @param dst The UTF-16 string.
 * @return size_t The length of the UTF-16 string.
 */
size_t UTF8ToUTF16(const utf8* src, size_t srcLen, utf16* dst) noexcept;

/**
 * @brief Converts a UTF-16 string to UTF-8 string.
 * 
 * @param src The UTF-16 string.
 * @param srcLen The length of the UTF-16 string.
 * @param dst The UTF-8 string.
 * @return size_t The length of the UTF-8 string.
 */
size_t UTF16ToUTF8(const utf16* src, size_t srcLen, utf8* dst) noexcept;

}
