#pragma once
#include "Product.hpp"


class physicalGame : public Product
{
	private:
		int	_stock;
	public:
		physicalGame();
		~physicalGame();

		int	physicalGame::getStock() const;
		std::string	toString() const;
		void		sell();
};
