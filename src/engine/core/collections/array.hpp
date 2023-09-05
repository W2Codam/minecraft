// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#pragma once
#include <core/types/common.hpp>
#include <initializer_list>

// ============================================================================

namespace core
{

/**
 * @brief A dynamic memory allocating array.
 *
 * TODO: Lot's of duplicated code, maybe have some sort of common
 * memory allocation class / functions?
 * 
 * @tparam T The type of the array.
 */
template <typename T>
class Array {
public: // Constructors
	/**
	 * @brief Construct a new Array object
	 */
	Array(void) : m_size(0), m_capacity(0) { }

	/**
	 * @brief Construct a new Array object
	 * 
	 * @param capacity The capacity of the array.
	 */
	Array(i32 capacity) : m_size(0), m_capacity(capacity) {
		m_data = new T[capacity];
	}

	/**
	 * @brief Construct a new Array object
	 * 
	 * @param list The initializer list.
	 */
	Array(std::initializer_list<T> list) {
		m_size = m_capacity = list.size();

		m_data = new T[list.size()];
		for (size_t i = 0; i < list.size(); i++) {
			m_data[i] = list[i];
		}
	}

	/**
	 * @brief Construct a new Array object
	 * 
	 * @param other The other array.
	 */
	Array(const Array<T>& other) {
		m_size = m_capacity = other.m_size;

		m_data = new T[m_capacity];
		for (size_t i = 0; i < m_size; i++) {
			m_data[i] = other.m_data[i];
		}
	}

	~Array(void) {
		delete[] m_data;
	}

public: // Operators
	Array& operator=(std::initializer_list<T> list) {
		delete[] m_data;

		m_size = m_capacity = list.size();

		m_data = new T[list.size()];
		for (size_t i = 0; i < list.size(); i++) {
			m_data[i] = list[i];
		}

		return *this;
	}

	Array& operator=(const Array<T>& other) {
		if (this != &other) {
			delete[] m_data;

			m_size = m_capacity = other.m_size;

			m_data = new T[m_capacity];
			for (size_t i = 0; i < m_size; i++) {
				m_data[i] = other.m_data[i];
			}
		}

		return *this;
	}

	T& operator[](i32 index) {
		return this->operator[](static_cast<size_t>(index));
	}

	T& operator[](size_t index) {
		ASSERT(index > 0 && index < m_size, "Index out of bounds!");
		return m_data[index];
	}

public: // Methods
	/** @return The length of the array. */
	size_t length(void) const {
		return m_size;
	}

	/**
	 * @brief Pushes a value to the array.
	 * 
	 * @param value The new value to push.
	 */
	void push(const T& value) {
		if (m_size == m_capacity) {
			m_capacity = m_capacity == 0 ? 1 : m_capacity * 2;
			T* newData = new T[m_capacity];

			for (size_t i = 0; i < m_size; i++) {
				newData[i] = m_data[i];
			}

			delete[] m_data;
			m_data = newData;
		}

		m_data[m_size++] = value;
	}

	/**
	 * @brief Inserts a value at the given index.
	 * 
	 * @param value The new value to insert.
	 * @param index The index to insert the value at.
	 */
	void insert(const T& value, size_t index) {
		ASSERT(index > 0 && index < m_size, "Index out of bounds!");

		if (m_size == m_capacity) {
			m_capacity = m_capacity == 0 ? 1 : m_capacity * 2;
			T* newData = new T[m_capacity];

			for (size_t i = 0; i < m_size; i++) {
				newData[i] = m_data[i];
			}

			delete[] m_data;
			m_data = newData;
		}

		for (size_t i = m_size; i > index; i--) {
			m_data[i] = m_data[i - 1];
		}

		m_data[index] = value;
		m_size++;
	}

	/**
	 * @brief Removes a value at the given index.
	 * 
	 * @param index The index to remove the value at.
	 */
	void remove(size_t index) {
		ASSERT(index > 0 && index < m_size, "Index out of bounds!");

		for (size_t i = index; i < m_size - 1; i++) {
			m_data[i] = m_data[i + 1];
		}

		m_size--;
	}

private:
	size_t m_size = 0;
	size_t m_capacity = 0;
	T* m_data = nullptr;
};

} // namespace core
