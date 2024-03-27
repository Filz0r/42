#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	public:
		Zombie(const std::string &name);
		~Zombie();
		void announce(void);

	private:
		std::string name;
};

#endif //ZOMBIE_HPP
