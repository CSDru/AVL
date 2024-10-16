//
// Created by Dru on 10/15/2024.
//
#ifndef AVL_AVL_CPP
#define AVL_AVL_CPP

#include "AVL.h"

template<typename T>
AVL<T>::AVL() : root(nullptr) {}

template<typename T>
AVL<T>::~AVL()
{
    clear(root);
}

template<typename T>
void AVL<T>::insert(const T &data)
{
    root = insert(root, data);
}

template<typename T>
bool AVL<T>::contains(const T &data)
{
    return contains(root, data);
}

template<typename T>
void AVL<T>::remove(const T &data)
{
    root = remove(root, data);
}

template<typename T>
void AVL<T>::preOrder() const
{
    preOrder(root);
}

template<typename T>
void AVL<T>::inOrder() const
{
    inOrder(root);
}

template<typename T>
void AVL<T>::postOrder() const
{
    postOrder(root);
}

template<typename T>
void AVL<T>::breadthOrder() const
{
    breadthOrder(root);
}

template<typename T>
Node<T> * AVL<T>::insert(Node<T> *&node, const T &data)
{
    if(!node)
        return new Node<T>(data, 1);

    if(data < node->data)
        node->left = insert(node->left, data);
    else if(data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    updateHeight(node);

    node = balance(node);

    return node;
}

template<typename T>
bool AVL<T>::contains(Node<T> *node, const T &data) const
{
    if(!node)
        return false;
    else if(data < node->data)
        return contains(node->left, data);
    else if(data > node->data)
        return contains(node->right, data);
    else
        return true;
}

template<typename T>
Node<T> *AVL<T>::remove(Node<T> *node, const T &data)
{
    if(!node)
        return nullptr;

    if(data < node->data)
        node->left = remove(node->left, data);
    else if(data > node->data)
        node->right = remove(node->right, data);
    else
    {
        if(!node->left || !node->right)
        {
            Node<T>* temp = node->left ? node->left : node->right;
            if(!temp)
            {
                delete node;
                return nullptr;
            }
            delete node;
            return temp;
        }
        Node<T>* leastNode = findLeast(node->right);
        node->data = leastNode->data;
        node->right = remove(node->right, leastNode->data);
    }

    updateHeight(node);

    node = balance(node);

    return node;
}

template<typename T>
Node<T> *AVL<T>::findLeast(Node<T> *node) const
{
//    if(node && node->left)
//        node = findLeast(node->left);
//    return node;
    while(node && node->left)
        node = node->left;
    return node;
}

template<typename T>
void AVL<T>::preOrder(Node<T> *node) const
{
    if(!node)
        return;
    std::cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

template<typename T>
void AVL<T>::inOrder(Node<T> *node) const
{
    if(!node)
        return;
    inOrder(node->left);
    std::cout << node->data << " ";
    inOrder(node->right);
}

template<typename T>
void AVL<T>::postOrder(Node<T> *node) const
{
    if(!node)
        return;
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->data << " ";
}

template<typename T>
void AVL<T>::breadthOrder(Node<T> *node) const
{
    if(!node)
        return;
    std::queue<Node<T>*> Queue;
    Queue.push(node);

    while(!Queue.empty())
    {
        Node<T>* current = Queue.front();
        Queue.pop();
        std::cout << current->data << " ";

        if(current->left)
            Queue.push(current->left);
        if(current->right)
            Queue.push(current->right);
    }
}

template<typename T>
void AVL<T>::clear(Node<T> *node)
{
    if(!node)
        return;
    clear(node->left);
    clear(node->right);
    delete node;
}

template<typename T>
int AVL<T>::height(Node<T>* node)
{
    return node ? node->height : 0;
}

template<typename T>
void AVL<T>::updateHeight(Node<T> *node)
{
    if(node)
        node->height = 1 + std::max(height(node->left), height(node->right));
}

template<typename T>
int AVL<T>::balanceFactor(Node<T> *node)
{
    return node ? height(node->left) - height(node->right) : 0;
}

template<typename T>
Node<T> * AVL<T>::balance(Node<T> *node)
{
    int balance = balanceFactor(node);

    if(balance > 1)
    {
        if(balanceFactor(node->left) < 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if(balance < -1)
    {
        if (balanceFactor(node->right) > 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

template<typename T>
Node<T> *AVL<T>::rotateRight(Node<T> *node)
{
    Node<T>* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    updateHeight(node);
    updateHeight(newRoot);

    return newRoot;
}

template<typename T>
Node<T> *AVL<T>::rotateLeft(Node<T> *node)
{
    Node<T>* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    updateHeight(node);
    updateHeight(newRoot);

    return newRoot;
}

#endif //AVL_AVL_CPP