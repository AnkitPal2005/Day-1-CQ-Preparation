#include<iostream>
using namespace std;
#include"genericLinkedList.h"
int main()
{
    LinkedList<int> intList;
    intList.InsertAtBeginning(10);
    intList.InsertAtBeginning(20);
    intList.InsertAtEnd(30);
    intList.Display(); // 20 -> 10 -> 30 -> NULL

    intList.DeleteValue(10);
    intList.Display(); // 20 -> 30 -> NULL

    LinkedList<string> strList;
    strList.InsertAtBeginning("Krishna");
    strList.InsertAtBeginning("Hare");
    strList.InsertAtEnd("Govinda");
    strList.Display(); // Hare -> Krishna -> Govinda -> NULL

    strList.DeleteValue("Krishna");
    strList.Display(); // Hare -> Govinda -> NULL

    return 0;
}
