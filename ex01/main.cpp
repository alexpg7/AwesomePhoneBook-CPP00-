#include "PhoneBook.hpp"

int	ft_search(PhoneBook *book)
{
	(*book).display();
	return (0);
}

int	ft_checknum(std::string number)
{
	for (int k = 0; number[k]; k++)
	{
		if (number[k] > '9' || number[k] < '0')
			return (1);
	}
	if (number.length() != 9)
		return (2);
	return (0);
}

int	ft_add(PhoneBook *book)
{
	std::string	name;
	std::string	lastname;
	std::string	nickname;
	std::string	number;
	std::string	secret;
	int			check;

	std::cout << "Introduce NAME:" << std::endl;
	if (!std::getline(std::cin, name))
		return (-1);
	std::cout << "Introduce LAST NAME:" << std::endl;
	if (!std::getline(std::cin, lastname))
		return (-1);
	std::cout << "Introduce NICKNAME:" << std::endl;
	if (!std::getline(std::cin, nickname))
		return (-1);
	while (true)
	{
		std::cout << "Introduce PHONE NUMBER:" << std::endl;
		if (!std::getline(std::cin, number))
			return (-1);
		check = ft_checknum(number);
		if (check == 0)
			break ;
		else if (check == 1)
			std::cout << "Invalid PHONE NUMBER (you must write a number)." << std::endl;
		else if (check == 2)
			std::cout << "Invalid PHONE NUMBER (must be of 9 digits)." << std::endl;
	}
	std::cout << "Introduce DARKEST SECRET:" << std::endl;
	if (!std::getline(std::cin, secret))
		return (-1);
	(*book).add(name, lastname, nickname, number, secret);
	return (0);
}

int	ft_exit(void)
{
	std::cout << "Exiting PhoneBook..." << std::endl;
	return (0);
}

int	main(void)
{
	PhoneBook	book;
	std::string	comm;

	while (1)
	{
		std::cout << "Write a command: (ADD, SEARCH, EXIT)" << std::endl;
		std::getline(std::cin, comm);
		if (comm == "EXIT")
			return (ft_exit());
		else if (comm == "ADD")
		{
			if (ft_add(&book) == -1)
			{
				std::cout << "Something went wrong..." << std::endl;
				return (ft_exit());
			}
		}
		else if (comm == "SEARCH")
		{
			if (ft_search(&book) == -1)
			{
				std::cout << "Something went wrong..." << std::endl;
				return (ft_exit());
			}
		}
		else
			std::cout << "Invalid command." << std::endl;
	}
	return (0);
}