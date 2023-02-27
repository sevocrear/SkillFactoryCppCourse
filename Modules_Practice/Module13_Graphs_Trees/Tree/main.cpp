#include "include/Tree.hpp"
int main()
{
    Tree tree;
    
    tree.setRoot(2); // задали корень
    tree.addNode(2,3); // добавляем узлы
    tree.addNode(2,0);
    tree.addNode(2,1);
    tree.addNode(1,4);
    tree.addNode(1,7);
    // tree.addNode(4,5);
    // tree.addNode(4,6);
    tree.delNode(4); // удалили узел 4
    tree.showNode(1);
    // tree.showNode(4);
    return 0;
}