#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->lindex = 0;
	this->full = false;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add(std::string n, std::string ln, std::string nn, std::string num, std::string sec)
{
	int	index = this->lindex;

	this->contacts[index].set(n, ln, nn, num, sec);
	std::cout << this->contacts[index].first(false) << " has been added." << std::endl;
	if (index < 8)
		this->lindex++;
	return ;
}

void	PhoneBook::display(void)
{
	int	num;

	num = this->lindex * (this->full == false) + 8 * (this->full == true);
	for (int k = 0; k < num; k++)
	{
		std::cout << k + 1 << "         |";
		std::cout << this->contacts[k].first(true) << "|";
		std::cout << this->contacts[k].last() << "|";
		std::cout << this->contacts[k].nick() << std::endl;
	}
	return ;
}