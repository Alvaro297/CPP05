#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include <iostream>


class Intern
{
private:
public:
	Intern();
	~Intern();
	AForm* makeForm(std::string formName, std::string target);
};


#endif