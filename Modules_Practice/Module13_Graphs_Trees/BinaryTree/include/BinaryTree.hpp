#pragma once
#include <iostream>
class BinaryTree {
    public:
        struct Node { // структура узла
            Node(int d, Node* p = nullptr):
                data(d), parent(p) {
               leftChild = nullptr; 
               rightChild = nullptr;
            };
            ~Node() {
                // чистим за собой память
                if(rightChild != nullptr)
                    delete rightChild;
                if(leftChild != nullptr)
                    delete leftChild;
            }
            Node* parent; // родительский узел
            
            Node* leftChild; // левый узел
            Node* rightChild; // правый узел
            
            int data; // данные - целое число

        };
    
        BinaryTree()
        {
            root = nullptr;
        }
        ~BinaryTree()
        {
            if(root != nullptr)
            {
                delete root;
            }
        }    

        void addInt(int newdata);
        Node* findNodeByData(int finddata);
        void delInt(int deldata);
    private:       
        Node* root; // корневой узел
        bool isLeaf(Node* check);
};