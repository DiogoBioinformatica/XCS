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

std::string Instance::showInstance() const {
	std::stringstream buffer { };
	buffer << "[" << m_hash << "] ";
	buffer << Individual::showIndividual();
	return buffer.str();
}

} /* namespace XCS */
