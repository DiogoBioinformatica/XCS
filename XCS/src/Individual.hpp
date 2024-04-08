/*
 * Individual.hpp
 *
 *  Created on: 26 de mar. de 2024
 *      Author: uriel
 */

#ifndef INDIVIDUAL_HPP_
#define INDIVIDUAL_HPP_

#include <string>
#include <sstream>

#include "Chromosome.hpp"

namespace XCS {

class Individual {
public:
	Individual(const Chromosome&, const Chromosome&);
	virtual ~Individual();
	std::string showIndividual() const;
protected:
	const Chromosome m_state;
	const Chromosome m_group;
};

} /* namespace XCS */

#endif /* INDIVIDUAL_HPP_ */
