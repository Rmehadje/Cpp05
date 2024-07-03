/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:52:22 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/02 13:07:33 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>


class	Bureaucrat{
	private:
		const std::string name;
		int	grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &og);
		Bureaucrat &operator=(const Bureaucrat &cp);
		~Bureaucrat();

		const	std::string &getName(void) const;
		int	getGrade(void) const;
		void	increment(void);
		void	decrement(void);

		class GradeTooHighException: public std::exception{
			const char* what(void) const throw();
		};
		class GradeTooLowException: public std::exception{
			const char* what(void) const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &value);
