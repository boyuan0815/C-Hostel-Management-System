#ifndef _ADMIN_H_
#define _ADMIN_H_
#include "Room.h"
#include "listRoom.h"
#include <iostream>
using namespace std;

class Student{
    private: 
        string studentID;
        string studentName;
        Room room;
    public: 
        Student ();
        void setStudentID(string);
        void setStudentName(string);
        string getStudentID();
        string getStudentName();
        void printDetail();
        void addRoom(listRoom, int, int&, bool);
};
#endif