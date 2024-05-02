/*
 * OutputFile.hpp
 *
 *  Created on: 19 de fev. de 2024
 *      Author: uriel
 */

#ifndef OUTPUTFILE_HPP_
#define OUTPUTFILE_HPP_

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>

namespace XCS {

class OutputFile {
public:
	OutputFile();
	virtual ~OutputFile();
	void insertHeader();
	void insertFooter();
	void insertLine(const std::string&);
	std::string insertLineColour(const std::string&, const std::vector<float>&);
	std::string flushLeft(const std::string&);
	void insertTableBegin(std::string&);
	void insertTableEnd(std::string&, std::string&);
	void insertItemize(std::vector<std::string>&);
private:
	std::ofstream m_ofs;
};

} /* namespace XCS */

#endif /* OUTPUTFILE_HPP_ */
