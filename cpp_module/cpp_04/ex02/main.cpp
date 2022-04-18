/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:16:53 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/18 17:16:11 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;
	delete j;
	delete i;
	std::cout << std::endl;
	Animal	*a[4];

	for(int i=0; i<4; i++) {
		if (i < 2)
			a[i] = new Cat();
		else
			a[i] = new Dog();
	}
	std::cout << std::endl;

	for(int i=0; i<4; i++)
		a[i]->makeSound();
	std::cout << std::endl;

	for(int i=0; i<4; i++)
		delete a[i];
	std::cout << std::endl;

	Brain brain;
	Cat cat(brain);
	Dog dog(brain);
	std::cout << std::endl;

	brain.setter("brain", 100);
	cat.setter("cat", 100);
	dog.setter("dog", 100);

	std::cout << brain.getter() << std::endl;
	std::cout << cat.getter() << std::endl;
	std::cout << dog.getter() << std::endl;
	std::cout << std::endl;
	return 0;
}
