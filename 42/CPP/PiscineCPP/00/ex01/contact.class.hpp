#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>
#include <iomanip>

#define FIRST_NAME 0
#define LAST_NAME 1
#define NICKNAME 2
#define PHONE_NBR 3
#define SECRET 4
#define CONTACT_FIELDS 5

class Contact
{
    public:
        Contact(void);
        ~Contact(void);
		int id; //put that in private
        void            setinfos();
        void            print_all_contacts();
		void			print_contact();
		void			ask_until_valid(int input);
        std::string contact_fieldnames[6];
    private :
        std::string contact_data[CONTACT_FIELDS];
		
};
#endif

