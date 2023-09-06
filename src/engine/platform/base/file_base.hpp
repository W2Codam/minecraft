// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#pragma once
#include <core/types/common.hpp>
#include <core/types/string_view.hpp>

// ============================================================================

namespace core::filesystem {

/** @brief Different file modes. */
enum class FileMode : u32 {
	CreateAlways = 2,
	CreateNew = 1,
	OpenAlways = 4,
	OpenExisting = 3,
	TruncateExisting = 5
};

/** @brief Different file access types. */
enum class FileAccess : u32 {
	Read = 0x80000000,
	Write = 0x40000000,
	ReadWrite = Read | Write
};

/** @brief Different file share types. */
enum class FileShare : u32 {
	None = 0x00000000,
	Read = 0x00000001,
	Write = 0x00000002,
	Delete = 0x00000004,
	ReadWrite = Read | Write,
	All = ReadWrite | Delete
};

class AFileBase {
public:
	virtual ~AFileBase() {
	}

public:
	/**
	 * @brief Reads data from a file.
	 *
	 * @param[out] buffer Buffer to store the data in.
	 * @param[in] bytesRead The amount of bytes read that were read.
	 * @param[out] bytesToRead The maximum amount bytes to read.
	 * @return True if cannot read data, otherwise false.
	 */
	virtual bool read(void* buffer, size_t* bytesRead, size_t bytesToRead) = 0;

	/**
	 * @brief Writes data to a file.
	 *
	 * @param[out] buffer
	 * @param[in] bytesToWrite
	 * @param[out] bytesWritten
	 * @return true
	 * @return false
	 */
	virtual bool write(const void* buffer, size_t* bytesWritten, size_t bytesToWrite) = 0;

	/** @brief Closes the file. */
	virtual void close() = 0;

public:
	virtual size_t size() const = 0;
	virtual size_t getPosition() const = 0;
	virtual void setPosition(size_t seek) = 0;
	virtual bool isOpen() const = 0;
};

} // namespace core::filesystem
