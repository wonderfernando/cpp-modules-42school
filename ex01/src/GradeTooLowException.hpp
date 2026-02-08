#include <iostream>

class GradeTooLowException : public std::exception
{
    public:
        const char *what() const throw() {
            return "The Grade Is Too Low";
        }
};
