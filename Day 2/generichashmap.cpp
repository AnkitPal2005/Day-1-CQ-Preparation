#include<iostream>
#include "./generichashmap.h" 


int main()
{
    HashTable<string, string> ht;
    int choice;
    string key, value;

    while (true)
    {
        cout << "\nEnter your choice\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Display Hash Table\n";
        cout << "5. Total Elements\n";
        cout << "6. Clear All\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value: ";
            cin >> value;
            ht.insertion(key, value);
            break;
        case 2:
            cout << "Enter key to search: ";
            cin >> key;
            ht.search(key);
            break;
        case 3:
            cout << "Enter key to delete: ";
            cin >> key;
            ht.deletenode(key);
            break;
        case 4:
            ht.display();
            break;
        case 5:
            cout << "Total elements: " << ht.total() << endl;
            break;
        case 6:
            ht.clear();
            break;
        case 7:
            cout << "Exiting\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}
