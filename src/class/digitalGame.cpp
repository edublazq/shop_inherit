#include "digitalGame.hpp"

digitalGame::digitalGame()
{
}

digitalGame::~digitalGame()
{
}

std::string	digitalGame::toString() const
{
	std::string new_str;

	new_str = Product::toString();
	new_str.append("\nSize (GB): ");
	new_str.append(std::to_string(_gbSize));
	return (new_str);
}

int	digitalGame::finalPrice() const
{
	return (_price - (_price * 0.05));
}
