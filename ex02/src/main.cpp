#include "Bureaucrat.hpp"
#include "Form.hpp"
int main(void)
{
    {
        try
        {
            Bureaucrat Bur1("Bur1", 15);
            Form form1("Form1", 20, 45);
            std::cout << Bur1 << std::endl;
            std::cout << form1 << std::endl;
            Bur1.signForm(form1);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    return (0);
}