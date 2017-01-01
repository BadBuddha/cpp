#include <iostream>
#include <string>

using namespace std;

class Node{
    private:
        int data;
        Node* next;
        //friend class LinkedList;
    public:
        Node(){};
        void setData(int aData){data = aData;}
        void setNext(Node* aNext){next = aNext;}
        int getData(){return data;}
        Node* getNext(){return next;}
};

class LinkedList{
    private:
        Node* head;
        int length;
    public:
        LinkedList();
        ~LinkedList();
        bool isEmpty() const;
        void print();
        bool insert(int data, int position);
        bool remove(int data);
        void push_back(int data);
};

LinkedList :: LinkedList() : head(NULL), length(0){}

LinkedList :: ~LinkedList(){
//    while (!isEmpty()) removeFront();)
}

bool LinkedList :: isEmpty() const{
    return head == NULL;
}

void LinkedList :: print(){
    Node* tmp = head;
    if(!isEmpty()){
        cout << endl;
        do{
            cout << tmp->getData() << "--> ";
            tmp = tmp->getNext();
        }while(tmp != NULL);
    }else
        cout << "EMPTY" << endl;
}

bool LinkedList :: insert(int data, int position){
    Node* newNode = new Node();
    newNode->setData(data);
    newNode->setNext(NULL);
    if(position > (length + 1)){
        cout << "Error: The given position is out of range";
        return false;
    }
    int count = 0;
    Node* tempOld = head;
    Node* tempNew = head;
    while(tempNew){
        cout << "here" << endl;
        if(count == position){
            tempOld->setNext(newNode);
            newNode->setNext(tempNew);
            length++;
            return true;
        }
        tempOld = tempNew;
        tempNew = tempOld->getNext();
        count ++;
    }
    if(count == position){
        tempOld->setNext(newNode);
        newNode->setNext(tempNew);
        length++;
        return true;
    }
}

bool LinkedList :: remove(int position){
    int count = 0;
    if(position > (length+1)){
        cout << "Erro entered position is out of bounds" << endl;
        return false;
    }
    Node* tempOld = head;
    Node* tempNew = head;
    if(isEmpty()){
        cout << "empty list" << endl;
        return false;
    }else{
        while(tempNew){
            if(count == position){
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

void LinkedList :: push_back(int data){
    Node* newNode = new Node();
    newNode->setData(data);
    newNode->setNext(NULL);

    if(head == NULL){
        head = newNode;
        length++;
        return;
    }
    Node* temp = head;
    cout << "so far good" << endl;
    while(temp->getNext()!= NULL){
        cout << "so far good2" << endl;
        temp = temp->getNext();
    }
    length++;
    temp->setNext(newNode);
}

int main(){
    LinkedList list;
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.insert(2,2);
    list.print();
    list.remove(2);
    list.print();
    return -1;
}
