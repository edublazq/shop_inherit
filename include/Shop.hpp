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
		void	addProduct(Product product);
		void	removeProduct(std::string title);
		void	showProducts();
		Product*	searchByTitle(std::string title);
		void	listByPlatform(std::string platform);
		Product	mostExpensive();
		void	sellPhysical(std::string &title, int amount);
};
