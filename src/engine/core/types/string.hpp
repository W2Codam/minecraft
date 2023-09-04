// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#pragma once
#include <core/types/common.hpp>

// ============================================================================

template <typename T>
class StringBase {
protected:
	T* _data = nullptr;
	i32 _length = 0;
};
