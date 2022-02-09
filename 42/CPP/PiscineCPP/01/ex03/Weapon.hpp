#ifndef WEAPON_HPP
 #define WEAPON_HPP
 
 #include <string>

 class Weapon
 {
 	private:
 		std::string _name;
 	public:
 		Weapon(std::string name);
		~Weapon();
		std::string		getType() const;
		void			setType(std::string name);
 };

#endif

 
