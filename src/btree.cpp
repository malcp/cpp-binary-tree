#ifndef BTREE_CPP
#define BTREE_CPP

#include <cstddef>
#include <iostream>
#include <string>

#include "node_factory.cpp"

#include "node/node.cpp"
#include "node/green.cpp"

template <class T>
class btree
{
private:
    node_factory<T> *factory;

public:
    btree(node_factory<T> *factory): root(NULL)
    {
        this->factory = factory;
    }

    ~btree()
    {
        destroy_tree();
    }

    void insert(T key)
    {
        if (root == NULL) {
            root = factory->get_instance();
            root->key_value = key;
            root->left = NULL;
            root->right = NULL;
        } else {
            insert(key, root);
        }
    }

    node<T> *search(T key)
    {
        return search(key, root);
    }

    void destroy_tree()
    {
        destroy_tree(root);
    }

    void print()
    {
        print_tree(root);
    }

private:
    void destroy_tree(node<T> *leaf)
    {
        if (leaf != NULL) {
            destroy_tree(leaf->left);
            destroy_tree(leaf->right);

            // std::cout << "destroying key: " << leaf->key_value << std::endl;
            delete leaf;
        }
    }

    void insert(T key, node<T> *leaf)
    {
        if (key < leaf->key_value) {
            if (leaf->left != NULL) {
                insert(key, leaf->left);
            } else {
                leaf->left = factory->get_instance();
                leaf->left->key_value = key;
                leaf->left->left = NULL;
                leaf->left->right = NULL;
            }
        } else if (key >= leaf->key_value) {
            if (leaf->right != NULL) {
                insert(key, leaf->right);
            } else {
                leaf->right = factory->get_instance();
                leaf->right->key_value = key;
                leaf->right->left = NULL;
                leaf->right->right = NULL;
            }
        }
    }

    node<T> *search(T key, node<T> *leaf)
    {
        if (leaf != NULL) {
            if (leaf->key_value == key) {
                return leaf;
            }
            if (key < leaf->key_value) {
                return search(key, leaf->left);
            } else {
                return search(key, leaf->right);
            }
        }

        return NULL;
    }

    void print_tree(node<T> *leaf, int padding = 0)
    {
        if (leaf != NULL) {
            for (int i = 0; i < padding; i++) {
                if (i < padding-1) {
                    std::cout << "    ";
                } else if (i == padding-1) {
                    std::cout << "|";
                }
            }

            if (padding > 0) {
                std::cout << "__ ";
            }

            std::string node = leaf->as_string();
            std::cout << node << std::endl;

            print_tree(leaf->left, padding + 1);
            print_tree(leaf->right, padding + 1);
        }
    }

    node<T> *root;
};

#endif // BTREE_CPP
