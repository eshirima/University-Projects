//
//  List.hpp
//  Lab 3
//
//  Created by Emil Shirima on 2/2/16.
//  Copyright © 2016 Emil Shirima. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include <iostream>

template<typename T>

class Node
{
public:
    Node();
    Node(T);
    T data;
    Node<T>* next;
    
};

template<typename T>

class Collection
{
public:
    Collection();
    
    bool isEmpty();
    void addItem(T);
    void removeItem(T);
    T lastItem();
    void printCollection();
    
private:
    Node<T>* head;
    Node<T>* getLastNode();
};

template<typename T>
Node<T>::Node()
{
    data = NULL;
    next = nullptr;
}

template<typename T>
Node<T>::Node(T info)
{
    data = info;
    next = nullptr;
}

template<typename T>
Collection<T>::Collection()
{
    head = nullptr;
}

template <typename T>
bool Collection<T>::isEmpty()
{
    return (head == nullptr) ? true : false;
}

template <typename T>
Node<T>* Collection<T>::getLastNode()
{
    if (head == nullptr)
    {
        return nullptr;
    }
    
    Node<T>* temp = head;
    
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    
    return temp;
}

template<typename T>
void Collection<T>::addItem(T value)
{
    if (isEmpty())
    {
        head = new Node<T>(value);
    }
    else
    {
        Node<T>* temp = getLastNode();
        
        if (temp == nullptr)
        {
            temp = new Node<T>(value);
        }
        else
        {
            temp->next = new Node<T>(value);
        }
    }
}

template<typename T>
void Collection<T>::removeItem(T value)
{
    if (!isEmpty())
    {
        Node<T>* slowerTemp = head;
        Node<T>* temp = head->next;
        
        if (head->data == value)
        {
            delete head;
            head = temp;
        }
        
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                slowerTemp->next = temp->next;
                delete temp;
                break;
            }
            
            slowerTemp = temp;
            temp = temp->next;
        }
    }
    else
    {
        std::cout << "It's the 21st century and we still cannot delete an empty list :(" << "\n";
    }
}

template<typename T>
T Collection<T>::lastItem()
{
    if (!isEmpty())
    {
        return getLastNode()->data;
    }
    else
    {
        std::cout << "Can't find the last item to an empty list :(" << "\n";
        return T(); // hacky way to return
    }
}

template<typename T>
void Collection<T>::printCollection()
{
    if (!isEmpty())
    {
        Node<T>* temp = head;
        
        while (temp)
        {
            std::cout << temp->data << "\n";
            temp = temp->next;
        }
    }
    else
    {
        std::cout << "Our current technology does not support printing an empty list :(" << "\n";
    }
}
#endif /* List_hpp */