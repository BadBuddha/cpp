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
        void frontBackSplit(Node* headRef, Node** frontRef, Node** backRef);
        Node* sortedMerge(Node *a, Node *b);
    public:
        LinkedList();
        ~LinkedList();
        bool isEmpty() const;
        void print();
        bool insert(int data, int position);
        bool remove(int data);
        void push_back(int data);
        Node* getHead(){return head;}
        void mergeSort(Node **headRef);

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
    //cout << "so far good" << endl;
    while(temp->getNext()!= NULL){
        //cout << "so far good2" << endl;
        temp = temp->getNext();
    }
    length++;
    temp->setNext(newNode);
}


void LinkedList :: mergeSort(Node** headRef){
    Node *head = *headRef;
    //cout << "\nhead in mergesort : " << head->getData() << endl;
    Node *a, *b;
    if((head == NULL) || (head->getNext() == NULL)){
        //cout << "\nreturning";
        return;
    }
    frontBackSplit(head, &a, &b);
    //cout << "value of a data in mergeSort ->" << a->getData() << endl;
    //cout << "value of b data in mergeSort ->" << b->getData() << endl;
    Node *head1 = a;
    cout << "\n";
    while(head1){
        cout << head1->getData() << "-->";
        head1 = head1->getNext();
    }
    cout << "    b : ";
    head1 = b;
    while(head1){
        cout << head1->getData() << "-->";
        head1 = head1->getNext();
    }

    mergeSort(&a);
    //cout << "-----------------------------------------" << endl;
    //cout << "here for second mergesort for a :" << a->getData() << endl;
    //cout << "here for second mergesort for b :" << b->getData() << endl;
    mergeSort(&b);
    *headRef = sortedMerge(a,b);
    //cout << "headRef : " << (*headRef)->getData() << endl;
    head = *headRef;
}

Node* LinkedList :: sortedMerge(Node *a, Node *b){
    Node *result = NULL;

    if(a == NULL) return b;
    else if (b == NULL) return a;
    //cout << "value of a data " << a->getData() << endl;
    //cout << "value of b data " << b->getData() << endl;
    if(a->getData() <= b->getData()){
        result = a;
        //cout << "value of result a " << result->getData() << endl;
        result->setNext(sortedMerge(a->getNext(), b));
    }else{
        result = b;
        //cout << "value of result b " << result->getData() << endl;
        result->setNext(sortedMerge(a,b->getNext()));
    }
    //cout << "result->getNext data : " << result->getNext()->getData() << endl;
    //print();
    return result;
}

void LinkedList :: frontBackSplit(Node* headRef, Node** frontRef, Node** backRef){
    Node *fast, *slow;
    //cout << "---------------here in headRef : " << headRef->getData() << endl;
    if(headRef==NULL || headRef->getNext()==NULL){
        // length < 3 cases
        //cout << "---------------here in frontBackSplit" << endl;
        *frontRef = headRef;
        *backRef = NULL;
    }else{
        slow = headRef;
        //cout << "Initial slow : " << slow->getData() << endl;
        fast = headRef->getNext();
        //cout << "Iinitial fast : " << fast->getData() << endl;
        while(fast){
            fast = fast->getNext();
            //cout << "First fast : " << fast->getData() << endl;
            //cout << "Fist slow : " << slow->getData() << endl;
            if (fast){
                slow = slow->getNext();
                fast = fast->getNext();
                //cout << "Second slow : " << slow->getData() << endl;
                //cout << "Second fast : " << fast->getData() << endl;
            }
        }
        *frontRef = headRef;
        *backRef = slow->getNext();
        //cout << "" << endl;
        //cout << "backRef : " << (*backRef)->getData() << endl;
        //cout << "frontRef : " << (*frontRef)->getData() << endl;
        slow->setNext(NULL);
    }

}

int main(){
    LinkedList list;
    list.push_back(15);
    list.push_back(10);
    list.push_back(5);
    //list.insert(2,2);
    list.push_back(20);
    list.push_back(3);
    list.push_back(2);
    //list.push_back(9);
    list.print();
    //list.remove(2);
    //list.print();
    Node *head = list.getHead();
    list.mergeSort(&head);
    while(head){
        cout << head->getData() << "-->" ;
    //cout << "head2 : " << head->getNext()->getData();
    //cout << "head3 : " << head->getNext()->getNext()->getData();
    //cout << "head4 : " << head->getNext()->getNext()->getNext()->getData();
        head = head->getNext();
    }

    //list.print();
    return -1;
}
