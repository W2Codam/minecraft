// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#pragma once
#include <core/types/common.hpp>
#include <platform/defines.hpp>

// Type traits for making template programming more convenient.
// See: https://clang.llvm.org/docs/LanguageExtensions.html
// We can use some language extensions to make our life easier but we need to
// check if the compiler supports them first.
// ============================================================================

namespace core::traits {

/** @brief Invert the statement. */
template <typename T>
struct Not {
	enum { value = !T::value };
};

/** @brief Check if a class is derived from another class. */
// ============================================================================

template <class Base, class Derived>
struct IsBaseOf {
	enum { value = __is_base_of(Base, Derived) };
};

/** @brief Check if a type is a enum. */
// ============================================================================

template <typename T>
struct IsEnum {
	enum { value = __is_enum(T) };
};

/** @brief Check if two types are the same. */
// ============================================================================

template <typename T, typename T2>
struct IsSame {
	enum { value = false };
};

template <typename T>
struct IsSame<T, T> {
	enum { value = true };
};

/** @brief Enable if a condition is true. */
// ============================================================================

template <bool T, typename P = void>
struct EnableIf;

template <typename T>
struct EnableIf<true, T> {
	typedef T Type;
};

template <typename T>
struct EnableIf<false, T> {};

} // namespace Core::Traits
