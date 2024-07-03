/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:57:35 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/03 15:03:49 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, int gradeSign): name("random"), gradeSign( gradeSign ), gradeExec( 0 ) {
	if (gradeSign < 1)
		throw Form::GradeTooHighException();
	if (gradeSign < 150)
		throw Form::GradeTooLowException();
}

Form::~Form(){
	std::cout << "Form desturctor called\n";
}