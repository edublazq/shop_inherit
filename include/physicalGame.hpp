#pragma once
#include "Product.hpp"


class physicalGame : public Product
{
	private:
		int	_stock;
	public:
		physicalGame();
		physicalGame(string &title, string &platform, int price, int stock);
		~physicalGame();

		int	physicalGame::getStock() const;
		string	toString() const;
		void		sell();
};
