#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>
#include <string_view>

void PrintMsg(std::string msg);

class Harl {

	private:

		static constexpr int	kMaxNum = 4;
		static constexpr std::string_view levels_[kMaxNum] = {"DEBUG", "INFO", "WARNING", "ERROR"};

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:
		Harl();
		~Harl();
		void filter(std::string level);

};

#endif