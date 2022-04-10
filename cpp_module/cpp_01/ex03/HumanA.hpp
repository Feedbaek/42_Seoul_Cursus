/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:29:17 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/10 14:52:30 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA {
private:
	std::string	name;
	Weapon	*w;
public:
	void	attack();
	HumanA(std::string name, Weapon &w);
	~HumanA();
};
