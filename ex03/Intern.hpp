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
	AForm* makeForm(const std::string& formName, const std::string& target) const;
};


#endif