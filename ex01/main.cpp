#include "PhoneBook.hpp"

std::string	ft_trimtext(std::string comm)
{
	int			i = 0;
	std::string	str;

	while (comm[i])
	{
		if (comm[i] != ' ' && comm[i] != '\t')
			str += comm[i];
		i++;
	}
	return (str);
}

std::string	ft_trimfirst(std::string comm)
{
	int			i = 0;
	std::string	str;

	while (comm[i] == ' ' || comm[i] == '\t')
		i++;
	str = &comm[i];
	return (str);
}

int	ft_read(std::string read, int lindex)
{
	if (read.length() == 1)
	{
		if (read[0] > (char)(lindex + '0') || read[0] < '1')
			return (-1);
		return ((int)(read[0] - '0'));
	}
	return (-1);
}

int	ft_search(PhoneBook &book)
{
	std::string	read;
	int			lindex;
	int			index;

	if (book.lindex == 0 && book.full == false)
	{
		std::cout << "You have no contacts to search." << std::endl;
		return (0);
	}
	lindex = book.lindex * (book.full == false) + 8 * (book.full == true);
	while (1)
	{
		std::cout << "Choose a contact (by number):" << std::endl;
		book.display();
		if (!std::getline(std::cin, read))
			return (-1);
		index = ft_read(read, lindex);
		if (index == -1)
			std::cout << "Invalid index." << std::endl;
		else
			return (book.showindex(index));
	}
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

int	ft_add(PhoneBook &book)
{
	std::string	name;
	std::string	lastname;
	std::string	nickname;
	std::string	number;
	std::string	secret;
	int			check;

	if (book.full == true)
	{
		check = book.warning();
		if (check == -1)
			return (-1);
		else if (check == 0)
			return (0);
	}
	while (1)
	{
		std::cout << "Introduce NAME:" << std::endl;
		if (!std::getline(std::cin, name))
			return (-1);
		name = ft_trimfirst(name);
		if (name.length() < 1)
			std::cout << "This field cannot be empty." << std::endl;
		else
			break ;
	}
	while (1)
	{
		std::cout << "Introduce LAST NAME:" << std::endl;
		if (!std::getline(std::cin, lastname))
			return (-1);
		lastname = ft_trimfirst(lastname);
		if (lastname.length() < 1)
			std::cout << "This field cannot be empty." << std::endl;
		else
			break ;
	}
	while (1)
	{
		std::cout << "Introduce NICKNAME:" << std::endl;
		if (!std::getline(std::cin, nickname))
			return (-1);
		nickname = ft_trimfirst(nickname);
		if (nickname.length() < 1)
			std::cout << "This field cannot be empty." << std::endl;
		else
			break ;
	}
	while (true)
	{
		std::cout << "Introduce PHONE NUMBER:" << std::endl;
		if (!std::getline(std::cin, number))
			return (-1);
		number = ft_trimtext(number);
		check = ft_checknum(number);
		if (check == 0)
			break ;
		else if (check == 1)
			std::cout << "Invalid PHONE NUMBER (you must write a number)." << std::endl;
		else if (check == 2)
			std::cout << "Invalid PHONE NUMBER (must be of 9 digits)." << std::endl;
	}
	while (1)
	{
		std::cout << "Introduce DARKEST SECRET:" << std::endl;
		if (!std::getline(std::cin, secret))
			return (-1);
		secret = ft_trimfirst(secret);
		if (secret.length() < 1)
			std::cout << "This field cannot be empty." << std::endl;
		else
			break ;
	}
	book.add(name, lastname, nickname, number, secret);
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
	int			ret;

	while (1)
	{
		ret = 0;
		std::cout << "Write a command (ADD, SEARCH, EXIT):" << std::endl;
		if (!std::getline(std::cin, comm))
		{
			std::cout << "Something went wrong..." << std::endl;
			return (ft_exit());
		}
		comm = ft_trimfirst(comm);
		if (comm == "EXIT")
			return (ft_exit());
		else if (comm == "ADD")
			ret = ft_add(book);
		else if (comm == "SEARCH")
			ret = ft_search(book);
		else
			std::cout << "Invalid command." << std::endl;
		if (ret == -1)
		{
			std::cout << "Something went wrong..." << std::endl;
			return (ft_exit());
		}
	}
	return (0);
}
