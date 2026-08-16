/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 19:12:07 by ide-dieg          #+#    #+#             */
/*   Updated: 2026/08/08 20:05:55 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const AForm &other): name(other.name), isSigned(false), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm() {}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute): name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getGradeToSign() const
{
	return gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::AFormAlreadySignedException::what() const throw()
{
	return "AForm is already signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
	os << "AForm name: " << AForm.getName() << ", is signed: " << (AForm.getIsSigned() ? "yes" : "no") << ", grade to sign: " << AForm.getGradeToSign() << ", grade to execute: " << AForm.getGradeToExecute();
	return os;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (isSigned)
		throw AFormAlreadySignedException();
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

void AForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned)
		throw std::runtime_error("AForm is not signed");
	if (executor.getGrade() > gradeToExecute)
		throw GradeTooLowException();
	// The actual execution logic should be implemented in derived classes
}