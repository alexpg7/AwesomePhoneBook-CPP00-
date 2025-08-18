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

	len = this->firstname.length();
	for (k = 0; k < 10 && firstname[k]; k++)
		ret += this->firstname[k];
	if (k == 10 && len > 10)
		ret[9] = '.';
	if (k <= 9 && disp == true)
	{
		while (k <= 9)
		{
			ret += ' ';
			k++;
		}
	}
	return (ret);
}

std::string	Contact::last()
{
	std::string	ret;
	int			len;
	int			k;

	len = this->lastname.length();
	for (k = 0; k < 10 && lastname[k]; k++)
		ret += this->lastname[k];
	if (k == 10 && len > 10)
		ret[9] = '.';
	if (k <= 9)
	{
		while (k <= 9)
		{
			ret += ' ';
			k++;
		}
	}
	return (ret);
}

std::string	Contact::nick()
{
	std::string	ret;
	int			len;
	int			k;

	len = this->nickname.length();
	for (k = 0; k < 10 && nickname[k]; k++)
		ret += this->nickname[k];
	if (k == 10 && len > 10)
		ret[9] = '.';
	if (k <= 9)
	{
		while (k <= 9)
		{
			ret += ' ';
			k++;
		}
	}
	return (ret);
}