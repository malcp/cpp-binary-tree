#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <string>

template <class T>
class node
{
private:
    static size_t num_nodes;
public:
    T key_value;
    node *left;
    node *right;

	node<T>()
	{
		node<T>::num_nodes++;
	}

    virtual std::string as_string()
    {
        return "node: " + std::to_string(key_value);
    }

	static size_t get_num_nodes()
	{
		return node<T>::num_nodes;
	}
};

template <>
size_t node<int>::num_nodes = 0;


#endif // NODE_HPP
