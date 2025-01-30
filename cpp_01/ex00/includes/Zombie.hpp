#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie(std::string initName);
};

#endif //ZOMBIE_HPP