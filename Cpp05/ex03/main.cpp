/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:06:12 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/05 13:58:08 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	try
    {
        Bureaucrat b1("General", 5);
        std::cout << b1 << std::flush;
        Intern i;
        AForm *f = i.makeForm("Presidential Pardon", "BIG");
        AForm *f2(f);
        b1.signForm(*f);
        b1.executeForm(*f);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat b2("Soldier", 70);
        std::cout << b2 << std::flush;
        Intern i;
        AForm *f = i.makeForm("Robotomy Request", "Random");
        b2.signForm(*f);
        b2.setGrade(40);
        b2.executeForm(*f);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try
    {
        Bureaucrat b3("Soldier", 120);
        std::cout << b3 << std::flush;
        Intern i;
        AForm *f3 = i.makeForm("Shrubbery Creation", "tree");
        b3.signForm(*f3);
        b3.executeForm(*f3);
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    return 0;
}
}