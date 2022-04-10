/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:24:17 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/10 21:24:57 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <fstream>
# include <cstdlib>

class Sed {
private:
	std::string	s1_to_s2(std::string line, std::string s1, std::string s2);

public:
	void	replace(std::string file, std::string s1, std::string s2);
	Sed();
	~Sed();
};

#endif
