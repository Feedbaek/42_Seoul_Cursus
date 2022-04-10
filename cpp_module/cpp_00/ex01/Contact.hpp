/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:52:34 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/10 21:31:24 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <sstream>

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
	void	get_index(void);
	void	get_first_name(void);
	void	get_last_name(void);
	void	get_nickname(void);
	void	get_phone_number(void);
	void	get_darkest_secret(void);
	void	set_size(void);
};

#endif
