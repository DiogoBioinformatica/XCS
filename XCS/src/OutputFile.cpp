/*
 * OutputFile.cpp
 *
 *  Created on: 19 de fev. de 2024
 *      Author: uriel
 */

#include "OutputFile.hpp"

namespace XCS {

OutputFile::OutputFile() {
	m_ofs.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try {
		m_ofs.open("Output/main.tex", std::ofstream::out | std::ofstream::app);
	} catch (std::ofstream::failure &e) {
		std::cerr << e.code().message() << std::endl;
	}
}

OutputFile::~OutputFile() {
	m_ofs.close();
}

void OutputFile::insertHeader() {
	m_ofs << "\documentclass[12pt,openright,twoside,letterpaper,english,brazil,sumario=tradicional]{abntex2}\n";
	m_ofs << "\\usepackage{cmap}\n";
	m_ofs << "\\usepackage{lmodern}\n";
	m_ofs << "\\usepackage[T1]{fontenc}\n";
	m_ofs << "\\usepackage[utf8]{inputenc}\n";
	m_ofs << "\\usepackage{indentfirst}\n";
	m_ofs << "\\usepackage{color}\n";
	m_ofs << "\\usepackage{graphicx}\n";
	m_ofs << "\\setlength{\\parindent}{1.3cm}\n";
	m_ofs << "\\setlength{\\parskip}{0.2cm}\n";
	m_ofs << "\\usepackage{longtable}\n";
	m_ofs << "\\begin{document}";
}

void OutputFile::insertFooter() {
	m_ofs << "\end{document}";
}

void OutputFile::insertLine(const std::string &line) {
	m_ofs << line;
}

void OutputFile::insertTableBegin(std::string &extrarowheight) {
	m_ofs << "\\begin{center}\\setlength{\\extrarowheight}{" << extrarowheight
			<< "}\\begin{longtable}{cr|cr}\\hline";
}

void OutputFile::insertTableEnd(std::string &caption, std::string &label) {
	m_ofs << "\\hline\\caption{" << caption << "}\\label{" << label
			<< "}\\end{longtable}\\end{center}";
}

void OutputFile::insertItemize(std::vector<std::string> &t_text) {
	m_ofs << "\begin{itemize}";
	for (auto &line : t_text) {
		m_ofs << line;
	}
	m_ofs << "\end{itemize}";
}

} /* namespace XCS */
