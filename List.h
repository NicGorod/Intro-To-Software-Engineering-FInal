/*
  Class:      List
  Purpose:    Represents a template class for storing a collection of elements.

  Member Functions:
  - List(int capacity = 10): Constructor to initialize List object with optional capacity.
  - ~List(): Destructor to free dynamically allocated memory.
  - List& operator+=(T* item): Overloaded operator to add an element to the list.
  - void convertToArray(T** arr, int& size) const: Converts the list to an array and returns the size.

  Private Members:
  - int capacity: Capacity of the list.
  - Node* head: Pointer to the head node of the list.
*/

#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

template<typename T>
class List
{
    class Node
    {
    public:
        T* data;
        Node* next;
    };

public:
    List(int=10);
    ~List();
    List& operator+=(T* item); // Overloaded += operator
    void convertToArray(T** arr, int& size) const; // Convert to array

private:
    int capacity;
    Node* head;
};

template<typename T>
List<T>::List(int c)
{
    if (c < 0) {
        cerr << "Invalid capacity" << endl;
        exit(1);
    }

    capacity = c;
    head = nullptr;
}

template<typename T>
List<T>::~List()
{
    Node* currNode = head;
    Node* nextNode;

    while (currNode != nullptr) {
        nextNode = currNode->next;
        delete currNode->data;
        delete currNode;
        currNode = nextNode;
    }
}

template<typename T>
List<T>& List<T>::operator+=(T* item)
{
    Node* newNode = new Node;
    newNode->data = item;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* currNode = head;
        while (currNode->next != nullptr) {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }

    return *this; // Enable cascading
}

template<typename T>
void List<T>::convertToArray(T** arr, int& size) const
{
    size = 0;
    Node* currNode = head;
    while (currNode != nullptr) {
        arr[size++] = currNode->data;
        currNode = currNode->next;
    }
}

#endif
