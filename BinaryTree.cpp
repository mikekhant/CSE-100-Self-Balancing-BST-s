#include "BinaryTree.h"

/**
 * Implement balanceFactors() correctly
 */
 

// function to calculate height of subtrees to 
// assist in calculation of balance factor 
int treeheight(BinaryTree::Node* node, unordered_map<int,int> &map) {
    int leftheight, rightheight;
    if(node == nullptr) {
        return 0;
    }
    else {
        if(node->leftChild != nullptr ) {
            leftheight = treeheight(node->leftChild, map);
        }
        if(node->rightChild != nullptr) {
            rightheight = treeheight(node->rightChild, map);
        }
    }

    if(node->leftChild == nullptr && node->rightChild == nullptr) {
        return 0;
    }

    if(leftheight > rightheight) {
        return leftheight + 1;
    }
    else return rightheight + 1;
}

// function that will use treeheight() function to calculate balance factor 
// of inputted node
void bf(BinaryTree::Node* node, unordered_map<int,int> &map) {
    // get height of left subtree and right subtree
    int leftside = treeheight(node->leftChild, map);
    int rightside = treeheight(node->rightChild, map);

    // height of right subree - height of left subtree 
    int balancefactor = rightside - leftside;

    // add node and balance factor to map
    map[node->label] = balancefactor;
}

// function to traverse through whole binary tree
void traverse(BinaryTree::Node* node, unordered_map<int,int> &map) {
    //if right or left child exists, recursively call function 
    if(node->rightChild != nullptr) {
        traverse(node->rightChild, map);
    }
    if(node->leftChild != nullptr) {
        traverse(node->leftChild, map);
    }

    // call bf function to calculate balancefactor
    bf(node, map);
}


unordered_map<int,int> BinaryTree::balanceFactors() {
    unordered_map<int,int> map;
    traverse(root, map);
    return map;
}

