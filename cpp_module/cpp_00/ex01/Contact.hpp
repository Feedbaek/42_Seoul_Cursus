/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:52:34 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/12 20:54:59 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <sstream>
# include <cctype>

class Contact {
private:
	static int	size;
	int			index;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
public:
	void	contact_add(std::string first_name, std::string last_name,
		std::string nickname, std::string phone_number, std::string darkest_secret);
	std::string	get_index(void);
	int	get_int_index(void);
	std::string	get_first_name(void);
	std::string	get_last_name(void);
	std::string	get_nickname(void);
	std::string	get_phone_number(void);
	std::string	get_darkest_secret(void);
	void	print_inform(void);
	void	set_size(void);
};

#endif
