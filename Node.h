//
// Created by Dru on 9/24/2024.
//

#ifndef AVL_NODE_H
#define AVL_NODE_H

template <typename T>

struct Node
{
    T data;
    Node<T> *left = nullptr, *right = nullptr;
    int height;

    explicit Node(const T& _data, const int height) : data(_data), height(1){}
};

#endif //AVL_NODE_H
