/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:13:09 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/05 11:53:15 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &Name, int Grade): name(Name), grade(Grade){
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat::Bureaucrat(const Bureaucrat &og): name(og.getName()), grade(og.getGrade()){
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cp){
	if (this!= &cp)
		grade = cp.getGrade();
	return *this;
}

int	Bureaucrat::getGrade(void) const{
	return grade;
}

const	std::string &Bureaucrat::getName(void) const{
	return name;
}


void	Bureaucrat::increment(void){
	if (grade - 1 < 1)
		throw GradeTooHighException();
	else
		grade--;
}
void	Bureaucrat::decrement(void){
	if (grade + 1 > 150)
		throw GradeTooLowException();
	else
		grade++;
}

void	Bureaucrat::signForm(AForm &form){
	try{
		form.beSigned(*this);
		std::cout << *this << " signed " << form.getName() << std::endl;
	} catch (AForm::GradeTooLowException &e){
			std::cout<< name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &c){
	out << c.getName() << ", bureaucrat grade " << c.getGrade() << std::endl;
	return (out);
}

void	Bureaucrat::executeForm(AForm const &form){
	try{
		form.execute(*this);
		std::cout << form.getName() << " executed" << std::endl;
	}catch(const std::exception &e){
		std::cout << form.getName() << " not executed" << std::endl;
	}
}