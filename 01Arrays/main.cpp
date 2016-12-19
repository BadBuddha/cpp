#include <iostream>

using namespace std;

class GameEntry{
    public:
        GameEntry(const string& n ="", int s=0);
        string getName() const;
        int getScore() const;
    private:
        string name;
        int score;
};
GameEntry :: GameEntry(const string& n, int s): name(n), score(s){}
string GameEntry :: getName() const { return name;}
int GameEntry :: getScore() const {return score;}


class Scores{
    public:
        Scores(int maxEntry = 10);
        ~Scores();
        void add(const GameEntry& e);
        GameEntry remove(int i) throw(IndexOutOfBounds);
    private:
        int maxEntries;
        int numEntries;
        GameEntry* entries;
};

Scores :: Scores(int maxEnt){
    maxEntries = maxEnt;
    entries = new GameEntry[maxEntries];
    numEntries = 0;
}

void Scores :: add(const GameEntry& e){
    int newScore = e.getScore();
    if (numEntries == maxEntries){
        if(newScore <= entries[maxEntries-1].getScore())
            return;
    }
    else
        numEntries++;
    int i = numEntries - 2; //start with next to last
    while(i >= 0 && newScore > entries[i].getScore()){
        entries[i+1] = entries[i];
        i--;
    }
    entries[i+1] = e;
}

GameEntry Scores :: remove(int i) throw(IndexOutOfBounds){
    if((i< 0) || i >= numEntries)
        throw IndexOutOfBounds("Invalid Index");
    GameEntry e = entries[i];
    for(int j = i+1; j < numEntries; j++)
        entries[j-1] = entries[j];
    numEntries--;
    return e;
}

int main(){
    /*GameEntry* ge1;
    ge1 = new */GameEntry ge1("Aniket",999);
    Scores s(5);
    s.add(ge1);
}
