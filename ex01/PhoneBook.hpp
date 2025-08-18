#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		lindex;
		bool	full;
	public:
		PhoneBook();
		~PhoneBook();
		void	add(std::string n, std::string ln, std::string nn, std::string num, std::string sec);
		void	display();
};

#endif