/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:12:40 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/08/08 17:48:16 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
	public:
		Form();
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		Form(std::string name, int gradeToSign, int gradeToExecute);

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class FormAlreadySignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		friend std::ostream &operator<<(std::ostream &os, const Form &form);

		void beSigned(const Bureaucrat &bureaucrat);

	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;
};

#endif