/*
 * Instance.cpp
 *
 *  Created on: 26 de mar. de 2024
 *      Author: uriel
 */

#include "Instance.hpp"

namespace XCS {

Instance::Instance(const Chromosome &t_state, const Chromosome &t_group,
		const unsigned int t_hash) :
		Individual(t_state, t_group), m_hash(
				t_hash) {
}

Instance::~Instance() {
}

void Instance::showInstance() const {
	std::cout << "[" << m_hash << "] ";
	Individual::showIndividual();
}

} /* namespace XCS */
