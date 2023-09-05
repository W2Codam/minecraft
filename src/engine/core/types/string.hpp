// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#pragma once
#include <iostream>
#include <core/collections/array.hpp>
#include <core/types/common.hpp>

// ============================================================================

namespace core {

template <typename T>
class StringBase {
public:
	inline const T* get(void) const {
		return m_data;
	}

	inline size_t length(void) const {
		return m_length;
	}

protected:
	T* m_data = nullptr;
	size_t m_length = 0;
};

// ============================================================================

/**
 * @brief A UTF-8 string.
 *
 * @note This is a typedef for StringBase<utf8>.
 */
class String : public StringBase<utf8> {
public:
	String(const utf8* str) {
		// TODO: Copy the string.
		this->m_data = const_cast<utf8*>(str);
	}

	String(const char* str) {
	}
};

inline std::ostream& operator<<(std::ostream& os, const String& str) {
	return os << (unsigned char *)str.get();
}

// ============================================================================

/**
 * @brief A UTF-16 string.
 *
 * @note This is a typedef for StringBase<utf16>.
 */
class StringU16 : public StringBase<utf16> {
public:
	StringU16(const utf16* str) {
		// TODO: Copy the string.
		this->m_data = const_cast<utf16*>(str);
	}

	StringU16(const char* str) {
	};
};

inline std::wostream& operator<<(std::wostream& os, const StringU16& str) {
	printf("%s\n", (char *)str.get());
	return os;
}

} // namespace core
