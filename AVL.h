//
// Created by Dru on 10/15/2024.
//

#ifndef AVL_AVL_H
#define AVL_AVL_H

#include "Node.h"
#include <iostream>
#include <queue>

template <typename T>
class AVL
{
public:
    AVL();
    ~AVL();

    void insert(const T& data);
    bool contains(const T& data);
    void remove(const T& data);
    void preOrder() const;
    void inOrder() const;
    void postOrder() const;
    void breadthOrder() const;

private:
    Node<T>* root;

    Node<T> * insert(Node<T>*& node, const T& data);
    bool contains(Node<T>* node, const T& data) const;
    Node<T>* remove(Node<T>* node, const T& data);
    Node<T>* findLeast(Node<T>* node) const;
    void preOrder(Node<T>* node) const;
    void inOrder(Node<T>* node) const;
    void postOrder(Node<T>* node) const;
    void breadthOrder(Node<T>* node) const;
    void clear(Node<T>* node);

    int height(Node<T>* node);
    void updateHeight(Node<T>* node);
    int balanceFactor(Node<T>* node);
    Node<T> * balance(Node<T>* node);
    Node<T>* rotateRight(Node<T>* node);
    Node<T>* rotateLeft(Node<T>* node);
};

#include "AVL.cpp"

#endif //AVL_AVL_H