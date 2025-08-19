#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	number;
		std::string	secret;
	public:
		Contact();
		~Contact();
		void		set(std::string n, std::string ln, std::string nn, std::string num, std::string sec);
		std::string	first(bool disp);
		std::string	last();
		std::string	nick();
		void		show();
};

#endif
