#ifndef INCLUDE_WORLD_HPP
#define INCLUDE_WORLD_HPP

// you can do funky stuff with the iterator
//#include <iterator>
#include <set>

class World {
public:

    int spawn();
    void despawn();
    void has_component();
    void get_components();

private:

    unsigned int m_id_count;
    std::set<int> m_dead_entities;


};

#endif