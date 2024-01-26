#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node()
    {
        // Memory Free
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "\nMemory is been free for node with data " << value << endl;
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = tail->next;
}

void insertAtMiddle(Node *&head, Node *&tail, int position, int data)
{
    // Case to insert at first position
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // Case to insert at Last or Tail position
    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    // Case to insert at Middle Position
    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNodeAtPosition(Node *&head, Node *&tail, int position)
{
    // Delete from Starting Postion
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // Free Memory
        temp->next = NULL;
        delete temp;
    }

    else
    {
        // Deleting any middle position
        Node *prev = NULL;
        Node *curr = head;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        if (curr->next == NULL)
        {
            tail = prev;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void deleteNodeAtValue(Node *&head, Node *&tail, int value)
{
    // If the value is at starting positon
    if (head->data == value)
    {
        Node *curr = head;
        head = head->next;
        curr->next = NULL;
        delete curr;
    }
    else
    {
        Node *prev = NULL;
        Node *curr = head;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        if (curr->next == NULL)
        {
            tail = prev;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);
    // Head Pointer to Node 1
    Node *head = node1;
    Node *tail = node1;

    insertAtTail(tail, 20);
    print(head);

    insertAtTail(tail, 30);
    print(head);

    insertAtMiddle(head, tail, 4, 55);
    print(head);
    cout << head->data << " " << tail->data;

    deleteNodeAtPosition(head, tail, 4);
    print(head);

    deleteNodeAtValue(head, tail, 10);
    print(head);

    cout << head->data << " " << tail->data;

    return 0;
}