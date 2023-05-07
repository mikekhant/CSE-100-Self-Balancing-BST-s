#include <iostream>
#include "BinaryTree.h"
using namespace std;

/**
 * Test BinaryTree balanceFactors() function
 */
int main() {
    BinaryTree tree(6);
    tree.newick();
    unordered_map<int,int> bf = tree.balanceFactors();
    for(auto pair : bf) {
        cout << pair.first << '\t' << pair.second << endl;
    }
    BinaryTree tree2(2);
    tree2.newick();
    unordered_map<int,int> bf2 = tree2.balanceFactors();
    for(auto pair : bf2) {
        cout << pair.first << '\t' << pair.second << endl;
    }
    return 0;
}
