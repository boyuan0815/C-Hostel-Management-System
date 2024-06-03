#include "Student.h"
#include "Room.h"
#include "listRoom.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

const string line (60, '-');
const string header = line + "\n             Cooling Hostel Management System\n" + line + "\n";
const string add_booking_menu = "1) Add or modify the room\n2) Return to last page\nChoose your choice => ";

Student::Student()
{
    studentID="";
    studentName="";
}

void Student::setStudentID(string _studentID){studentID = _studentID;}

void Student::setStudentName(string _studentName){studentName = _studentName;}

string Student::getStudentID(){return studentID;}

string Student::getStudentName(){return studentName;}

void Student::printDetail()
{
    cout << "Student Name: " << studentName << endl;
    cout << "Student ID: " << studentID << endl;
    cout << "Room Number: " <<  room.getRoomNumber() << endl;
    cout << "Room Type: " << room.getRoomType() << endl;
    cout << "Room Price: " << room.getRoomPrice() << endl;
    cout << "Duration: " << room.getDuration() << endl;
    cout << "Total price: " << room.getTotal() << endl;
}
void Student::addRoom (listRoom list, int size, int &total_student_added, bool newRoom) {
    string studentName, studentID;
    int roomNum;
    int student_choice5;
    int index;
    cout<<"Please enter your name: ";
    getline(cin,studentName);
    cout<<"Please enter your student ID: ";
    getline(cin,studentID);
    this->studentID = studentID;
    this->studentName = studentName;
    if (newRoom) {
        total_student_added++;
    }
    system("cls");
    do {
        cout << header << add_booking_menu;
        cin >> student_choice5;
        while (student_choice5 != 1 && student_choice5 != 2 ){
            cout<<"Sorry, please choose again your choice (1 or 2) => ";
            cin>>student_choice5;
        }
        cin.ignore();
        system("cls");
        if (student_choice5 == 1) {
           list.displayList();
            nodeRoom* indexMatched;
            //call searching function
            do {
                cout << "Enter the room number: ";
                cin >> roomNum;
                indexMatched = list.FindNode(roomNum);
                if (indexMatched) {
                    system("cls");
                    cout << header;
                    cout << "The room number is founded!\n\nMatched Room Detail:" << endl;
                    cout << "-------------------" << endl;
                    cout << "Room Number : " << indexMatched->NroomNumber << endl;
                    cout << "Room Type   : " << indexMatched->NroomType << endl;
                    cout << "Room Price  : " << indexMatched->NroomPrice << endl;
                    cout << "-------------------" << endl;
                }
                else {
                    cout<<"The room is not founded:(\n"<<endl;  
                } 
            } while (!indexMatched);

            room.setRoomNumber(indexMatched->NroomNumber);
            room.setRoomType(indexMatched->NroomType);
            room.setRoomPrice(indexMatched->NroomPrice);
            int duration;
            cout << "\n\nEnter the duration stay in the hostel (in days): ";
            cin >> duration;
            room.setDuration(duration);
            system("cls");
            cout << header << "Here is the details of the order: " << endl << endl;
            printDetail();
            cout << line << endl << endl;
            string NextPage;
            cout<<"Press \"Y\" or \"y\" to last page"<<": "<<right;
            cin>>NextPage;
            while (NextPage != "Y" && NextPage != "y"){
                cout<<"Sorry, please press \"Y\" or \"y\" to last page"<<": "<<right;
                cin>>NextPage;
            }
            system("cls");
        }
        else {
             break;
        }
    } while (true);
}