#include "Shop.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>

using std::cout;
using std::cin;
using std::endl;

// Función auxiliar para eliminar espacios al inicio y final
static string	trim(const string &str)
{
	size_t first = str.find_first_not_of(" \t\n\r");
	if (first == string::npos)
		return "";
	size_t last = str.find_last_not_of(" \t\n\r");
	return str.substr(first, (last - first + 1));
}

void	displayMenu()
{
	cout << endl << "==================== SHOP MENU ====================" << endl;
	cout << "1. Add physical game" << endl;
	cout << "2. Add digital game" << endl;
	cout << "3. Remove product" << endl;
	cout << "4. Show complete catalog" << endl;
	cout << "5. Search by title" << endl;
	cout << "6. Filter by platform" << endl;
	cout << "7. Sell units" << endl;
	cout << "8. Most expensive product" << endl;
	cout << "9. Exit" << endl;
	cout << "Enter your choice: ";
}

void	addPhysical(Shop &shop)
{
	string	title;
	string	platform;
	string	price;
	string	stock;

	cout << "Introduce title: ";
	getline(cin, title);
	title = trim(title);
	cout << "Introduce platform: ";
	getline(cin, platform);
	platform = trim(platform);
	cout << "Introduce price: ";
	getline(cin, price);
	cout << "Introduce stock: ";
	getline(cin, stock);

	try
	{
		physicalGame	newGame(title, platform, std::stoi(price), std::stoi(stock));
		shop.addProduct(newGame);
		cout << "Physical game added successfully!" << endl;
	}
	catch (const std::exception &e)
	{
		cout << "Error adding physical game: " << e.what() << endl;
	}
}

void	addDigital(Shop &shop)
{
	string	title;
	string	platform;
	string	price;
	string	gbSize;
	
	cout << "Introduce title: ";
	getline(cin, title);
	title = trim(title);
	cout << "Introduce platform: ";
	getline(cin, platform);
	platform = trim(platform);
	cout << "Introduce price: ";
	getline(cin, price);
	cout << "Introduce size (GB): ";
	getline(cin, gbSize);

	try
	{
		digitalGame	newGame(title, platform, std::stoi(price), std::stoi(gbSize));
		shop.addProduct(newGame);
		cout << "Digital game added successfully!" << endl;
	}
	catch (const std::exception &e)
	{
		cout << "Error adding digital game: " << e.what() << endl;
	}
}

void	removeProduct(Shop &shop)
{
	string	title;
	
	cout << "Introduce product title to remove: ";
	getline(cin, title);
	title = trim(title);
	shop.removeProduct(title);
	cout << "Product removed!" << endl;
}

void	showProducts(Shop &shop)
{
	cout << endl << "==================== CATALOG ====================" << endl;
	shop.showProducts();
	cout << "=================================================" << endl;
}

void	searchTitle(Shop &shop)
{
	string	input;
	Product	*toSearch;

	cout << "Introduce title to search: ";
	getline(cin, input);
	input = trim(input);
	toSearch = shop.searchByTitle(input);
	if (!toSearch)
	{
		cout << "No matches found for title: " << input << endl;
		return ;
	}
	cout << endl << toSearch->toString() << endl;
}

void	filterByPlatform(Shop &shop)
{
	string	platform;
	
	cout << "Introduce platform to filter: ";
	getline(cin, platform);
	platform = trim(platform);
	cout << endl << "==================== RESULTS ====================" << endl;
	shop.listByPlatform(platform);
	cout << "=================================================" << endl;
}

void	sellUnits(Shop &shop)
{
	string	title;
	string	amount;
	
	cout << "Introduce product title: ";
	getline(cin, title);
	title = trim(title);
	cout << "Introduce amount to sell: ";
	getline(cin, amount);
	
	try
	{
		shop.sellPhysical(title, std::stoi(amount));
		cout << "Sale completed successfully!" << endl;
	}
	catch (const std::exception &e)
	{
		cout << "Error during sale: " << e.what() << endl;
	}
}

void	showMostExpensive(Shop &shop)
{
	try
	{
		Product	expensive = shop.mostExpensive();
		cout << endl << "==================== MOST EXPENSIVE ====================" << endl;
		cout << expensive.toString() << endl;
		cout << "========================================================" << endl;
	}
	catch (const std::exception &e)
	{
		cout << "Error: " << e.what() << endl;
	}
}
