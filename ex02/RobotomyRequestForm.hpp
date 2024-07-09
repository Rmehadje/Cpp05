/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:23:08 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/05 11:23:29 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <fstream>


class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &cp);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &og);
		void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &value);