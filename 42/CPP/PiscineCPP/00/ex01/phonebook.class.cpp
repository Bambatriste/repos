#include <iostream>
#include "phonebook.class.hpp"

Phonebook::Phonebook(int nb_user) : nb_user(nb_user)
{
    return;
}

Phonebook::~Phonebook(void)
{
    return;
}

void Phonebook::add_contact()
{
    if (this->nb_user < 8)
    {
        this->contacts[this->nb_user].setinfos();
		this->contacts[this->nb_user].id = get_user_nb();
        this->nb_user++;
    }
	else
	{
		std::cout << "Sorry , the phonebook is full you can't add more contacts" << std::endl;
	}
}

int Phonebook::search_contact()
{
	std::string user_input_id;
	int search_index;
	if (this->nb_user == 0)
	{
		std::cout << "No contacts founds in the Phonebook" << std::endl;
		return (0);
	}
	for (int i = 0; i < 4; i++)
	{
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << contacts[0].contact_fieldnames[i];
	}
	std::cout << "|";
	std::cout << std::endl;
    for (int i = 0; i < this->nb_user; i++)
    {
        contacts[i].print_all_contacts();
    }
	std::cout << "Enter the ID of the contact you want to display :";
	std::getline(std::cin, user_input_id);
	while (user_input_id.length() != 1 || user_input_id[0] > (this->nb_user + '0' - 1) || (user_input_id[0] < 0))
	{
		std::cout << "wrong input , please enter a valid id :";
		std::getline(std::cin, user_input_id);
	}
	search_index = user_input_id[0] - '0';
	contacts[search_index].print_contact();

    return (0);
}

int Phonebook::get_user_nb()
{
	return (this->nb_user);
}

int Phonebook::wait_cmd()
{
	std::string new_cmd;

	while (new_cmd.compare("EXIT") != 0)
	{
		std::cout << "please enter a command (SEARCH, ADD or EXIT) :";
		std::getline(std::cin, new_cmd);
		if (new_cmd.compare("ADD") == 0)
			this->add_contact();
		if (new_cmd.compare("SEARCH") == 0)
			this->search_contact();
	}
	return (0);
}
