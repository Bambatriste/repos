#include <iostream>

int main (int ac, char **av)
{
    std::string str;
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        std::cout << std::endl;
        return (0);
    }
    for (int i = 1; i < ac; i++)
    {
        str = av[i];
        for (size_t j = 0; j < str.length(); j++)
        {
            std::cout << (char)std::toupper(str[j]);
        }
    }
    std::cout << std::endl;
    return (0);
}
