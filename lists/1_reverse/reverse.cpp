#include <iostream>

class LinkedList {

    private:

        struct Node {

            int data;
            Node* next; 
            // explicit here means that if we ever call functions that manipulate a Node, we can't accidentally
            // create a new Node without specifying the constructor. 
            explicit Node(int value): data(value), next(nullptr) {

                std::cout << "Node created with value: " << value << std::endl;

            }

        };

        Node* head; // declare the private head node so all functions have access to it

    public: 

        LinkedList(): head(nullptr){ };
        ~LinkedList();
        void insertEnd(int value);
        void printList() const;
        void reverseList();

};

LinkedList::~LinkedList() {

    Node* current = head;

    while(current != nullptr){

        Node* deletable = current;
        current = current->next;
        delete deletable;

    }

    head = nullptr;

}

void LinkedList::insertEnd(int value){

    Node* newNode = nullptr; // wanted to see how to check just like malloc in C, got this

    try{

        newNode = new Node(value);

    }
    catch (const std::bad_alloc& error){

        std::cerr << "Allocation failed: " << error.what() << std::endl;

    }

    if(head == nullptr){

        head = newNode;
        return;

    }

    Node* temp = head;

    while (temp->next != nullptr){

        temp = temp->next;

    }

    temp->next = newNode;

}

void LinkedList::printList() const {

    Node* temp = head;

    while(temp != nullptr){

        std::cout << temp->data << " -> ";
        temp = temp->next;

    }

    std::cout << "NULL" << std::endl;

}

void LinkedList::reverseList() {

    Node* prev = nullptr;
    Node* next = nullptr;
    Node* curr = head;

    while (curr != nullptr){

        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;

    }

    head = prev;

}

int main(){

    LinkedList list;

    for (int i = 0; i < 5; i++){

        list.insertEnd(i + 1);

    }

    list.printList();
    list.reverseList();
    list.printList();

    return 0;

}