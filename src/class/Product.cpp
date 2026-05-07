#include "Product.hpp"

Product::Product()
{
	_title = "Mafia III";
	_platform = "PS4";
	_price = 40;
}

Product::~Product()
{
}

string	Product::toString() const
{
	string	new_str;

	new_str.append("Title: ");
	new_str.append(_title);
	new_str.append("\nPlatform: ");
	new_str.append(_platform);
	new_str.append("\nPrice: ");
	new_str.append(std::to_string(_price));
	return (new_str);
}

int	Product::finalPrice() const
{
	return (_price + (_price * 0.21));
}

string	Product::getTitle() const
{
	return (_title);
}

void	Product::setTitle(string &title)
{
	_title = title;
}

string	Product::getPlatform() const
{
	return (_platform);
}

void	Product::setPlatform(string &platform)
{
	_platform = platform;
}
