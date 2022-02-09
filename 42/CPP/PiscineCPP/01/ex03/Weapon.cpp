 #include "Weapon.hpp"
 
 Weapon::Weapon(std::string name)
 {
	 this->_name = name;
 }
 
 Weapon::~Weapon()
 {
 }

std::string Weapon::getType() const
 {
	 return (this->_name);
 }

 void	Weapon::setType(std::string name)
 {
	 this->_name = name;
 }
 
