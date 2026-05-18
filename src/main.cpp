#include "Shop.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void	displayMenu();
void	addPhysical(Shop &shop);
void	addDigital(Shop &shop);
void	removeProduct(Shop &shop);
void	showProducts(Shop &shop);
void	searchTitle(Shop &shop);
void	filterByPlatform(Shop &shop);
void	sellUnits(Shop &shop);
void	showMostExpensive(Shop &shop);

int	main(void)
{
	Shop	shop;
	string	choice;
	
	while (!std::cin.eof())
	{
		displayMenu();
		getline(cin, choice);
		
		if (choice == "1")
		{
			addPhysical(shop);
		}
		else if (choice == "2")
		{
			addDigital(shop);
		}
		else if (choice == "3")
		{
			removeProduct(shop);
		}
		else if (choice == "4")
		{
			showProducts(shop);
		}
		else if (choice == "5")
		{
			searchTitle(shop);
		}
		else if (choice == "6")
		{
			filterByPlatform(shop);
		}
		else if (choice == "7")
		{
			sellUnits(shop);
		}
		else if (choice == "8")
		{
			showMostExpensive(shop);
		}
		else if (choice == "9")
		{
			cout << "Thank you for using Shop! Goodbye!" << endl;
			break;
		}
		else
		{
			cout << "Invalid choice! Please enter a number between 1 and 9." << endl;
		}
	}
	
	return (0);
}
