
#include <iostream>
using namespace std;


template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T val)
    {
        data = val;
        next = nullptr;
    }
};


template <typename T>
class LinkedList
{
private:
    Node<T> *Head;

public:
    LinkedList()
    {
        Head = nullptr;
    }

  
    void InsertAtBeginning(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = Head;
        Head = newNode;
    }

    
    void InsertAtEnd(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (Head == nullptr)
        {
            Head = newNode;
            return;
        }
        Node<T> *temp = Head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

   
    void DeleteValue(T value)
    {
        if (Head == nullptr)
            return;

      
        if (Head->data == value)
        {
            Node<T> *temp = Head;
            Head = Head->next;
            delete temp;
            return;
        }

        Node<T> *current = Head;
        Node<T> *previous = nullptr;

        while (current != nullptr && current->data != value)
        {
            previous = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Value not found in the list.\n";
            return;
        }

        previous->next = current->next;
        delete current;
    }

    
    void Display()
    {
        Node<T> *temp = Head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
