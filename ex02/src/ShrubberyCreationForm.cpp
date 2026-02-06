/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:59:28 by kbarru            #+#    #+#             */
/*   Updated: 2026/01/26 16:25:43 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", false, SHRUBBERYCREATION_SIGN_GRADE, SHRUBBERYCREATION_EXEC_GRADE), _target("Home")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", false, SHRUBBERYCREATION_SIGN_GRADE, SHRUBBERYCREATION_EXEC_GRADE), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
	this->_target = other._target;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::make_action() const
{
	std::ofstream file;
	file.open((this->_target + "_shrubbery").c_str());

file << std::endl << std::endl;
file << "                         oxoxoo    ooxoo "<< std::endl;
file << "                        ooxoxo oo  oxoxooo"<< std::endl;
file << "                        oooo xxoxoo ooo ooox"<< std::endl;
file << "                        oxo o oxoxo  xoxxoxo"<< std::endl;
file << " 	       _-_         oxo xooxoooo o oo         _-_"<< std::endl;
file << " 	    /~~   ~~\\	    ooo\\oo\\  /o/o         /~~   ~~\\"<< std::endl;
file << " 	 /~~         ~~\\        \\  \\/ /        /~~         ~~\\"<< std::endl;
file << " 	{               }        |   /        {               }"<< std::endl;
file << " 	 \\  _-     -_  /         |  |          \\  _-     -_  /"<< std::endl;
file << " 	   ~  \\ //  ~	         | D|            ~  \\ //  ~"<< std::endl;
file << " 	_- -   | | _- _	         |  |         _- -   | | _- _"<< std::endl;
file << " 	  _ -  | |   -_	         |  |           _ -  | |   -_"<< std::endl;
file << " 	      // \\        ______/____\\____          // \\"<< std::endl;

}
