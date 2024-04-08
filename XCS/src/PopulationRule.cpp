/*
 * PopulationRule.cpp
 *
 *  Created on: 25 de mar. de 2024
 *      Author: uriel
 */

#include "PopulationRule.hpp"

namespace XCS {

PopulationRule::PopulationRule( std::unique_ptr<OutputFile> &t_outputfile, const unsigned int t_loopnumber,
		const unsigned int t_multiplexersize, const unsigned int t_k) :
		m_multiplexersize(t_multiplexersize) {

	for (unsigned int i = 0; i != t_loopnumber; ++i) {
		m_buffer << "\n---------------------------\n";
		//long unsigned int* groupindex;

		std::map<unsigned int, bool> state;
		std::map<unsigned int, bool> group;

		makeMessage(t_k, state, group);

		auto chrstate = std::unique_ptr<Chromosome>(
				new Chromosome(state, m_multiplexersize));
		auto chrgroup = std::unique_ptr<Chromosome>(new Chromosome(group, 1));

		std::stringstream m_load { };

		m_load << "\\par Ind: ";
		m_load << chrstate->showChromosome();
		m_load << ":";
		m_load << chrgroup->showChromosome();
		m_buffer << "\n";
		m_buffer << t_outputfile->flushLeft(m_load.str());
		m_buffer << " -> ";

		auto message = makeRule(state);
		auto chrrule = std::unique_ptr<Chromosome>(
				new Chromosome(message, m_multiplexersize));

		m_load.trunc;

		m_load << "Rule: ";
		m_load << chrrule->showChromosome();
		m_load << ":";
		m_load << chrgroup->showChromosome();
		m_load << "\n";

		m_buffer << t_outputfile->flushLeft(m_load.str());

		bool flagtotal = 1;
		float filledsum = 0.0;
		if (m_rules.size() != 0) {
			bool flag = 0;

			for (auto &ruleloop : m_rules) {
				m_buffer << "  Sets:\t";
				m_buffer << ruleloop.showRule();
				m_buffer << " ";
				m_buffer << chrrule->showChromosome();
				m_buffer << ":";
				m_buffer << chrgroup->showChromosome();
				float filled = static_cast<float>((m_multiplexersize
						- chrrule->getMessageSize()))
						/ static_cast<float>(m_multiplexersize);
				filledsum += static_cast<float>(filled);

				m_buffer << "{" << filled << "}";
				if (analysisSet(ruleloop, *chrrule) == 0) {
					m_buffer << " match!!";
					flagtotal = 0;
				} else {
					flag = 1;
				}
				m_buffer << "\n";
			}

			if (flagtotal == 1) {
				makeCovering(*chrstate, *chrgroup, *chrrule);
			}
		} else {
			makeCovering(*chrstate, *chrgroup, *chrrule);
		}
		m_buffer << "filledSum: " << filledsum << "\n";
		m_buffer << "Iteration: " << i + 1 << " Pop Size: " << m_rules.size()
				<< " AveGen: "
				<< (static_cast<float>(filledsum)
						/ static_cast<float>(m_rules.size()));
	}
	makeFile(t_outputfile);
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

bool PopulationRule::analysisSet(const Rule &t_ruleloop,
		const Chromosome &t_rulecover) const {
	std::map<unsigned int, bool> ruleloop = t_ruleloop.getRuleMessage();
	std::map<unsigned int, bool> rulecover = t_rulecover.getMessage();

	bool ruleflag = 0;
	for (auto it2 = rulecover.begin(); it2 != rulecover.end(); it2++) {
		auto itfind = ruleloop.find(it2->first);
		if (itfind != ruleloop.end()) {
			if (it2->second != ruleloop[it2->first]) {
				ruleflag = 1;
			}
		} else {
			ruleflag = 1;
		}
	}
	return ruleflag;
}

void PopulationRule::makeCovering(const Chromosome &chrstate,
		const Chromosome &chrgroup, const Chromosome &chrrule) {
	m_buffer << "Rule:\t";
	m_buffer << chrrule.showChromosome();
	m_buffer << ":";
	m_buffer << chrgroup.showChromosome();
	m_buffer << "\n";
	Rule rule = Rule(chrstate, chrgroup, chrrule,
			static_cast<float>((m_multiplexersize - chrrule.getMessageSize()))
					/ static_cast<float>(m_multiplexersize));
	m_rules.push_back(rule);
}

void PopulationRule::makeFile(std::unique_ptr<OutputFile> &t_outputfile) {
	t_outputfile->insertHeader();
	t_outputfile->insertLine(m_buffer.str());
	t_outputfile->insertFooter();
}

} /* namespace XCS */
