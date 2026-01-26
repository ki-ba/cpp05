/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 09:16:36 by kbarru            #+#    #+#             */
/*   Updated: 2026/01/26 16:14:37 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>


#  ifdef EX02
# define FORM_TYPE AForm
#  else
#  define FORM_TYPE Form
# endif

class FORM_TYPE;

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat &other);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	int	promote();
	int demote();

	#ifdef FORMS
	void	signForm(FORM_TYPE &f);
	#endif

	#ifdef EX02
	void	executeForm(FORM_TYPE const & form) const;
	#endif

	Bureaucrat &operator=(Bureaucrat& other);

	class GradeTooHighException : public std::range_error
	{
		public:
			~GradeTooHighException() throw();
			GradeTooHighException();
	};

	class GradeTooLowException : public std::range_error
	{
		public:
			~GradeTooLowException() throw();
			GradeTooLowException();
	};
};

std::ostream &operator<<(std::ostream& os, const Bureaucrat &b) throw();

#endif
