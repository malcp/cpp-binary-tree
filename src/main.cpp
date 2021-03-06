#include <iostream>
#include <cstdlib>
#include "btree.cpp"
#include "node_factory.cpp"
#include "node/node.cpp"

using namespace std;

int main(void)
{
    cout << "Hello World" << endl;

    srand(time(NULL));
    btree<int> *tree = new btree<int>(new node_factory<int>());
    for (int i = 0; i < 5; i++) {
        tree->insert(rand() % 100);
    }

    /*
    tree.insert(10);
    tree.insert(6);
    tree.insert(14);
    tree.insert(5);
    tree.insert(8);
    tree.insert(11);
    tree.insert(18);
    */
    tree->print();

	cout << endl << "num nodes: " << node<int>::get_num_nodes() << endl;

    return(0);
}
