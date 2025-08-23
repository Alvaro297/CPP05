#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

typedef AForm* (*FormCreator)(const std::string& target);

static AForm* createShrubbery(const std::string& target) { return new ShrubberyCreationForm(target); }

static AForm* createRobotomy(const std::string& target) { return new RobotomyRequestForm(target); }

static AForm* createPresidential(const std::string& target) { return new PresidentialPardonForm(target); }

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
	const std::string names[] =
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	FormCreator creators[] =
	{
		&createShrubbery,
		&createRobotomy,
		&createPresidential
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == names[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](target);
		}
	}

	std::cerr << "Error: Form '" << formName << "' does not exist." << std::endl;
	return NULL;
}