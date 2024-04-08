/*
 * Instance.cpp
 *
 *  Created on: 26 de mar. de 2024
 *      Author: uriel
 */

#include "Instance.hpp"

namespace XCS {

Individual::Individual(const Chromosome &t_state, const Chromosome &t_group) :
		m_state(t_state), m_group(t_group) { // @suppress("Symbol is not resolved")

}

Individual::~Individual() {
}


std::string Individual::showIndividual() const {
	std::stringstream buffer { };
	buffer << m_state.showChromosome();
	buffer << ":";
	buffer << m_group.showChromosome();
	return buffer.str();
}

} /* namespace XCS */
