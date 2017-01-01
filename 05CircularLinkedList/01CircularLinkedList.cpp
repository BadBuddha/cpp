#include <iostream>
#include <string>
#include <assert.h>

typedef int Elem;

using namespace std;

class Node{
    private:
        Elem data;
        Node* next;
    public:
        Node(){};
        void setData(Elem aData){data = aData;}
        void setNext(Node* aNext){next = aNext;}
        Node* getNext() const {return next;}
        Elem getData() const {return data;}
};

class DLinkedList{
    private:
        int length;
        Node* head;
        Node* trailer;
    public:
        DLinkedList();
        ~DLinkedList();
        void print();
        bool isEmpty() const;
        bool remove(Elem data);                      // remove node with an element
        void push_back(Elem data);                   // insert at back
        int getLength(){return length;}

        bool insert(Elem data, int position);
        Node* getFrontNode() const {return head;}      //  get first element
        Node* getLastNode() const {return trailer;}    //  get last element

        void removeNode(Node* nodeToRemove);
        //void removeFromFront();                     //  remove from front
        void removeFromBack();                      //  remove from back

        void insertBefore(Node* addNodeBefore, const Elem e);
        void addAtFront(const Elem e);                          // add at front
        void addAtBack(const Elem e);                           // add at back

        Node* getNodeAt(const int position);
};

DLinkedList :: DLinkedList() : head(NULL), trailer(NULL){}

DLinkedList :: ~DLinkedList(){
    Node *tmp1, *tmp2;
    tmp1 = head;
    while (!isEmpty()){
        tmp2 = tmp1->getNext();
        delete tmp1;
        tmp1 = tmp2;
    }
}

bool DLinkedList :: isEmpty() const{
    return (!head || !trailer);
}

void DLinkedList :: print(){
    Node* tmp = head;
    if(!isEmpty()){
        do{
            cout << tmp->getData() << " --> ";
            tmp = tmp->getNext();
        }while(tmp != NULL);
    }else
        cout << "EMPTY" << endl;
    cout << endl;
}

bool DLinkedList :: insert(Elem data, int position){
    Node* newNode = new Node();
    newNode->setData(data);
    newNode->setNext(NULL);
    if(position > (length + 1)){
        cout << "Error: The given position is out of range";
        return false;
    }
    if((position == 0) || (head == NULL)){
        newNode->setNext(head);
        head = newNode;
        trailer = newNode;
    }else{
        int count = 1;
        Node* temp = head;
        while((count < position) && (temp->getNext() != NULL)){
            temp = temp->getNext();
            count ++;
        }
        if (count == length){
            trailer = newNode;
        }
        newNode->setNext(temp->getNext());
        temp->setNext(newNode);
        length++;
        return true;
    }
}

bool DLinkedList :: remove(int position){
    int count = 0;
    if(position > (length+1)){
        cout << "Erro entered position is out of bounds" << endl;
        return false;
    }
    Node* temp = head;
    Node* tempNew = head;
    Node* tempOld = head;
    if(isEmpty()){
        cout << "empty list" << endl;
        return false;
    }else{
        while(tempNew){
            if(count == position){
                if (count == length){
                    trailer = tempOld;
                }
                tempOld->setNext(tempNew->getNext());
                length--;
                delete tempNew;
                return true;
            }
            tempOld = tempNew;
            tempNew = tempOld->getNext();
            count++;
        }
    }
    cout << "Nothing was removed from the list" << endl;
    return false;
}

// void DLinkedList :: removeNode(Node* nodeToRemove){
//     Node* suc = nodeToRemove->getNext();     // successor
//     pre->setNext(suc);
//     suc->setPrev(pre);
// }
//
// // remove from front
// void DLinkedList :: removeFromFront(){
//     removeNode(head->getNext());
// }
//
// //  remove from back
// void DLinkedList :: removeFromBack(){
//     removeNode(trailer->getNext());
// }

Node* DLinkedList :: getNodeAt(const int position){
        int count = 0;
        Node* tmp = head;
        assert(position <= (getLength()-1));
        while(tmp){
            if(count == position){
                return tmp;
            }
            tmp = tmp->getNext();
            count++;
        }
        return NULL;
}

// Add Node before a node
void DLinkedList :: insertBefore(Node* previousNode, const Elem e){
    Node* newNode = new Node();
    newNode->setNext(NULL);
    newNode->setData(e);
    // will be used for insertAfter
    // if(previousNode == trailer){
    //     trailer = newNode;
    // }
    newNode->setNext(previousNode);
    //newNode->setPrev(previousNode->getPrev());
    //previousNode->getPrev()->setNext(newNode);
    //previousNode->setPrev(newNode);
}


// Add to front of list

void DLinkedList :: addAtFront(const Elem data){
    Node* newNode = new Node();
    newNode->setData(data);
    newNode->setNext(NULL);
    //newNode->setPrev(NULL);
    if(head == NULL){
        head = newNode;
        trailer = newNode;
        length++;
        cout << "here" << endl;
        return;
    }
    length++;
    newNode->setNext(head);
    head = newNode;
}


// Push node at the back of the list

void DLinkedList :: push_back(Elem data){
    Node* newNode = new Node();
    newNode->setData(data);
    newNode->setNext(NULL);
    //newNode->setPrev(NULL);
    if(head == NULL){
        head = newNode;
        trailer = newNode;
        length++;
        cout <<"here" << endl;
        return;
    }
    Node* temp = head;
    while(temp->getNext()!= NULL){
        temp = temp->getNext();
    }
    length++;
    temp->setNext(newNode);
    //newNode->setPrev(temp);
    trailer = newNode;
}

int main(){
    DLinkedList* list = new DLinkedList();
    //list.addAtFront(1);
    list->push_back(3);
    list->push_back(4);
    list->addAtFront(9);
    list->push_back(5);
    //list.insert(12,1);
    //list.insert(2,2);
    list->print();
    list->remove(2);
    list->print();

    cout << "value of node at 3rd position : " << list->getNodeAt(2)->getData() << endl;
    list->insertBefore(list->getNodeAt(2),12);
    list->print();
    return -1;
}
