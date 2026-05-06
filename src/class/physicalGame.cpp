#include "physicalGame.hpp"


physicalGame::physicalGame()
{
};

physicalGame::~physicalGame()
{
}

int	physicalGame::getStock() const
{
	return (_stock);
}

std::string	physicalGame::toString() const
{
	std::string	new_str;

	new_str = Product::toString();
	new_str.append("\nStock: ");
	new_str.append(std::to_string(_stock));
	return (new_str);
}

void	physicalGame::sell()
{
	if (_stock > 0)
		_stock--;
	else
		std::cerr << "Not enough stock!" << std::endl;
}
