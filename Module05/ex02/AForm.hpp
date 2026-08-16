/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:12:40 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/08/08 20:06:06 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
	public:
		AForm();
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		AForm(std::string name, int gradeToSign, int gradeToExecute);

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

		class AFormAlreadySignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		friend std::ostream &operator<<(std::ostream &os, const AForm &AForm);

		void beSigned(const Bureaucrat &bureaucrat);

	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;
};

#endif