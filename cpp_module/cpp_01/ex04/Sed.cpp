/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:16:17 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/15 12:36:25 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

std::string	Sed::s1_to_s2(std::string line, std::string s1, std::string s2) {
	std::string	str = "";
	size_t	j;

	for (size_t i=0; i<line.length(); i++) {
		j = 0;
		while (line[i + j] == s1[j] && j < s1.length())
			j++;
		if (j == s1.length()) {
			str += s2;
			i += (j - 1);
		}
		else
			str += line[i];
	}
	return (str);
}

void	Sed::replace(std::string file, std::string s1, std::string s2) {
	if (file.length() == 0) {
		std::cout << "Error: file\n";
		exit(1);
	}
	else if (s1.length() == 0) {
		std::cout << "Error: s1\n";
		exit(1);
	}
	else if (s2.length() == 0) {
		std::cout << "Error: s2\n";
		exit(1);
	}
	std::ifstream ifs(file.c_str(), std::ios::in);
	if (ifs.fail()) {
		std::cout << "Error: input file open\n";
		exit(1);
	}
	file += ".replace";
	std::ofstream ofs(file.c_str(), std::ios::out | std::ios::trunc);
	if (ofs.fail()) {
		std::cout << "Error: output file open\n";
		exit(1);
	}
	std::string line;
	while (std::getline(ifs, line)) {
		ofs << Sed::s1_to_s2(line, s1, s2);
		if (!ifs.eof())
			ofs << "\n";
	}
	ifs.close();
	ofs.close();
}

Sed::Sed() {
}

Sed::~Sed() {
}
