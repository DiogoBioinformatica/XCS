/*
 * Rule.hpp
 *
 *  Created on: 27 de mar. de 2024
 *      Author: uriel
 */

#ifndef RULE_HPP_
#define RULE_HPP_

#include <vector>

#include "Individual.hpp"

namespace XCS {

class Rule: public Individual {
public:
	Rule(const Chromosome&, const Chromosome&, const Chromosome&, const std::vector<float>&);
	virtual ~Rule();
	std::map<unsigned int, bool> getRuleMessage() const;
	unsigned int getRuleMessageSize() const;
	std::vector<float> getColours() const;
	std::string showRule() const;
private:
	Chromosome m_rulestate;
	Chromosome m_rulegroup;
	//const float m_filled { };
	const std::vector<float> m_colours { };
};

} /* namespace XCS */

#endif /* RULE_HPP_ */
