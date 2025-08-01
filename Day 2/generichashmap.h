
#include <iostream>
#include <string>
using namespace std;

template <typename K, typename V>
class Node
{
public:
    K key;
    V value;
    Node<K, V> *next;
    Node(K k, V v)
    {
        key = k;
        value = v;
        next = nullptr;
    }
};

template <typename K, typename V>
class HashTable
{
    int hashSize = 10;
    Node<K, V> **hashmap;
    int totalElements;

public:
    HashTable()
    {
        hashmap = new Node<K, V> *[hashSize]();
        totalElements = 0;
    }

    ~HashTable()
    {
        clear();
        delete[] hashmap;
    }

    int hash(int key) { return key % hashSize; }
    int hash(float key) { return (int)(key * hashSize); }
    int hash(long key) { return key % hashSize; }
    int hash(char key) { return key % hashSize; }

    int hash(string key)
    {
        int count = 0;
        for (char c : key)
            count += (c - 'a');
        return count % hashSize;
    }

    int hashfunction(K key) { return hash(key); }

    bool ismatched(int a, int b) { return a == b; }
    bool ismatched(long a, long b) { return a == b; }
    bool ismatched(char a, char b) { return a == b; }
    bool ismatched(float a, float b) { return a == b; }
    bool ismatched(string a, string b) { return a == b; }

    bool CheckIfPresent(K key, int hashposition)
    {
        Node<K, V> *temp = hashmap[hashposition];
        while (temp != nullptr)
        {
            if (ismatched(key, temp->key))
                return true;
            temp = temp->next;
        }
        return false;
    }

    void insertion(K key, V value)
    {
        float load = totalElements / (float)hashSize;
        if (load > 0.7)
        {
            resize();
        }

        int hashposition = hashfunction(key);
        if (CheckIfPresent(key, hashposition))
        {
            cout << "Key already present\n";
            return;
        }

        Node<K, V> *newNode = new Node<K, V>(key, value);
        newNode->next = hashmap[hashposition];
        hashmap[hashposition] = newNode;
        totalElements++;
        cout << "Insertion Successful\n";
    }

    void resize()
    {
        int oldsize = hashSize;
        hashSize = oldsize * 2;
        Node<K, V> **oldmap = hashmap;
        hashmap = new Node<K, V> *[hashSize]();
        totalElements = 0;

        for (int i = 0; i < oldsize; i++)
        {
            Node<K, V> *temp = oldmap[i];
            while (temp)
            {
                insertion(temp->key, temp->value);
                Node<K, V> *del = temp;
                temp = temp->next;
                delete del;
            }
        }
        delete[] oldmap;
        cout << "Resize Complete.New Size: " << hashSize << endl;
    }

    void search(K key)
    {
        int hashposition = hashfunction(key);
        Node<K, V> *temp = hashmap[hashposition];
        while (temp)
        {
            if (ismatched(key, temp->key))
            {
                cout << "Key Found\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Not Found\n";
    }

    void deletenode(K key)
    {
        int hashposition = hashfunction(key);
        Node<K, V> *temp = hashmap[hashposition];
        Node<K, V> *prev = nullptr;

        while (temp)
        {
            if (ismatched(key, temp->key))
            {
                if (!prev)
                    hashmap[hashposition] = temp->next;
                else
                    prev->next = temp->next;

                delete temp;
                totalElements--;
                cout << "Deleted Successfully\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Key not found\n";
    }

    void display()
    {
        for (int i = 0; i < hashSize; i++)
        {
            Node<K, V> *temp = hashmap[i];
            cout << "[" << i << "]: ";
            while (temp)
            {
                cout << "(" << temp->key << "," << temp->value << ") -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }

    void clear()
    {
        for (int i = 0; i < hashSize; i++)
        {
            Node<K, V> *temp = hashmap[i];
            while (temp)
            {
                Node<K, V> *del = temp;
                temp = temp->next;
                delete del;
            }
            hashmap[i] = nullptr;
        }
        totalElements = 0;
        cout << "Clear Successfully\n";
    }

    int total() { return totalElements; }
};

