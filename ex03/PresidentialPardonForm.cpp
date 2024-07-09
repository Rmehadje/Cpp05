/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:32:18 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/05 11:34:33 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon Form", 25, 5){
	this->target = "random";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon Form", 25, 5){
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &cp) : AForm(cp){
	*this = cp;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	delete this;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &og){
	this->target = og.target;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const{
	if (this->getSigned() == false)
		throw AForm::AFormNotSignedException();
	else if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooHighException();
	else
		std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &value){
	out << "Presidential Pardon Form: " << value.getName() << " , grade to sign: " << value.getGradeSign() << " , grade to execute: " << value.getGradeExec() << std::endl;
	return out;
}