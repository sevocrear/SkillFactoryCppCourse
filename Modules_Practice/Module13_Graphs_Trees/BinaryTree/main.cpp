#include "include/BinaryTree.hpp"
int main() 
{   
    BinaryTree tree;
    
    tree.addInt(5);
    tree.addInt(3);
    tree.addInt(7);
    tree.addInt(2);
    tree.addInt(4);
    tree.addInt(1);
    tree.addInt(6);
    tree.addInt(8);
    tree.findNodeByData(8);
    tree.findNodeByData(9);
    tree.findNodeByData(1);
    // tree.delInt(1);
}