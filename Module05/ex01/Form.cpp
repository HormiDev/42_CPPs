/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:12:07 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/08/08 17:48:46 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

Form::Form(const Form &other): name(other.name), isSigned(false), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form() {}

Form::Form(std::string name, int gradeToSign, int gradeToExecute): name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

std::string Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getGradeToSign() const
{
	return gradeToSign;
}

int Form::getGradeToExecute() const
{
	return gradeToExecute;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *Form::FormAlreadySignedException::what() const throw()
{
	return "Form is already signed";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form name: " << form.getName() << ", is signed: " << (form.getIsSigned() ? "yes" : "no") << ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute();
	return os;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (isSigned)
		throw FormAlreadySignedException();
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}