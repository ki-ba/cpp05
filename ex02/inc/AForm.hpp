/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarru <kbarru@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 15:11:07 by kbarru            #+#    #+#             */
/*   Updated: 2026/01/26 15:55:34 by kbarru           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_name;
		bool				 _signed;
		const int			_sign_grade;
		const int 			_exec_grade;

	public:
		AForm();
		AForm(const AForm &other);
		AForm(const std::string name, bool is_signed, const int sign_grade, const int exec_grade);
		virtual ~AForm();
		void	beSigned(Bureaucrat b);
		std::string	getName() const;
		int	getSignGrade() const;
		int	getExecGrade() const;
		bool	isSigned() const;

		void execute(Bureaucrat const & executor) const;
		virtual void make_action() const = 0;

		AForm &operator=(const AForm& other); // akes no sense since only signature is non-const

		class GradeTooHighException : public std::range_error
		{
			public:
				GradeTooHighException();
				GradeTooHighException(std::string msg);
				~GradeTooHighException() throw();
		};
		class GradeTooLowException : public std::range_error
		{
			public:
				GradeTooLowException();
				GradeTooLowException(std::string msg);
				~GradeTooLowException() throw();
		};

		class FormNotSignedException : public std::runtime_error
		{
			public:
				FormNotSignedException();
				~FormNotSignedException() throw();
		};
};

std::ostream &operator<<(std::ostream& os, const AForm &f) throw();
#endif
