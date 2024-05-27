#include <BitcoinExchange.hpp>

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: invalid usage!\nCorrect usage: ./btc <path_to_database>" << std::endl;
		return 1;
	}
	std::string database (av[1]);
	if (database.empty()) {
		std::cerr << "Error: empty database file input!" << std::endl;
		return 1;
	}
	BitcoinExchange exchange(database);
	exchange.run();
	return 0;
}