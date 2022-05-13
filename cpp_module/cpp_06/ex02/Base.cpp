/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:29:06 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/11 17:33:55 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "ABC.hpp"

Base::~Base() {
}

Base*	generate() {
	Base *ret;

	switch (rand() % 3) {
	case 0:
		ret = new A();
		break;
	case 1:
		ret = new B();
		break;
	case 2:
		ret = new C();
		break;
	}
	return ret;
}
void	identify(Base* p) {
	void* ret;

	if ((ret = dynamic_cast<A*>(p)))
		std::cout << "A" << std::endl;
	else if ((ret = dynamic_cast<B*>(p)))
		std::cout << "B" << std::endl;
	else if ((ret = dynamic_cast<C*>(p)))
		std::cout << "C" << std::endl;
}
void	identify(Base& p) {
	try {
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	} catch (std::exception& a) {}
	try {
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	} catch (std::exception& a) {}
	try {
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (std::exception& a) {};
}
