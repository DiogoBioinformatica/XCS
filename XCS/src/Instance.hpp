/*
 * Instance.hpp
 *
 *  Created on: 26 de mar. de 2024
 *      Author: uriel
 */

#ifndef INSTANCE_HPP_
#define INSTANCE_HPP_

#include "Individual.hpp"
#include "Chromosome.hpp"

namespace XCS {

class Instance: public Individual {
public:
	Instance(const Chromosome&, const Chromosome&, unsigned int);
	virtual ~Instance();
	void showInstance() const;
private:
	const unsigned int m_hash { };
};

} /* namespace XCS */

#endif /* INSTANCE_HPP_ */
