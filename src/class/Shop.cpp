#include "Shop.hpp"

Shop::Shop()
{
}

Shop::~Shop()
{
}

void	Shop::addProduct(Product &product)
{
	_products.push_back(product);
}

void	Shop::removeProduct(string &title)
{
	for (auto it = _products.begin(); it != _products.end(); it++)
	{
		if (it->getTitle() == title)
		{
			_products.erase(it);
			return ;
		}
	}
}

void	Shop::showProducts()
{
	for (auto it = _products.begin(); it != _products.end(); it++)
	{
		cout << it->toString() << std::endl << std::endl;
	}
}

Product*	Shop::searchByTitle(string title)
{
	for (auto it = _products.begin(); it != _products.end(); it++)
	{
		if (it->getTitle() == title)
			return &(*it);
	}
	return (nullptr);
}

void	Shop::listByPlatform(string platform)
{
	for (auto it = _products.begin(); it != _products.end(); it++)
	{
		if (it->getPlatform() == platform)
		{
			cout << std::endl << it->toString() << std::endl;
		}
	}		
}

Product	Shop::mostExpensive()
{
	Product	*expensive = nullptr;

	for (auto it = _products.begin(); it != _products.end(); it++)
	{
		if (!expensive || it->finalPrice() > expensive->finalPrice())
			expensive = &(*it);
	}
	if (!expensive)
		throw	std::runtime_error("No products in shop!");
	return (*expensive);
}

void	Shop::sellPhysical(string &title, int amount)
{
	physicalGame	*game = 
		dynamic_cast<physicalGame*>(searchByTitle(title));
	
	if (!game)
	{
		std::cerr << "Not game found!" << std::endl;
		return ;
	}
	for (int i = 0; i < amount; i++)
	{
		game->sell();
		if (game->getStock() <= 0)
		{
			cout << "All stock selled!" << std::endl;
			return ;
		}
	}
}
