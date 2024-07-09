/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:06:12 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/05 12:07:44 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat  *bureaucrat = new Bureaucrat("Bureaucrat", 4);
        AForm        *Aform = new  PresidentialPardonForm("AForm");
        AForm        *Aform2 = new RobotomyRequestForm("AForm2");
        AForm        *Aform3 = new ShrubberyCreationForm("tree");

        std::cout << *bureaucrat << std::endl;
        std::cout << *Aform << std::endl;
        std::cout << *Aform2 << std::endl;
        std::cout << *Aform3 << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Sign Form section " << std::endl;
        bureaucrat->signForm(*Aform);
        bureaucrat->signForm(*Aform2);
        bureaucrat->signForm(*Aform3);

        std::cout << "----------------------------------------" << std::endl;
        std::cout << *bureaucrat << std::endl;
        std::cout << *Aform << std::endl;
        std::cout << *Aform2 << std::endl;
        std::cout << *Aform3 << std::endl;

        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Execute Form section " << std::endl;
        bureaucrat->executeForm(*Aform);
        bureaucrat->executeForm(*Aform2);
        bureaucrat->executeForm(*Aform3);
    
        delete bureaucrat;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Grade out of range " << '\n';
    }

    return (0);
}