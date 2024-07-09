/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:31:44 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/05 11:32:05 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <fstream>


class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &cp);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &og);
		void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &value);