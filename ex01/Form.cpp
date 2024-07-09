/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:57:35 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/09 14:20:06 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, int gradeSign, int gradeExec): name(name), gradeSign( gradeSign ), gradeExec(gradeExec) {
	if (gradeSign < 1)
		throw Form::GradeTooHighException();
	if (gradeSign > 150)
		throw Form::GradeTooLowException();
}


Form::~Form(){
}

Form::Form(const Form &og): name(og.getName()), isitSigned(og.getSigned()), gradeSign(og.getGradeSign()), gradeExec(og.getGradeExec()){
}

Form &Form::operator=(const Form &cp){
	if (this != &cp)
		isitSigned = cp.getSigned();
	return *this;
}

std::string Form::getName() const {
	return name;
}

bool Form::getSigned() const {
	return isitSigned;
}

int Form::getGradeExec() const {
	return gradeExec;
}

int Form::getGradeSign() const {
	return gradeSign;
}

void	Form::beSigned(const Bureaucrat &Bureaucrat){
	if (Bureaucrat.getGrade() > gradeSign)
		throw Form::GradeTooLowException();
	isitSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &c){
	out << "~~~~~~~~~~~~~~~Form Info~~~~~~~~~~~~~~~~" << std::endl;
	out << "Form name: " << c.getName() << std::endl;
	out << "Grade to sign: " << c.getGradeSign() << std::endl;
	out << "Grade to execute: " << c.getGradeExec();
	return (out);
}

