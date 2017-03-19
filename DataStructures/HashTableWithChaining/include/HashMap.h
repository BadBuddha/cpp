#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include "HashEntry.h"

using namespace std;

const int TABLE_SIZE = 128;

class HashMap{
    private:
        HashEntry **table;
    public:
        HashMap();
        ~HashMap();
        int get(int key);
        void put(int key, int value);
};

HashMap :: HashMap(){
    table = new HashEntry*[TABLE_SIZE];
    for(int i = 0; i< TABLE_SIZE; i++){
        table[i] = NULL;
    }
}

int HashMap :: get(int key){
    int hash = (key % TABLE_SIZE);
    while(table[hash] != NULL && table[hash]->getKey() != key){
        hash = (hash+1) % TABLE_SIZE;
    }
    if (table[hash] == NULL)
        return -1;
    else
        return table[hash]->getValue();
}

void HashMap :: put(int key, int value){
    int hash = (key % TABLE_SIZE);
    while (table[hash] != NULL && table[hash]->getKey() != key){
        hash = (hash + 1)% TABLE_SIZE;
    }
    if (table[hash] != NULL){
        delete table[hash];
    }
    table[hash] = new HashEntry(key, value);
}

HashMap :: ~HashMap(){
    for(int i = 0;i < TABLE_SIZE; i++ ){
        if (table[i] != NULL)
            delete table[i];
    }
    delete[] table;
}


#endif
