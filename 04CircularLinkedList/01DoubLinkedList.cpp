#include <iostream>
#include <string>
#include <assert.h>

typedef int Elem;

using namespace std;

class DNode{
    private:
        Elem data;
        DNode* next;
        DNode* prev;
    public:
        DNode(){};
        void setData(Elem aData){data = aData;}
        void setNext(DNode* aNext){next = aNext;}
        void setPrev(DNode* aPrev){prev = aPrev;}
        DNode* getNext() const {return next;}
        DNode* getPrev() const {return prev;}
        Elem getData() const {return data;}
};

class DLinkedList{
    private:
        int length;
        DNode* head;
        DNode* trailer;
    public:
        DLinkedList();
        ~DLinkedList();
        void print();
        bool isEmpty() const;
        bool remove(Elem data);                      // remove node with an element
        void push_back(Elem data);                   // insert at back
        int getLength(){return length;}

        bool insert(Elem data, int position);
        const Elem getFront() const {return head->getNext()->getData();}      //  get first element
        const Elem getLast() const {return trailer->getPrev()->getData();}    //  get last element

        void removeNode(DNode* nodeToRemove);
        void removeFromFront();                     //  remove from front
        void removeFromBack();                      //  remove from back

        void insertBefore(DNode* addNodeBefore, const Elem e);
        void addAtFront(const Elem e);                          // add at front
        void addAtBack(const Elem e);                           // add at back

        DNode* getNodeAt(const int position);
};

DLinkedList :: DLinkedList() : head(NULL), trailer(NULL){}

DLinkedList :: ~DLinkedList(){
    while (!isEmpty()) removeFromFront();
    delete head;
    delete trailer;
}

bool DLinkedList :: isEmpty() const{
    return (!head || !trailer);
}

void DLinkedList :: print(){
    DNode* tmp = head;
    if(!isEmpty()){
        do{
            cout << tmp->getData() << " <--> ";
            tmp = tmp->getNext();
        }while(tmp != NULL);
    }else
        cout << "EMPTY" << endl;
    cout << endl;
}

bool DLinkedList :: insert(Elem data, int position){
    DNode* newNode = new DNode();
    newNode->setData(data);
    newNode->setNext(NULL);
    newNode->setPrev(NULL);
    if(position > (length + 1)){
        cout << "Error: The given position is out of range";
        return false;
    }
    if((position == 0) || (head == NULL)){
        newNode->setNext(head);
        head = newNode;
    }else{
        int count = 1;
        DNode* temp = head;
        while((count < position) && (temp->getNext() != NULL)){
            temp = temp->getNext();
            count ++;
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
    DNode* temp = head;
    //DNode* tempNew = head;
    if(isEmpty()){
        cout << "empty list" << endl;
        return false;
    }else{
        while(temp){
            if(count == position){
                temp->getNext()->setPrev(temp->getPrev());
                temp->getPrev()->setNext(temp->getNext());
                length--;
                delete temp;
                return true;
            }
            //tempOld = tempNew;
            temp = temp->getNext();
            count++;
        }
    }
    cout << "Nothing was removed from the list" << endl;
    return false;
}

void DLinkedList :: removeNode(DNode* nodeToRemove){
    DNode* pre = nodeToRemove->getPrev();     // predecessor
    DNode* suc = nodeToRemove->getNext();     // successor
    pre->setNext(suc);
    suc->setPrev(pre);
}

// remove from front
void DLinkedList :: removeFromFront(){
    removeNode(head->getNext());
}

//  remove from back
void DLinkedList :: removeFromBack(){
    removeNode(trailer->getNext());
}

DNode* DLinkedList :: getNodeAt(const int position){
        int count = 0;
        DNode* tmp = head;
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
void DLinkedList :: insertBefore(DNode* previousNode, const Elem e){
    DNode* newNode = new DNode();
    newNode->setNext(NULL);
    newNode->setPrev(NULL);
    newNode->setData(e);
    // will be used for insertAfter
    // if(previousNode == trailer){
    //     trailer = newNode;
    // }
    newNode->setNext(previousNode);
    newNode->setPrev(previousNode->getPrev());
    previousNode->getPrev()->setNext(newNode);
    previousNode->setPrev(newNode);
}


// Add to front of list

void DLinkedList :: addAtFront(const Elem data){
    DNode* newNode = new DNode();
    newNode->setData(data);
    newNode->setNext(NULL);
    newNode->setPrev(NULL);
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
    DNode* newNode = new DNode();
    newNode->setData(data);
    newNode->setNext(NULL);
    newNode->setPrev(NULL);
    if(head == NULL){
        head = newNode;
        trailer = newNode;
        length++;
        cout <<"here" << endl;
        return;
    }
    DNode* temp = head;
    while(temp->getNext()!= NULL){
        temp = temp->getNext();
    }
    length++;
    temp->setNext(newNode);
    newNode->setPrev(temp);
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
