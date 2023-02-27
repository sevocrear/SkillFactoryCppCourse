#pragma once

#define SIZE 10
#include <iostream>
class Tree { // класс дерева
    public:
        struct Node { // структура узла
            Node(int _number, Node* _parent = nullptr);
            ~Node();
            
            int number; // номер мершины
            
            Node* parent; // родительская вершина
            Node* children[SIZE]; // список дочерних вершин
            int childCount; // количество детей
            
            void addChild(Node* newChild);
            void delChild(Node* child);
        };
        Tree();
        ~Tree();
    
        void setRoot(int number);
        void addNode(int parentNumber, int newNodeNumber);
        
        void delNode(int nodeNumber);
        void showNode(int number);
    private:
        Node* getNodeByNumber(int number, Node* current);
        Node* root;
};