#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	public:
		Zombie();
		Zombie(const std::string &name);
		~Zombie();
		void setName(const std::string &name);
		void announce(void);

	private:
		std::string name;
};

#endif //ZOMBIE_HPP
