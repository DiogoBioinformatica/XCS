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


void Individual::showIndividual() const {
	m_state.showChromosome();
	std::cout << ":";
	m_group.showChromosome();
}

} /* namespace XCS */
