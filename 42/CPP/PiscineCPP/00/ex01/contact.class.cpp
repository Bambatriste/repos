#include "contact.class.hpp"


    Contact::Contact(void)
    {
		contact_fieldnames[0] = "index";
		contact_fieldnames[1] = "first name";
		contact_fieldnames[2] = "last name";
		contact_fieldnames[3] = "nickname";
		contact_fieldnames[4] = "phone number";
		contact_fieldnames[5] = "darkest secret";

        return;
    }

    Contact::~Contact(void)
    {
        return;
    }

	void	Contact::ask_until_valid(int input_id)
	{
		std::string input_str;

		std::cout << "please enter contact ";
		std::cout << this->contact_fieldnames[input_id + 1];
		std::cout << " :";

		std::getline(std::cin, input_str);
		while (input_str.length() == 0)
		{
			std::cout << "empty field , please try again :";
			std::getline(std::cin, input_str);
		}
		this->contact_data[input_id] = input_str;
	}

    void    Contact::setinfos(void)
    {
		for (int i = 0; i < 5; i++)
		{
			ask_until_valid(i);
		}
    }

    void    Contact::print_all_contacts(void)
    {
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << this->id;
        for (int i = 0; i < 3; i++)
        {
            std::cout << "|";
			if (this->contact_data[i].length() > 10)
			{
				std::cout << this->contact_data[i].substr(0, 9);
				std::cout << ".";
			}
			else
			{
				std::cout << std::setw(10);
				std::cout << this->contact_data[i];
			}
        }
        std::cout << "|";
        std::cout << std::endl;
    }

	void	Contact::print_contact()
	{
		int i = 0;

		while (i < CONTACT_FIELDS)
		{
			std::cout << this->contact_fieldnames[i + 1];
			std::cout << ": ";
			std::cout << this->contact_data[i] <<std::endl;
			i++;
		}
	}
