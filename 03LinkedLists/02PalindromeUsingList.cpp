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
        void reverse();
        bool isPalindrom();
        Node* getHead(){return head;}
        int getLength(){return length;}
        bool isEqualTo(LinkedList *list);
        LinkedList* copyToNewList();
        LinkedList* makeNewListFrom(Node* newNodeOfTheList);

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
    while(temp->getNext()!= NULL){
        temp = temp->getNext();
    }
    length++;
    temp->setNext(newNode);
}

void LinkedList :: reverse(){
    Node *prev = NULL, *temp;
    Node *ptr = head;
    while(ptr){
        temp = ptr->getNext();
        ptr->setNext(prev);
        prev = ptr;
        ptr = temp;
    }
    head = prev;
}


bool LinkedList :: isPalindrom(){
    if(isEmpty()){
        return false;
    }
    Node *singleJump, *doubleJump, *mid = NULL;
    singleJump = doubleJump = head;
    while(doubleJump){
        if (doubleJump){
            doubleJump = doubleJump->getNext();
        }
        if (doubleJump){
            doubleJump = doubleJump->getNext();
            singleJump = singleJump->getNext();
        }
    }
    mid = singleJump;
    //LinkedList *newList = makeNewListFrom(mid);
    LinkedList *copiedList = new LinkedList;
    copiedList = copyToNewList();
    //cout << "\n copying stuff \n\n" ;
    copiedList->print();
    copiedList->reverse();
    //cout << "new list";
    copiedList->print();
    //cout << "old list :";
    print();
    cout << endl;
    if (isEqualTo(copiedList)){
        return true;
    }
    return false;
}


LinkedList* LinkedList :: copyToNewList(){
    Node *tmp = head;
    LinkedList *newList = new LinkedList;
    while(tmp){
        //cout << "Copying data : " << tmp->getData() << endl;
        newList->push_back(tmp->getData());
        tmp = tmp->getNext();
    }
    return newList;
}

LinkedList* LinkedList :: makeNewListFrom(Node* newNodeOfTheList){
    Node *tmp = head;
    Node *prev;
    while(tmp->getNext() != newNodeOfTheList){
        prev = tmp;
        tmp = tmp->getNext();
    }
    tmp = tmp->getNext();
    LinkedList *newList = new LinkedList();
    while(tmp){
        //cout << "getData() : " << tmp->getData() << endl;
        newList->push_back(tmp->getData());
        tmp = tmp->getNext();
    }
    newList->print();
    return newList;
}


bool LinkedList :: isEqualTo(LinkedList *listToCompare){
    if(getLength() != listToCompare->getLength()){
        return false;
    }
    Node *current1 = getHead(), *current2 = listToCompare->getHead();
    if (current1){
        if(current1->getData() != current2->getData()){
            return false;
        }
        current2 = current2->getNext();
        current1 = current1->getNext();
    }
    return true;
}



int main(){
    LinkedList* list1 = new LinkedList();
    list1->push_back(3);
    list1->push_back(4);
    list1->push_back(5);
    list1->insert(2,2);
    list1->print();
    list1->reverse();
    list1->print();
    list1->remove(2);
    list1->print();
    list1->reverse();
    list1->print();
    LinkedList* list2 = new LinkedList();
    list2->push_back(3);
    list2->push_back(2);
    list2->push_back(5);

    LinkedList *list3 = list2;
    cout << endl << "list 3 elements : " << endl;
    list3->print();
    cout << endl;
    cout << "Length of the list : " << list1->getLength() << endl;
    cout << "List1 " << ((list1->isEqualTo(list2))?"is":"is not") << " equal to list2" << endl;
    cout << "List " << ((list1->isPalindrom())?"is":"is not") << " a palindrome" << endl;
    list1->print();
    return -1;
}
