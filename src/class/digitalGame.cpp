#include "digitalGame.hpp"

digitalGame::digitalGame()
{
}

digitalGame::digitalGame(string &title, string &platform, int price, int gb)
{
	_title = title;
	_platform = platform;
	_price = price;
	_gbSize = gb;
}

digitalGame::~digitalGame()
{
}

string	digitalGame::toString() const
{
	string new_str;

	new_str = Product::toString();
	new_str.append("\nSize (GB): ");
	new_str.append(std::to_string(_gbSize));
	return (new_str);
}

int	digitalGame::finalPrice() const
{
	return (_price - (_price * 0.05));
}
