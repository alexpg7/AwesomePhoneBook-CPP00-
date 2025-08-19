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
	if (index == 7)
		full = true;
	this->lindex = (this->lindex + 1) % 8;
	return ;
}

void	PhoneBook::display(void)
{
	int	num;

	num = this->lindex * (this->full == false) + 8 * (this->full == true);
	std::cout << "   INDEX  |" << "FIRST NAME|" << " LAST NAME|" << " NICKNAME " << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	for (int k = 0; k < num; k++)
	{
		std::cout << "         "  << k + 1 << "|";
		std::cout << this->contacts[k].first(true) << "|";
		std::cout << this->contacts[k].last() << "|";
		std::cout << this->contacts[k].nick() << std::endl;
	}
	return ;
}

int	PhoneBook::showindex(int index)
{
	contacts[index - 1].show();
	return (index - 1);
}

int	PhoneBook::warning()
{
	std::string	res;

	std::cout << "The PhoneBook is full. If you add a new contact (";
	std::cout << lindex + 1 << ") " << contacts[lindex].first(false);
	std::cout << " will be rewritten." << std::endl;
	std::cout << "Do you want to proceed? (y/n)" << std::endl;
	while (1)
	{
		if (!std::getline(std::cin, res))
			return (-1);
		if (res == "y")
			return (1);
		else if (res == "n")
			return (0);
		else
			std::cout << "Invalid option." << std::endl;
	}
	return (0);
}
