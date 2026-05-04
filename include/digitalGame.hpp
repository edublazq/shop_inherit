#pragma once
#include "Product.hpp"

class digitalGame : public Product
{
	private:
		int	_gbSize;
	public:
		digitalGame();
		~digitalGame();
		std::string	toString() const;
		int			finalPrice() const;
};
