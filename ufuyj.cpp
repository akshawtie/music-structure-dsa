#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Linked List ADT
class SinglyLinkedList {
private:
    Node* head;

public:
    // Constructor
    SinglyLinkedList() {
        head = NULL;
    }

    // Insert at end
    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    // Delete an element
    void remove(int value) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Element deleted\n";
            return;
        }

        Node* curr = head;
        while (curr->next != NULL && curr->next->data != value)
            curr = curr->next;

        if (curr->next == NULL) {
            cout << "Element not found\n";
        } else {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            cout << "Element deleted\n";
        }
    }

    // Search an element
    void search(int key) {
        Node* temp = head;
        int position = 1;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Element found at position " << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Element not found\n";
    }

    // Count nodes
    int count() {
        int cnt = 0;
        Node* temp = head;

        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    // Display list
    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main function
int main() {
    SinglyLinkedList list;
    int choice, value;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Count nodes\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insert(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                list.remove(value);
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                list.search(value);
                break;

            case 4:
                cout << "Number of nodes: " << list.count() << endl;
                break;

            case 5:
                list.display();
                break;

            case 6:
                cout << "Exiting program\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 6);

    return 0;
}


