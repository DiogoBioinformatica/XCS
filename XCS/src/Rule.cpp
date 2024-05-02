/*
 * Rule.cpp
 *
 *  Created on: 27 de mar. de 2024
 *      Author: uriel
 */

#include "Rule.hpp"

namespace XCS {

Rule::Rule(const Chromosome &t_state, const Chromosome &t_group,
		const Chromosome &t_rulestate, const std::vector<float> &t_colours) :
		Individual(t_state, t_group), m_rulestate(t_rulestate), m_rulegroup(t_group), m_colours(t_colours) {
}

Rule::~Rule() {
}

std::map<unsigned int, bool> Rule::getRuleMessage() const {
	return m_rulestate.getMessage();
}

unsigned int Rule::getRuleMessageSize() const {
	return m_rulestate.getMessageSize();
}

std::vector<float> Rule::getColours() const {
	return m_colours;
}

std::string Rule::showRule() const {
	std::stringstream buffer;
	buffer << m_rulestate.showChromosome();
	buffer << ":";
	buffer << m_rulegroup.showChromosome();
	//buffer << " filled: " << m_filled;
	return buffer.str();
}

} /* namespace XCS */
