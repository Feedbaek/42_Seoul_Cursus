/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 23:56:21 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/08 00:03:44 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		std::cout << "argv error" << std::endl;
	else {
		Convert c(argv[1]);
		std::cout << c.toChar() << std::endl;
		std::cout << c.toDouble() << std::endl;
		std::cout << c.toFloat() << std::endl;
		std::cout << c.toInt() << std::endl;
	}
	return (0);
}
