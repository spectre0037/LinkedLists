#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node()
    {
        next = nullptr;
    }
};
class SinglyLinkedList
{
public:
    Node *head;

    SinglyLinkedList()
    {
        head = nullptr;
    }
    void InsertAtBegining(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }
    void InsertAtEnd(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        if (head == nullptr)
        {
            head = newNode;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            temp = temp->next;
        }
    }
    void InsertAtPosition(int value, int position)
    {
        Node *newNode = new Node();
        newNode->data = value;
        Node *temp = head;
        if (head == nullptr)
        {
            head = newNode;
        }
        else if (position == 1)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            for (int i = 1; i < position - 1 && temp != nullptr; i++)
            {
                temp = temp->next;
            }

            if (temp == nullptr)
            {
                return;
            }
            else if (temp != nullptr)
            {
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }
    void DeleteAtBegining()
    {
        Node *current = head;
        head = current->next;
        delete current;
    }
    void DeleteAtEnd()
    {
        Node *current = head;
        while (current->next->next != nullptr)
        {
            current = current->next;
        }
        delete current;
        current->next = nullptr;
    }
    void DeleteAtPosition(int position)
    {
        Node *temp = head;
        if (head == nullptr || position <= 0)
        {
            return;
        }
        else if (position == 1)
        {
            DeleteAtBegining();
            return;
        }
        else
        {
            for (int i = 1; i < position - 1 && temp != nullptr; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            delete temp;
        }
    }
    void PrintList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    SinglyLinkedList object;
    object.InsertAtBegining(2);
    object.InsertAtBegining(3);
    object.InsertAtBegining(4);
    object.InsertAtBegining(5);
    object.PrintList();
    object.InsertAtPosition(12, 1);
    object.PrintList();
    object.DeleteAtPosition(3);
    cout << endl;
    object.PrintList();
}
