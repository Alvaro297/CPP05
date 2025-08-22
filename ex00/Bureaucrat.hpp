#ifndef BUREAUCHAT_HPP
# define BUREAUCHAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat(const std::string name, int grade);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();
};



#endif