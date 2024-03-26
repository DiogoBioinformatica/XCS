/*
 * Chromosome.cpp
 *
 *  Created on: 26 de mar. de 2024
 *      Author: uriel
 */

#include "Chromosome.hpp"

namespace XCS {

Chromosome::Chromosome(std::map<unsigned int, bool> &t_message,
		const unsigned int t_messagesize) :
		m_message(t_message), m_messagesize(t_messagesize) {
}

Chromosome::~Chromosome() {
}

void Chromosome::showChromosome() const {
	auto it = m_message.begin();
	for (unsigned int i = 0; i != m_messagesize; ++i) {
		auto itfind = m_message.find(i);
		if (itfind != m_message.end()) {
			std::cout << it->second;
			++it;
		} else {
			std::cout << "#";
		}
	}
}

} /* namespace XCS */
