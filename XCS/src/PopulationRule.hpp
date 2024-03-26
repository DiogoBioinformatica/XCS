/*
 * PopulationRule.hpp
 *
 *  Created on: 25 de mar. de 2024
 *      Author: uriel
 */

#ifndef POPULATIONRULE_HPP_
#define POPULATIONRULE_HPP_

#include <iostream>
#include <memory>
#include <map>
#include <random>
#include <functional>

#include "Chromosome.hpp"
#include "Instance.hpp"

namespace XCS {

class PopulationRule {
public:
	PopulationRule(const unsigned int, const unsigned int, const unsigned int);
	virtual ~PopulationRule();
	void makeMessage(const unsigned int, std::map<unsigned int, bool>&,
			std::map<unsigned int, bool>&);
	template<typename T>
	unsigned int makeSeed(const unsigned int, T, T);
	std::map<unsigned int, bool> makeRule(const std::map<unsigned int, bool>&);
private:
	const unsigned int m_multiplexersize { };
	std::random_device mch;
};

} /* namespace XCS */

#endif /* POPULATIONRULE_HPP_ */
