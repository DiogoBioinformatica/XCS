/*
 * Chromosome.hpp
 *
 *  Created on: 26 de mar. de 2024
 *      Author: uriel
 */

#ifndef CHROMOSOME_HPP_
#define CHROMOSOME_HPP_

#include <map>
#include <iostream>
#include <memory>

namespace XCS {

class Chromosome {
public:
	Chromosome(std::map<unsigned int, bool>&, const unsigned int);
	virtual ~Chromosome();
	//std::map<unsigned int, bool> getMessage() const;
	//unsigned int getMessageSize() const;
	void showChromosome() const;
private:
	const std::map<unsigned int, bool> m_message { };
	const unsigned int m_messagesize { };
};

} /* namespace XCS */

#endif /* CHROMOSOME_HPP_ */
