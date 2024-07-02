#include "BitcoinExchange.hpp"

int main (int argc, char **argv)
{
	(void)argc;
	(void)argv;
	std::string db = argv[1];
	BitcoinExchange ex(db);
	ex.print_db();
}
