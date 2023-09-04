// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#pragma once
#include <core/types/traits.hpp>
#include <core/types/common.hpp>
#include <platform/defines.hpp>

using namespace core::traits;

// ============================================================================

template <typename T>
class Engine {
public:
	Engine(void) {
	}

	T getValue() const {
		return value;
	}

	void setValue(T newValue) {
		value = newValue;
	}

private:
	T value;
};
