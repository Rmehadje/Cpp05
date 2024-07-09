/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:24:04 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/05 11:31:18 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy request Form", 72, 45){
	this->target = "random";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy request Form", 72, 45){
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cp) : AForm(cp){
	*this = cp;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	delete this;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &og){
	this->target = og.target;
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const{
	if (this->getSigned() == false)
		throw AForm::AFormNotSignedException();
	else if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooHighException();
	else{
		std::cout << "Robotomy in progress..." << std::endl;
		srand(time(0));
		if (rand() % 2 == 0)
			std::cout << this->target << " has been Robotomized successfully!" << std::endl;
		else
			std::cout << this->target << " Robotomization failed..." << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &value){
	out << "Robotomy Request Form: " << value.getName() << " , grade to sign: " << value.getGradeSign() << " , grade to execute: " << value.getGradeExec() << std::endl;
	return out;
}