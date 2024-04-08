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
#include <vector>
#include <string>
#include <sstream>

#include "Chromosome.hpp"
#include "Instance.hpp"
#include "Rule.hpp"
#include "OutputFile.hpp"

namespace XCS {

class PopulationRule {
public:
	PopulationRule( std::unique_ptr<OutputFile>&, const unsigned int, const unsigned int, const unsigned int);
	virtual ~PopulationRule();
	void makeMessage(const unsigned int, std::map<unsigned int, bool>&,
			std::map<unsigned int, bool>&);
	template<typename T>
	unsigned int makeSeed(const unsigned int, T, T);
	std::map<unsigned int, bool> makeRule(const std::map<unsigned int, bool>&);
	bool analysisSet(const Rule&, const Chromosome&) const;
	void makeCovering(const Chromosome&, const Chromosome&, const Chromosome&);
	void makeFile(std::unique_ptr<OutputFile>&);
private:
	const unsigned int m_multiplexersize { };
	std::random_device mch;
	std::vector<Rule> m_rules;
	std::stringstream m_buffer;
};

} /* namespace XCS */

#endif /* POPULATIONRULE_HPP_ */
