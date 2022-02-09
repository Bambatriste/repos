#include "ShrubberyCreationForm.hpp"
#include <fstream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm was built by default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
:
Form ("ShrubberyCreationForm", 145, 137, target)
{
	std::cout << "ShrubberyCreationForm was built by default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src )
:
Form(src)
{

}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	Form::operator=(rhs);
	return *this;
}

std::ostream &			operator<<( std::ostream &o, ShrubberyCreationForm const &i)
{
	o << "Form = " << i.getName() << "; Min Req to sign  = " 
	<< i.getSignReq() << "; min req to exec = " << i.getExecReq() << ";is signed = " << i.getIsSigned();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{

	std::ofstream ofs;
	std::string ofs_name;
	try
	{
		if (!getIsSigned())
			throw FormNotSignedException();
		else if (executor.getGrade() > getExecReq())
			throw GradeTooLowException();
		ofs_name = getTarget() + "_shrubbery";
		ofs.open(ofs_name.c_str());
		if (!ofs.is_open())
			throw CantOpenFileException();
		else
		{

    		ofs << "                         ( (  .(     /.                      \n";  
        	ofs << "                    /**  .( (   (   (    (                   \n";        
         	ofs << "                /(   (. ((( (  **/ (.   ,. . (               \n";       
        	ofs << "                 (/((/. *(  /( (((/*.    .&  ( .             \n";        
    		ofs << "             (/(((/((/// ,* #   /.(/(  & (  ( (  ,((         \n";         
    		ofs << "            ((/   (./( .(.(   (((,. &( (,* &(  * ( (/        \n";         
    		ofs << "           //(/ (. , ,( (. / *& % @.  , (// / , (*(          \n";       
        	ofs << "           *   ((/**//( @    / &((    .( *  .  **(  *        \n";      
    		ofs << "            ((.(( *    / (/(((@ &&/(  ( ( %* ( ,/(/ .((      \n";      
    		ofs << "           (((//  (%,. /( ,.&*((& /( ** (, ,&##(,(  *        \n";     
    		ofs << "           ((  ( %&  / ,%.** @&&&  (  .#&  ,(/( ((*,(        \n";    
    		ofs << "            (((*, / (( @&**/(@ &&((((,& (( (%( ( (**         \n";   
        	ofs << "              (/ (((.(/(( @% &@&( .&%(( ((..  /,.(           \n"; 
        	ofs << "                           %@&@&&&&%%&@@*..( ,  ,(           \n";
    		ofs << "                             ,@&&&&&(/( (( ((                \n";
    		ofs << "                              @&&&%                          \n";     
        	ofs << "                             ,&&@                            \n";        
        	ofs << "                             &&&&&                           \n";        
        	ofs << "       .,,**///((##%%&&&&&&&&&&&&&&&&&&&&%%%##((//**,..   	 ";
			ofs.close();
		}
		std::cout << "shrubbery form was executed" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << executor.getName() << " couldn't execute form : " << this->getName() << " : "<< e.what() << '\n';
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */