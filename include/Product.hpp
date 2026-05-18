#pragma once
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;


class Product
{
	protected:
		string	_title;
		string	_platform;
		int			_price;
	public:
		Product();
		virtual ~Product();

		string			getTitle() const;
		string			getPlatform() const;
		void			setTitle(string &title);
		void			setPlatform(string &platform);

		virtual string	toString() const;
		virtual int			finalPrice() const;
};
