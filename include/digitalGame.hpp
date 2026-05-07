#pragma once
#include "Product.hpp"

class digitalGame : public Product
{
	private:
		int	_gbSize;
	public:
		digitalGame();
		digitalGame(string &title, string &platform, int price, int gb);
		~digitalGame();
		string	toString() const;
		int			finalPrice() const;
};
