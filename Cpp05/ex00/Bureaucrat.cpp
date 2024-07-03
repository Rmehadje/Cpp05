/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:52:02 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/02 13:13:30 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("random"), grade(1){
}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name), grade(grade){
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Bureaucrat destructor has been called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &og){
	*this = og;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cp){
	if (this!= &cp)
		grade = cp.grade;
	return *this;
}

int	Bureaucrat::getGrade(void) const{
	return grade;
}

const	std::string &Bureaucrat::getName(void) const{
	return name;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &c){
	out << c.getName() << ", bureaucrat grade " << c.getGrade() << std::endl;
	return (out);
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw(){
	return "Grade is too high.\n";
}
const char* Bureaucrat::GradeTooLowException::what(void) const throw(){
	return "Grade is too Low.\n";
}

void	Bureaucrat::increment(void){
	if (grade == 1)
		throw GradeTooHighException();
	else
		grade--;
}
void	Bureaucrat::decrement(void){
	if (grade == 150)
		throw GradeTooLowException();
	else
		grade++;
}