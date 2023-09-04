// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#pragma once
#include <core/types/common.hpp>
#include <core/types/stringview.hpp>

// ============================================================================

namespace core::filesystem {

class AFileBase {
public:
	virtual ~AFileBase() {
	}
	// Templated read function to read 'count' elements of type 'T' from the file.
	template <typename T>
	bool read(T& data);

	// Templated write function to write 'count' elements of type 'T' to the file.
	template <typename T>
	bool write(const T& data);

	// Pure virtual function to open the file for reading.
	virtual bool open(const char_t* path) = 0;

	// Pure virtual function to close the file.
	virtual void close(void) = 0;
};

} // namespace core::filesystem
