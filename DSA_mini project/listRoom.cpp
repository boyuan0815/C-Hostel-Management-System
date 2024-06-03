#include "listRoom.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
const string line (60, '-');
const string header = line + "\n             Cooling Hostel Management System\n" + line + "\n";

nodeRoom::nodeRoom(){
    NroomNumber = 0;
    NroomType = "";
    NroomPrice = 0;
}

nodeRoom::nodeRoom(int n, string t, int p){
    NroomNumber = n;
    NroomType = t;
    NroomPrice = p;
}

listRoom::listRoom()
{
    head=NULL;
}

// cancel the destructor function definition because runtime error
// listRoom::~listRoom()
// {
//     nodeRoom* currNode = head, *nextNode = NULL;
//     while (currNode != NULL){
//         nextNode = currNode->next;
//         // destroy the current node
//         delete currNode;
//         currNode = nextNode; 
//     }
//     head = NULL;
// }

void listRoom::InsertNode(int roomNum)
{
    int currIndex = 0;
    nodeRoom* currNode = head;
    nodeRoom* prevNode = NULL;
    while (currNode && roomNum > currNode->NroomNumber) {
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }

    string newRoomType;
    int newRoomPrice;
    nodeRoom* newNode = new nodeRoom;
    cout<<"Enter the new room type   : ";
    cin>>newRoomType;
    cout<<"Enter the new room price  : ";
    cin>>newRoomPrice;
    newNode->NroomNumber = roomNum;
    newNode->NroomType = newRoomType;
    newNode->NroomPrice = newRoomPrice;

    if (currIndex == 0) {
        newNode->next  = head;
        head           = newNode;
    } 
    else {
        newNode->next  = prevNode->next;
        prevNode->next = newNode;
    }
}

void listRoom::InsertNode(int roomNum, string roomType, int roomPrice)
{
    int currIndex = 0;
    nodeRoom* currNode = head;
    nodeRoom* prevNode = NULL;
    while (currNode && roomNum > currNode->NroomNumber) {
        prevNode = currNode;
        currNode = currNode->next;
        currIndex++;
    }

    nodeRoom* newNode = new nodeRoom;
    newNode->NroomNumber = roomNum;
    newNode->NroomType = roomType;
    newNode->NroomPrice = roomPrice;

    if (currIndex == 0) {
        newNode->next  = head;
        head           = newNode;
    } 
    else {
        newNode->next  = prevNode->next;
        prevNode->next = newNode;
    }

}

nodeRoom* listRoom::FindNode(int num)
{
    nodeRoom* currNode = head;
    int currIndex= 1;
    while (currNode && currNode->NroomNumber != num) {
        currNode = currNode->next; 
        currIndex++;
    }
    if(currNode) return currNode;
    return NULL;
}


void listRoom::deleteNode(int roomnum)
{
    nodeRoom* prevNode = NULL;
    nodeRoom* currNode = head;
    int currIndex= 1;
    while (currNode && currNode->NroomNumber != roomnum) {
        prevNode = currNode;
        currNode = currNode->next; 
        currIndex++;
    }

    if (currNode){
        if(prevNode){  
            prevNode->next = currNode->next;
            delete currNode;
        }
        else{ 
            head = currNode->next;
            delete currNode;
        }
    }
}

void listRoom::displayList(void)
{   
    cout << header;
    string line (60, '-');
    cout << setw(16) << "Room Number" << setw(18) << "Room Type" << setw(21) << "Room Price\n"<< line << endl;
    nodeRoom* currNode = head;
    while (currNode != NULL){
        cout << setw(12) << currNode->NroomNumber << setw(20) << currNode->NroomType << setw(18) << currNode->NroomPrice <<endl;
        currNode = currNode->next;
    }
    cout << line << endl;
}
