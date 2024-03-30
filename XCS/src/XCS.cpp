//============================================================================
// Name        : XCS.cpp
// Author      : Uriel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <chrono>
#include <memory>
#include <cmath>

#include "OutputFile.hpp"
#include "PopulationRule.hpp"

int main() {
	auto start = std::chrono::high_resolution_clock::now();

	const unsigned int loopnumber = 15;
	const unsigned int k = 2;

	auto outputfile = std::unique_ptr<XCS::OutputFile>(new XCS::OutputFile());

	auto populationrule = std::unique_ptr<XCS::PopulationRule>(
			new XCS::PopulationRule(*outputfile, loopnumber, (std::pow(2, k) + k), k));

	auto result = std::chrono::high_resolution_clock::now() - start;
	long long microseconds = std::chrono::duration_cast<
			std::chrono::microseconds>(result).count();
	std::cout << "" << std::endl;
	std::cout << "Execution Time: " << microseconds << " microseconds.";
	return 0;
}
