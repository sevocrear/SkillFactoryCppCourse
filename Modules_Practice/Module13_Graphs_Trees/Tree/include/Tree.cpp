
#include "Tree.hpp"
Tree::Node::Node(int _number, Node* _parent): 
    number(_number), 
    parent(_parent),
    childCount(0) { 
    
}
//
Tree::Node::~Node() {
   for(int i=0;i < childCount;i++)
   {
       delete children[i];
   }
}
//
void Tree::Node::addChild(Node* newChild){
   children[childCount++] = newChild;
}
//
Tree::Tree() {
   root = nullptr;
}
//
Tree::~Tree() {
   if(root != nullptr)
   {
       delete root;
   }
}
//
void Tree::setRoot(int number) {
   if(root != nullptr)
   {
       delete root;
       root = nullptr;
   }
   root = new Node(number);
}
//
void Tree::addNode(int parentNumber, int newNodeNumber)
{
   Node* parentNode = getNodeByNumber(parentNumber, root);
   Node* newNode = new Node(newNodeNumber, parentNode);
   parentNode->addChild(newNode);
}
//
Tree::Node* Tree::getNodeByNumber(int number, Node* current) {
   if(current->number == number)
       return current;
   for(int i=0; i<current->childCount; i++)
   {
       Node* found = getNodeByNumber(number, current->children[i]);
       if(found)
           return found;
   }
   return nullptr;
}

void Tree::showNode(int number) {
   Node* Node = getNodeByNumber(number, root);
   std::cout << "Node number:" << Node->number << std::endl;
   std::cout << "Node children count:" << Node->childCount << std::endl;
   for (int i = 0; i < Node->childCount; i++) {
      std::cout << "Node child number:" << Node->children[i]->number << ". parent:" << Node->children[i]->parent->number << std::endl;
   }
}

void Tree::delNode(int number) {
   // Ваш код должен быть здесь
    Node* node = getNodeByNumber(number, root); // нашли вершину для удаления
    Node* parent = node->parent; // нашли ее родителя
    // перебросили всех детей удаляемой вершины её родителю
    for(int i=0; i< node->childCount; i++)
    {
       parent->addChild(node->children[i]);  
    }
    // указали, что у  удаляемой вершины, больше нет детей
    node->childCount = 0;
    // удалили вершину
    parent->delChild(node);
}
void Tree::Node::delChild(Node* child) {
    int foundIndex = -1;
    for(int i=0;i<childCount; i++)
        if(children[i] == child)
            foundIndex = i; // нашли индекс удаляемой вершины в массиве
    delete children[foundIndex]; // удалили вершину
    childCount--; // удалили ее из массива
    for(int i=foundIndex; i< childCount; i++)
        children[i] = children[i+1]; 
}
    