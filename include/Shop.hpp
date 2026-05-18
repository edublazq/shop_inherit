#pragma once
#include "digitalGame.hpp"
#include "physicalGame.hpp"

#include <vector>

class Shop
{
	private:
		std::vector<Product>	_products;
	public:
		Shop();
		~Shop();
		void	addProduct(Product &product);
		void	removeProduct(string &title);
		void	showProducts();
		Product*	searchByTitle(string title);
		void	listByPlatform(string platform);
		Product	mostExpensive();
		void	sellPhysical(string &title, int amount);
};
