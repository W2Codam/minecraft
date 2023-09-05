// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#pragma once
#include <core/types/common.hpp>

// ============================================================================

namespace core {

/**
 * @brief A view of a string.
 *
 * @tparam T The type of the string.
 */
template <typename T>
class StringViewBase {
public: // Constructors
	StringViewBase(T* data, size_t size) : m_data(data), m_size(size) {
	}
	~StringViewBase();

	//= Operators =//

	FORCE_INLINE const T& operator[](i32 index) const {
		return m_data[index];
	}

	FORCE_INLINE StringViewBase& operator=(const StringViewBase& other) {
		if (this != &other) {
			m_data = other.size_data;
			m_size = other.m_size;
		}
		return *this;
	}

public: // Functions
	/** @returns The length of the view. */
	FORCE_INLINE size_t length(void) const {
		return m_size;
	}

	/** @returns Whether the view is empty. */
	FORCE_INLINE bool isEmpty(void) const {
		return m_size == 0;
	}

	/** @returns The data of the view. */
	FORCE_INLINE constexpr const T* get(void) const {
		return m_data;
	}

	/**
	 * @brief Returns a substring of the view.
	 *
	 * @param index The index to start the substring at.
	 * @param length The length of the substring.
	 * @return StringView<T> The substring.
	 */
	StringViewBase<T> substring(size_t index, size_t length) const;

	/**
	 * @brief Slices the view in place.
	 *
	 * @param index The offset to start the slice at.
	 * @param length The length of the slice.
	 */
	void slice(size_t index, size_t length);

private:
	T* m_data;
	size_t m_size;
};

}
