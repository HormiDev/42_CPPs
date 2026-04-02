/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 03:17:33 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/04/02 04:06:45 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

class Brain {
	public:
							Brain();
							~Brain();
							Brain(const Brain &other);
		Brain				&operator=(const Brain &other);
		friend std::ostream	&operator<<(std::ostream &os, const Brain &brain);
		void				setIdea(const std::string &idea);


	private:
		std::string ideas[100];
		int			idea_iterator;
};

#endif