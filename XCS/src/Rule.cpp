/*
 * Rule.cpp
 *
 *  Created on: 27 de mar. de 2024
 *      Author: uriel
 */

#include "Rule.hpp"

namespace XCS {

Rule::Rule(const Chromosome &t_state, const Chromosome &t_group,
		const Chromosome &t_rulestate, const float t_filled) :
		Individual(t_state, t_group), m_rulestate(t_rulestate), m_rulegroup(t_group), m_filled(t_filled) {
}

Rule::~Rule() {
}

std::map<unsigned int, bool> Rule::getRuleMessage() const {
	return m_rulestate.getMessage();
}

unsigned int Rule::getRuleMessageSize() const {
	return m_rulestate.getMessageSize();
}

void Rule::showRule() const {
	m_rulestate.showChromosome();
	std::cout << ":";
	m_rulegroup.showChromosome();
	std::cout << " filled: " << m_filled;
}

} /* namespace XCS */
