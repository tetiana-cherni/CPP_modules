#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

void PrintMsg(std::string msg);

class Harl {

	private:

		int	kNumCompl = 4;

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

		
		typedef struct s_level_complain{
			std::string level_;
			void (Harl::*ptrToMemberFn)(void);
		} t_level_complain;

	public:
		Harl();
		~Harl();
		void complain( std::string level );

};

#endif