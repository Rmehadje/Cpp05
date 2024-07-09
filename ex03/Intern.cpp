/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 13:07:32 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/05 13:49:05 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){

}

Intern::~Intern(){
}

Intern::Intern(Intern const &og){
	*this = og;
	return;
}

Intern &Intern::operator=(Intern const &cp){
	return *this;
}

const char *Intern::NoFormFound::what() const throw(){
	return "no form found";
}

AForm *Intern::makeForm(std::string const &formName, std::string target){
	std::string Form[] = {
		"Robotomy Request",
		"Presidential Pardon",
		"Shrubbery Creation"
	};
	AForm *forms[] = {
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target),
		new ShrubberyCreationForm(target),
	};
	for (int i = 0; i < 3; i++){
		if (formName == Form[i]){
			std::cout << "Intern is currently making the " << formName << std::endl;
			for (int j = 0;j < 3;j++)
				if (j != i)
					delete forms[j];
			return forms[i];
		}
	}
	throw NoFormFound();
	return nullptr;
}
