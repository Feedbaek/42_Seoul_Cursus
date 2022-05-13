/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 23:56:21 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/09 22:14:13 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

//int main(int argc, char **argv) {
//	if (argc != 2)
//		std::cout << "argv error" << std::endl;
//	else {
//		Convert c(argv[1]);
//		std::cout << c.toChar() << std::endl;
//		std::cout << c.toDouble() << std::endl;
//		std::cout << c.toFloat() << std::endl;
//		std::cout << c.toInt() << std::endl;
//	}
//	return (0);
//}

int main(int argc, char const *argv[])
{
	if (argc != 2)
		return (0);
	Convert hi(argv[1]);
	try
	{
		std::cout << "char: " << hi.toChar() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout<< "int: " << hi.toInt() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		float tmp = hi.toFloat();
		std::cout << "float: ";
		if (tmp - hi.toInt() == 0)
			std::cout << std::fixed <<std::setprecision(1) << tmp << "f" << std::endl;
		else
			std::cout << tmp  << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout<< "double: " << hi.toDouble() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
