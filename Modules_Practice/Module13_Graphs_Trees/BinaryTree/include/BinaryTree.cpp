#include "BinaryTree.hpp"
void BinaryTree::addInt(int newdata) {
    if(root == nullptr) {
        // если дерево пустое, то новый элемент станет корнем
        root = new Node(newdata);
    }
    else {
        Node* current = root; // начинаем с корня
        Node* newNode = nullptr;
        while(newNode == nullptr) {
            if (current->data >= newdata) {
                // если элемент меньше текущего, идем влево
                if(current->leftChild != nullptr) {
                    current = current->leftChild;
                    continue;
                }
                // если левого узла нет, то нашли место для нового элемента
                newNode = new Node(newdata, current);
                current->leftChild = newNode;
            }
            else {
                // если элемент меньше текущего, идем вправо
                if (current->rightChild != nullptr) {
                    current = current->rightChild;
                    continue;
                }
                // если правого узла нет, то нашли место для нового элемента
                newNode = new Node(newdata, current);
                current->rightChild = newNode;
            }
        }
    }
}

bool BinaryTree::isLeaf(Node* check) {
    return check->leftChild == nullptr 
           && check->rightChild == nullptr;
}

BinaryTree::Node* BinaryTree::findNodeByData(int finddata) {
    // Ваш код
    if(root == nullptr) {
        // если дерево пустое, то новый элемент станет корнем
        return nullptr;
    }
    else {
        Node* current = root; // начинаем с корня
        while(!isLeaf(current)) {
            if (current->data > finddata) {
                // если элемент меньше текущего, идем влево
                if(current->leftChild != nullptr) {
                    current = current->leftChild;
                }
            } else if (current->data < finddata) {
                // если элемент меньше текущего, идем вправо
                if (current->rightChild != nullptr) {
                    current = current->rightChild;
                }
            }
            if (current->data == finddata) {
                std::cout << "Found " << finddata << std::endl;
                return current;
            }
        }
        std::cout << "Didn't Found " << finddata << std::endl;
        return nullptr;
    }
}

// удаление элемента
void BinaryTree::delInt(int deldata) {
    // Ваш код
}