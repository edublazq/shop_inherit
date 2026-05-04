#pragma once
#include <iostream>
#include <string>

class Product
{
	protected:
		std::string	_title;
		std::string	_platform;
		int			_price;
	public:
		Product();
		~Product();

		virtual std::string	toString() const;
		virtual int			finalPrice() const;
};
