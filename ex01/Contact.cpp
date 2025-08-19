#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact()
{
	return ;
}

void	Contact::set(std::string n, std::string ln, std::string nn, std::string num, std::string sec)
{
	this->firstname = n;
	this->lastname = ln;
	this->nickname = nn;
	this->number = num;
	this->secret = sec;
	return ;
}

std::string	Contact::first(bool disp)
{
	std::string	ret;
	int			len;
	int			k;

	len = firstname.length();
	if (disp == true)
	{
		for (k = 0; k < 10 - len; k++)
			ret += " ";
	}
	for (k = 0; k < len && firstname[k] && k < 10; k++)
		ret += firstname[k];
	if (k == 10 && len > 10)
		ret[9] = '.';
	return (ret);
}

std::string	Contact::last()
{
	std::string	ret;
	int			len;
	int			k;

	len = lastname.length();
	for (k = 0; k < 10 - len; k++)
		ret += " ";
	for (k = 0; k < len && lastname[k] && k < 10; k++)
		ret += lastname[k];
	if (k == 10 && len > 10)
		ret[9] = '.';
	return (ret);
}

std::string	Contact::nick()
{
	std::string	ret;
	int			len;
	int			k;

	len = nickname.length();
	for (k = 0; k < 10 - len; k++)
		ret += " ";
	for (k = 0; k < len && nickname[k] && k < 10; k++)
		ret += nickname[k];
	if (k == 10 && len > 10)
		ret[9] = '.';
	return (ret);
}

void	Contact::show()
{
	std::cout << "FIRST NAME: " << firstname << std::endl;
	std::cout << "LAST NAME: " << lastname << std::endl;
	std::cout << "NICKNAME: " << nickname << std::endl;
	std::cout << "PHONE NUMBER: " << number << std::endl;
	std::cout << "DARKEST SECRET: " << secret << std::endl;
}
