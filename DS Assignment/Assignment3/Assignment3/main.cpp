#include <iostream>
#include "ArrayQueue.h" 
#include <fstream>
using namespace std;

struct listNodeType {
    ArrayQueue<char>* queue;
    listNodeType* back;
    listNodeType* next;
};

class DLCList {
public:
    DLCList(int n = 6);
    ~DLCList() {};
    bool deleteCurrent();
    ArrayQueue<char>* getCurrentQueue() const;
    void goBackward(int nNodes);
    void goForward(int nNodes);
    bool isEmpty();

private:
    listNodeType* cur;
};

DLCList::DLCList(int n) {
    listNodeType* head = new listNodeType;
    head->queue = new ArrayQueue<char>;
    this->cur = head;
    for (int i = 1; i < n; i++) {
        listNodeType* newNode = new listNodeType;
        newNode->queue = new ArrayQueue<char>;
        newNode->back = this->cur;
        newNode->next = head;
        this->cur->next = newNode;
        head->back = newNode;
        this->cur= newNode;
    }

    this->cur = head;
}



bool DLCList::deleteCurrent() {
    if (this->cur == nullptr) return false;

    listNodeType* trailCur = this->cur->back;
    listNodeType* nextCur = this->cur->next;
    trailCur->next = nextCur;
    nextCur->back = trailCur;
    delete this->cur->queue;
    delete this->cur;
    if (nextCur == this->cur) {
        this->cur = nullptr;
    }
    else {
        this->cur = nextCur;
    }
    return true;
}


ArrayQueue<char>* DLCList::getCurrentQueue() const {

    if (this->cur == nullptr) return 0;
    else return this->cur->queue;

}

void DLCList::goForward(int nNodes) {

    int count = 0;
    while (count != nNodes)
    {
        this->cur = this->cur->next;
        count++;
    }
}

void DLCList::goBackward(int nNodes) {

    int count = 0;
    while (count != nNodes)
    {
        this->cur = this->cur->back;
        count++;
    }
}

bool DLCList::isEmpty() {
    return bool(this->cur == nullptr);
}

int main() {
    ifstream in;
    in.open("messageQ.txt");
    if (!in) {
        cerr << "can't open file ... messageQ.txt" << endl;
        exit(0);
    }

    int n;
    in >> n;

    DLCList DL(n);

    in >> n;
    char op;
    char ch;
    ArrayQueue<char>* curQueue;

    while (!in.eof()) {
        if (n < 0) DL.goBackward(-n);
        else if (n > 0) DL.goForward(n);
        else {
            in >> op;
            switch (op) {

            case 'E': {
                in >> ch;
                curQueue = DL.getCurrentQueue();
                curQueue->addQueue(ch);
                break;
            }
            case 'D': {
                DL.deleteCurrent();
                break;
            }
            default:
                break;
            }
        }
        in >> n;
    }

    while (!DL.isEmpty()) {
        curQueue = DL.getCurrentQueue();
        while (!curQueue->isEmpty()) {
            curQueue->deQueue();
        }
        cout << " ";
        DL.deleteCurrent();
    }
    cout << endl;
    return 0;
}
