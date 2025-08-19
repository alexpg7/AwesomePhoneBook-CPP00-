#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
	public:
		PhoneBook();
		~PhoneBook();
		void	add(std::string n, std::string ln, std::string nn, std::string num, std::string sec);
		void	display();
		int		showindex(int index);
		int		warning();
		int		lindex;
		bool	full;
};

#endif
