#include <iostream>
#include <string>
#include <assert.h>
#include <unistd.h>

using namespace std;

class Node{
    private:
        int data;
        //friend class LinkedList;
    public:
        Node(){};
        Node* next;
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
        void MoveNode(Node** destRef, Node** sourceRef);
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
    usleep(1000000);
    Node *head = *headRef;
    cout << "\nhead in mergesort : " << head->getData() << endl;
    Node *a, *b;
    if((head == NULL) || (head->getNext() == NULL)){
        cout << "returning" << endl;
        return;
    }
    frontBackSplit(head, &a, &b);
    Node *head1 = a;
    while(head1){
        cout << head1->getData() << "-->";
        //cout << "head2 : " << head->getNext()->getData();
        //cout << "head3 : " << head->getNext()->getNext()->getData();
        //cout << "head4 : " << head->getNext()->getNext()->getNext()->getData();
        head1 = head1->getNext();
    }
    head1 = b;
    while(head1){
        cout << head1->getData() << "-->";
        //cout << "head2 : " << head->getNext()->getData();
        //cout << "head3 : " << head->getNext()->getNext()->getData();
        //cout << "head4 : " << head->getNext()->getNext()->getNext()->getData();
        head1 = head1->getNext();
    }
    cout << "value of a data in mergeSort ->" << a->getData() << endl;
    cout << "value of b data in mergeSort ->" << b->getData() << endl;
    mergeSort(&a);
    cout << "here for second mergesort for a :" << a->getData() << endl;
    cout << "here for second mergesort for b :" << b->getData() << endl;
    mergeSort(&b);
    *headRef = sortedMerge(a,b);
    cout << "headRef : " << (*headRef)->getData() << endl;
    head = *headRef;
}


Node* LinkedList :: sortedMerge(Node *a, Node *b){
    /* a dummy first node to hang the result on */
    Node dummy;
    /* tail points to the last result node  */
    Node* tail = &dummy;
   /* so tail->next is the place to add new nodes
     to the result. */
   dummy.setNext(NULL);
   while (1){
       if (a == NULL){
           /* if either list runs out, use the
              other list */
           tail->setNext(b);
           break;
       }else if (b == NULL){
           tail->setNext(a);
           break;
       }
       if (a->getData() <= b->getData())
           MoveNode(&(tail->next), &a);
       else
           MoveNode(&(tail->next), &b);
       tail = tail->getNext();
   }
   return(dummy.getNext());
}


void LinkedList :: MoveNode(Node** destRef, Node** sourceRef)
{
    /* the front source node  */
    Node* newNode = *sourceRef;
    assert(newNode != NULL);
    /* Advance the source pointer */
    *sourceRef = newNode->getNext();
    /* Link the old dest off the new node */
    newNode->setNext(*destRef);
    /* Move dest to point to the new node */
    *destRef = newNode;
}


void LinkedList :: frontBackSplit(Node* headRef, Node** frontRef, Node** backRef){
    Node *fast, *slow;
    cout << "---------------here in headRef : " << headRef->getData() << endl;
    if(headRef==NULL || headRef->getNext()==NULL){
        // length < 3 cases
        cout << "---------------here in frontBackSplit" << endl;
        *frontRef = headRef;
        *backRef = NULL;
    }else{
        slow = headRef;
        cout << "Initial slow : " << slow->getData() << endl;
        fast = headRef->getNext();
        cout << "Iinitial fast : " << fast->getData() << endl;
        while(fast){
            fast = fast->getNext();
            //cout << "First fast : " << fast->getData() << endl;
            cout << "Fist slow : " << slow->getData() << endl;
            if (fast){
                slow = slow->getNext();
                fast = fast->getNext();
                cout << "Second slow : " << slow->getData() << endl;
                //cout << "Second fast : " << fast->getData() << endl;
            }
        }
        *frontRef = headRef;
         *backRef = slow->getNext();
        //cout << "" << endl;
        cout << "backRef : " << (*backRef)->getData() << endl;
        cout << "frontRef : " << (*frontRef)->getData() << endl;
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
        cout << head->getData() << "-->";
        //cout << "head2 : " << head->getNext()->getData();
        //cout << "head3 : " << head->getNext()->getNext()->getData();
        //cout << "head4 : " << head->getNext()->getNext()->getNext()->getData();
        head = head->getNext();
    }

    list.print();
    return -1;
}
