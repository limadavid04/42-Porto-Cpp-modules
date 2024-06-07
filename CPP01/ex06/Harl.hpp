#ifndef HARL_HPP
#define HARL_HPP

#include <string>

typedef enum {
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	DEFAULT
} t_levels;

class Harl {

	public:
		void complain( std::string level );
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
};
#endif
