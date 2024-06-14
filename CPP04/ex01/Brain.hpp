#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
	public:
		Brain();
		Brain(const Brain &cpy);
		Brain & operator=( const Brain & src);
		virtual ~Brain();

	private:
		std::string ideas[100];
};
#endif
