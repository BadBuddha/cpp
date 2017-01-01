#include <iostream>
#include <string>

using namespace std;

// class Node{
//     private:
//         int data;
//         Node* next;
//         //friend class LinkedList;
//     public:
//         Node(){};
//         void setData(int aData){data = aData;}
//         void setNext(Node* aNext){next = aNext;}
//         int getData(){return data;}
//         Node* getNext(){return next;}
// };


template <typename E>
class gNode{
    private:
        E elem;
        gNode<E>* next;
    public:
        //gNode();
        void setData(E sData){elem = sData;}
        void setNext(gNode<E>* sNext){next = sNext;}
        E getData(){return elem;}
        gNode<E>* getNext(){return next;}
};


template <typename E>
class LinkedList{
    private:
        gNode<E>* head;
        int length;
    public:
        LinkedList();
        ~LinkedList();
        bool isEmpty() const;
        void print();
        bool insert(E sData, int position);
        bool remove(int position);
        void push_back(E sData);
};


// class LinkedList{
//     private:
//         Node* head;
//         int length;
//     public:
//         LinkedList();
//         ~LinkedList();
//         bool isEmpty() const;
//         void print();
//         bool insert(int data, int position);
//         bool remove(int data);
//         void push_back(int data);
// };

template <typename E>
LinkedList<E> :: LinkedList() : head(NULL), length(0){}

template <typename E>
LinkedList<E> :: ~LinkedList(){
//    while (!isEmpty()) removeFront();)
}

template <typename E>
bool LinkedList<E> :: isEmpty() const{
    return head == NULL;
}

template <typename E>
void LinkedList<E> :: print(){
    gNode<E>* tmp = head;
    if(!isEmpty()){
        cout << endl;
        do{
            cout << tmp->getData() << "--> ";
            tmp = tmp->getNext();
        }while(tmp != NULL);
    }else
        cout << "EMPTY" << endl;
}

template <typename E>
bool LinkedList<E> :: insert(E data, int position){
    gNode<E>* newNode = new gNode<E>();
    newNode->setData(data);
    newNode->setNext(NULL);
    if(position > (length + 1)){
        cout << "Error: The given position is out of range";
        return false;
    }
    int count = 0;
    gNode<E>* tempOld = head;
    gNode<E>* tempNew = head;
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

template <typename E>
bool LinkedList<E> :: remove(int position){
    int count = 0;
    if(position > (length+1)){
        cout << "Erro entered position is out of bounds" << endl;
        return false;
    }
    gNode<E>* tempOld = head;
    gNode<E>* tempNew = head;
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

template <typename E>
void LinkedList<E> :: push_back(E data){
    gNode<E>* newNode = new gNode<E>();
    newNode->setData(data);
    newNode->setNext(NULL);

    if(head == NULL){
        head = newNode;
        length++;
        return;
    }
    gNode<E>* temp = head;
    cout << "so far good" << endl;
    while(temp->getNext()!= NULL){
        cout << "so far good2" << endl;
        temp = temp->getNext();
    }
    length++;
    temp->setNext(newNode);
}

int main(){
    LinkedList<int,string> list;// = new LinkedList();
    list.push_back(3);
    list.push_back(4);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);
    list.push_back(9);
    list.push_back(10);
    list.push_back(11);
    list.push_back("a");

    list.print();
    list.remove(2);
    list.print();
    return -1;
}
