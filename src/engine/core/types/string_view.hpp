// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#pragma once
#include <core/types/common.hpp>
#include <core/types/string.hpp>

// ============================================================================

namespace core {

/**
 * @brief A view of a string.
 *
 * @tparam T The type of the string.
 */
template <typename T>
class StringViewBase {
protected:
	const T* m_data;
	size_t m_length;

	constexpr StringViewBase() : m_data(nullptr), m_length(0) {
	}

	constexpr StringViewBase(const T* data, size_t length)
		: m_data(data), m_length(length) {
	}

public:
	FORCE_INLINE const T& operator[](size_t index) const {
		return m_data[index];
	}

	FORCE_INLINE StringViewBase& operator=(const StringViewBase& other) {
		if (this != &other) {
			m_data = other.m_data;
			m_length = other.m_length;
		}
		return *this;
	}

public:
	FORCE_INLINE bool empty() const {
		return m_length == 0;
	}

	FORCE_INLINE constexpr size_t length() const {
		return m_length;
	}

	FORCE_INLINE constexpr const T* operator*() const {
		return m_data;
	}
};

// ============================================================================

class StringView : public StringViewBase<utf8> {};

} // namespace core
