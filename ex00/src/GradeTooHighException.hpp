#include <iostream>

class GradeTooHighException : public std::exception
{
    public:
        const char *what() const throw() {
            return "The Grade Is Too High";
        }
};
