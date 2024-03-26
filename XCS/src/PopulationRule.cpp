/*
 * PopulationRule.cpp
 *
 *  Created on: 25 de mar. de 2024
 *      Author: uriel
 */

#include "PopulationRule.hpp"

namespace XCS {

PopulationRule::PopulationRule(const unsigned int t_loopnumber,
		const unsigned int t_multiplexersize, const unsigned int t_k) :
		m_multiplexersize(t_multiplexersize) {
	for (unsigned int i = 0; i != t_loopnumber; ++i) {
		std::cout << "\n---------------------------\n";
		//long unsigned int* groupindex;

		std::map<unsigned int, bool> state;
		std::map<unsigned int, bool> group;

		makeMessage(t_k, state, group);
		//d::cout << "GGG " <<

		Chromosome chrstate(state, m_multiplexersize);
		Chromosome chrgroup(group, 1);

		std::cout << "Ind: ";
		chrstate.showChromosome();
		std::cout << ":";
		chrgroup.showChromosome();

		std::cout << " -> ";

		auto message = makeRule(state);
		auto chrrule = std::unique_ptr<Chromosome>(
				new Chromosome(message, m_multiplexersize));

		std::cout << "Rule: ";
		chrrule->showChromosome();
		std::cout << ":";
		chrgroup.showChromosome();
		std::cout << "\n";

		//Instance instance = Instance(chrstate, chrgroup, 10);
		//instance.showInstance();
	}
}

PopulationRule::~PopulationRule() {
}

void PopulationRule::makeMessage(const unsigned int t_k,
		std::map<unsigned int, bool> &t_state,
		std::map<unsigned int, bool> &t_group) {
	std::map<unsigned int, bool> message;
	std::vector<bool> result(t_k, 0);
	for (unsigned int i = 0; i != m_multiplexersize; ++i) {
		message[i] = makeSeed(0, 0, 1);
		if (i < t_k) {
			result[i] = message[i];
		}
	}
	auto p = result.begin()._M_p;
	auto groupnumber = *p;

	t_state = message;
	t_group.insert(
			std::pair<unsigned int, bool>(0, message[groupnumber + t_k]));
}

template<typename T>
unsigned int PopulationRule::makeSeed(const unsigned int seedtype, T rangeinf,
		T rangesup) {
	std::default_random_engine generator(mch());
	if (seedtype == 0) {
		std::uniform_int_distribution<unsigned int> distribution(rangeinf,
				rangesup);
		auto weight = std::bind(distribution, generator);
		return weight();

	} else {
		std::binomial_distribution<unsigned int> distribution(rangesup,
				rangeinf);
		auto weight = std::bind(distribution, generator);
		return weight();
	}
}

std::map<unsigned int, bool> PopulationRule::makeRule(
		const std::map<unsigned int, bool> &t_state) {

	std::map<unsigned int, bool> result;
	auto itend = t_state.end();
	for (auto it = t_state.begin(); it != itend; ++it) {
		if (makeSeed(1, static_cast<float>(0.5), static_cast<float>(3 - 0.5))
				== 1) {
			result[it->first] = it->second;
		}
	}
	return result;
}

} /* namespace XCS */
