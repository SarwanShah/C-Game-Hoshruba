#pragma once

template <typename T>
struct Node
{
    Node<T>* next;
    T data;

    Node<T>()
    {
        next = NULL;
    }

    Node<T>(const Node<T>& temp)
    {
        this->next = new Node<T>;
        next = temp.next;
        this->data = temp.data;
    }
};
