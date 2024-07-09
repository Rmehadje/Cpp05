/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:57:35 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/05 12:06:19 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string name, int gradeSign, int gradeEx): name(name), gradeSign( gradeSign ), gradeExec(gradeEx) {
	if (gradeSign < 1)
		throw AForm::GradeTooHighException();
	if (gradeSign > 150)
		throw AForm::GradeTooLowException();
}


AForm::~AForm(){
}

AForm::AForm(const AForm &og): name(og.getName()), isitSigned(og.getSigned()), gradeSign(og.getGradeSign()), gradeExec(og.getGradeExec()){
}

AForm &AForm::operator=(const AForm &cp){
	if (this != &cp)
		isitSigned = cp.getSigned();
	return *this;
}

std::string AForm::getName() const {
	return name;
}

bool AForm::getSigned() const {
	return isitSigned;
}

int AForm::getGradeExec() const {
	return gradeExec;
}

int AForm::getGradeSign() const {
	return gradeSign;
}

void	AForm::beSigned(const Bureaucrat &Bureaucrat){
	if (Bureaucrat.getGrade() > gradeSign)
		throw AForm::GradeTooLowException();
	isitSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &c){
	out << "~~~~~~~~~~~~~~~Form Info~~~~~~~~~~~~~~~~" << std::endl;
	out << "Form name: " << c.getName() << std::endl;
	out << "Grade to sign: " << c.getGradeSign() << std::endl;
	out << "Grade to execute: " << c.getGradeExec();
	return (out);
}

