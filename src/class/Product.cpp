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

std::string	Product::toString() const
{
	std::string	new_str;

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
