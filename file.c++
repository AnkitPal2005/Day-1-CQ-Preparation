#include<iostream>
using namespace std;
#include"genericLinkedList.h"
int main()
{
    LinkedList<int> intList;
    intList.InsertAtBeginning(10);
    intList.InsertAtBeginning(20);
    intList.InsertAtEnd(30);
    intList.Display();

    intList.DeleteValue(10);
    intList.Display();

    LinkedList<string> strList;
    strList.InsertAtBeginning("Krishna");
    strList.InsertAtBeginning("Hare");
    strList.InsertAtEnd("Govinda");
    strList.Display();

    strList.DeleteValue("Krishna");
    strList.Display();

    return 0;
}
