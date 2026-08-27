/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/28 00:40:48 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/08/28 00:42:29 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		virtual ~Intern();

		AForm *makeForm(std::string formName, std::string target) const;

	private:
		typedef AForm *(*FormCreator)(std::string target);

		static AForm *createShrubberyCreationForm(std::string target);
		static AForm *createRobotomyRequestForm(std::string target);
		static AForm *createPresidentialPardonForm(std::string target);
};

#endif