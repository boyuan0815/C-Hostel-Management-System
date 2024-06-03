#ifndef LISTROOM_H
#define LISTROOM_H
#include "Room.h"
#include <iostream>
using namespace std;

class nodeRoom{
    public: 
        int NroomNumber;
        string NroomType;
        int NroomPrice;
        nodeRoom* next;
        nodeRoom();
        nodeRoom(int,string,int);
};

class listRoom
{        
    private:
        nodeRoom* head;

    public:
        listRoom();
        // ~listRoom();

        bool IsEmpty() {return head == NULL; };
        void InsertNode(int);
        void InsertNode(int, string, int);
        nodeRoom* FindNode(int x);
        void deleteNode(int x);
        void displayList(void);
};

#endif