#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "contact.class.hpp"

class Phonebook
{
    public:
        Phonebook(int nb_users);
        ~Phonebook(void);
        void add_contact(void);
        int search_contact(void);
		int wait_cmd(void);
		int get_user_nb();
    private:
        Contact contacts[8];
        int nb_user;
};

#endif
