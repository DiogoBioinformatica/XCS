//============================================================================
// Name        : XCS.cpp
// Author      : Diogo Pereira
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <chrono>
#include <memory>
#include <cmath>

int main() {
	auto start = std::chrono::high_resolution_clock::now();

	const unsigned int loopnumber = 15;
	const unsigned int messagesize = 6;

	auto outputfile = std::unique_ptr<XCS::OutputFile>(new XCS::OutputFile());
	outputfile->insertLine("teste");

	/*auto database = std::unique_ptr<XCS::DataBase>(new XCS::DataBase());
	database->DBSearch(
			"SELECT id, message FROM codeword WHERE sequence_id=51;");

	auto populationrule = std::unique_ptr<XCS::PopulationRule>(
			new XCS::PopulationRule(loopnumber, messagesize));*/

	auto result = std::chrono::high_resolution_clock::now() - start;
	long long microseconds = std::chrono::duration_cast<
			std::chrono::microseconds>(result).count();
	std::cout << "" << std::endl;
	std::cout << "Execution Time: " << microseconds << " microseconds.";
	return 0;
}
