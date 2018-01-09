#ifndef GREEN_HPP
#define GREEN_HPP

#include <iostream>
#include <string>

#include "node.cpp"

template <class T>
class green : public node<T>
{
public:
    virtual std::string as_string()
    {
        return node<T>::as_string() +  " green: " + std::to_string(this->key_value);
    }

};

#endif // GREEN_HPP
