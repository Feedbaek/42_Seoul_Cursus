/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:36:15 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/03 22:45:58 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook {
private:
	static Contact	*arr[8];
	static int		input_cnt;
public:
	void	add(Contact *data) {
		arr[input_cnt % 8] = data;
		input_cnt++;
	}
};

#endif
