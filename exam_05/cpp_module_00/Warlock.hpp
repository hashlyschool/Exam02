#pragma once

#include <string>
#include <iostream>

class Warlock
{
	public:
		Warlock(std::string name, std::string title);
		~Warlock();

		std::string	getName() const;
		std::string	getTitle() const;

		void	setTitle(std::string const &title);

		void	introduce() const;
	private:
		std::string	name;
		std::string	title;
};
