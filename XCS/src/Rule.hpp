/*
 * Rule.hpp
 *
 *  Created on: 27 de mar. de 2024
 *      Author: uriel
 */

#ifndef RULE_HPP_
#define RULE_HPP_

#include "Individual.hpp"

namespace XCS {

class Rule: public Individual {
public:
	Rule(const Chromosome&, const Chromosome&, const Chromosome&, const float);
	virtual ~Rule();
	std::map<unsigned int, bool> getRuleMessage() const;
	unsigned int getRuleMessageSize() const;
	std::string showRule() const;
private:
	Chromosome m_rulestate;
	Chromosome m_rulegroup;
	const float m_filled = { };
};

} /* namespace XCS */

#endif /* RULE_HPP_ */
