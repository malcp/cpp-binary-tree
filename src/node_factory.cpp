#ifndef NODE_FACTORY_HPP
#define NODE_FACTORY_HPP

#include <iostream>
#include <string>

#include "node/node.cpp"
#include "node/green.cpp"

template <class T>
class node_factory
{
public:
    node<T>* get_instance()
    {
        return new green<T>;
    }
};

#endif // NODE_FACTORY_HPP
