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
		virtual ~Product();

		std::string			getTitle() const;
		std::string			getPlatform() const;
		void				setTitle(std::string &title);
		void				setPlatform(std::string &platform);

		virtual std::string	toString() const;
		virtual int			finalPrice() const;
};
