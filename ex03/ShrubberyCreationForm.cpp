/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:46:17 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/05 12:13:01 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery Creation Form", 145, 137){
	this->target = "random";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137){
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cp) : AForm(cp){
	*this = cp;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	delete this;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &og){
	this->target = og.target;
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
	(void)executor;
	if (this->getSigned() == false)
		throw AForm::AFormNotSignedException();
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	std::ofstream file(target + "shrubbery");
	file << "       ccee88oo" << std::endl;
	file << "   C8O8O8Q8PoOb o8oo" << std::endl;
	file << "  dOB69QO8PdUOpugoO9bD" << std::endl;
	file << " CgggbU8OU qOp qOdoUOdcb" << std::endl;
	file << "  48e6OuU  /p u gcoUodpP" << std::endl;
	file << "    uud\\|||||//dou" << std::endl;
	file << "         |||||" << std::endl;
	file << "         ||||| " << std::endl;
	file << "         |||||" << std::endl;
	file << "         |||||" << std::endl;
	file << "   .....//||||\\...." << std::endl;
	file.close();
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &value){
	out << "shrubbery Creation Form: " << value.getName() << ", grade to sign: " << value.getGradeSign() << ", grade to execute: " << value.getGradeExec() << ", signed: " << value.getSigned() << std::endl;
	return out;
}