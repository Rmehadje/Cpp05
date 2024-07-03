/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmehadje <rmehadje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:06:12 by rmehadje          #+#    #+#             */
/*   Updated: 2024/07/02 13:57:17 by rmehadje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(){
	try{
		Bureaucrat a("yemak", 1);
		std::cout << a;
		a.increment();
	} catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	try{
		Bureaucrat b("khtek", 150);
		b.increment();
		std::cout << b;
		b.decrement();
		std::cout << b;
		b.decrement();
		std::cout << b;

	} catch (std::exception& c){
		std::cout << c.what() << std::endl;
	}
}