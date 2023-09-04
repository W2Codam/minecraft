// ============================================================================
// Copyright (C) 2023 - W2Wizard & TechDaan
// See the LICENSE file in the project root for more information.
// ============================================================================

#include <core/engine.hpp>
#include <core/types/common.hpp>
#include <iostream>
#include <platform/defines.hpp>

// ============================================================================

int main(int argc, const char* argv[]) {
	Engine<PlatformType> engine;

	std::cout << "Hello, Linux!" << std::endl;
	return (EXIT_SUCCESS);
}
