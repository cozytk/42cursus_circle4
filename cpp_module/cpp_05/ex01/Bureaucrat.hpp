#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Form;

class Bureaucrat
{
private:
	const std::string   _name;
	int                 _grade;
	Bureaucrat();

public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat& ref);
	virtual ~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& ref);

	std::string	getName() const;
	int			getGrade() const;
	void		upGrade();
	void		downGrade();
	void		signForm(Form& ref);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream&   operator<<(std::ostream &os, const Bureaucrat &ref);

#endif