// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#pragma once
#include <platform/defines.hpp>
#include <core/types/common.hpp>

// Wrappers for memory allocation functions.
// Useful if platform specific memory allocation is needed or in the future
// some sort of memory tracking is needed.
// ============================================================================

namespace core::memory {

	/**
	 * @brief Allocate memory for 'count' elements of type 'T'.
	 * 
	 * @tparam T The type of the elements.
	 * @param count The amount of elements to allocate.
	 * @param alignment The alignment of the memory.
	 * @return T* The pointer to the allocated memory.
	 */
	template <typename T>
	T* alloc(size_t count = 1) {
		return new T[count];
	}

	/**
	 * @brief Free the memory of a pointer.
	 * 
	 * This function is only used for pointers allocated
	 * with the 'alloc' function.
	 * 
	 * @tparam T The type of the pointer.
	 * @param ptr The pointer.
	 */
	template <typename T>
	void free(T* ptr) {
		delete[] ptr;
	}

	/**
	 * @brief Copy 'count' elements from 'src' to 'dest'.
	 * 
	 * @tparam T The type of the elements.
	 * @param dest The destination.
	 * @param src The source.
	 * @param count The amount of elements to copy.
	 */
	template <typename T>
	void copy(T* dest, const T* src, size_t count) {
		for (size_t i = 0; i < count; i++)
			dest[i] = src[i];
	}

	/**
	 * @brief Reallocate memory for 'count' elements of type 'T'.
	 * 
	 * @tparam T The type of the elements.
	 * @param ptr The pointer to the memory.
	 * @param count The amount of elements to allocate.
	 * @return T* The pointer to the allocated memory.
	 */
	template <typename T>
	T* realloc(T* ptr, size_t count) {
		T* newPtr = memory::alloc<T>(count);
		memory::copy(newPtr, ptr, count);
		memory::free(ptr);
		return newPtr;
	}
}
