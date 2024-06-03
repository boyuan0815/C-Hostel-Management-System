#include "Room.h"
#include "Student.h"
#include "listRoom.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

const int maxStudentNumber = 100;
const string line (60, '-');
const string header = line + "\n             Cooling Hostel Management System\n" + line + "\n";
const string user_menu = "1) Admin\n2) Student\n3) Exit\n\nChoose your choice => ";

const string admin_menu = "1) View all student room booking.\n2) Modify Room\n3) Return last page\n4) Exit\n\nChoose your choice => ";
const string student_menu = "1) View menu\n2) Add order\n3) Return last page\n4) Exit\n\nChoose your choice => ";
const string check_room_menu = "Press 1 to view your room booking.\nPress 2 to modify your room booking.\nPress 3 to return to last page.\nChoose your choice => ";

int main() {
	
	int choice1;
	int admin_choice2;
	int student_choice2;
	int student_choice3;	
	
	string NextPage;
	Student student[maxStudentNumber];
	int total_student_added = 0;

	//determine the number of instance from data file
	int size = 0;
	ifstream infile("Room.txt");
	string holdInput;
	if (!infile) {
		cout << "Sorry, the file doesn't exist!" << endl;
		return 1;
	}
	else {
		while(getline(infile, holdInput))
			size++;
	}
	infile.close();
	
	//read information and form linked list
	int roomNum;
    string roomT;
    int roomP;	
	listRoom list;
	infile.open("Room.txt");
	for(int i=0; i<size; i++){
		infile>>roomNum>>roomT>>roomP;
		list.InsertNode(roomNum,roomT,roomP);
	}
	infile.close();

	//user interface
	cout << header << user_menu;
	cin >> choice1;
	while (choice1 != 1 && choice1 != 2 && choice1 != 3){
		cout << "Sorry, please choose again your choice (1,2 or 3) => ";
		cin >> choice1;
	}
	cin.ignore();
	system("cls");
	do {
		if (choice1 == 1) { //Admin
			cout << header << admin_menu;
			cin >> admin_choice2;
			while (admin_choice2 != 1 && admin_choice2 != 2 && admin_choice2 != 3 && admin_choice2 != 4){
				cout << "Sorry, please choose again your choice (1,2,3 or 4) => ";
				cin >> admin_choice2;
			}
			cin.ignore();
			system("cls");
			do {
				if (admin_choice2 == 1) {
					if (total_student_added == 0) {
						cout << header << "Sorry, there is no room booking added." << endl << endl;
						cout<<"Press \"Y\" or \"y\" to last page"<<": "<<right;
						cin>>NextPage;
						while (NextPage != "Y" && NextPage != "y"){
							cout << "Sorry, please press \"Y\" or \"y\" to last page"<<": "<<right;
							cin >> NextPage;
						}
						system("cls");
					}
					else {
						cout << header << "List of room booking: " << endl << endl;
						for (int i = 0 ; i < total_student_added ; i++) {
							student[i].printDetail();
							cout << line << endl;
						}
						cout<<"Press \"Y\" or \"y\" to last page"<<": "<<right;
						cin>>NextPage;
						while (NextPage != "Y" && NextPage != "y"){
							cout << "Sorry, please press \"Y\" or \"y\" to last page"<<": "<<right;
							cin >> NextPage;
						}
						system("cls");
					}
				}
				else if (admin_choice2 == 2) { 
					list.displayList();
					cout << "\nWhat operation do you want to perform? Select the option number:" <<endl;
					cout << "1. Add a new room into the menu" << endl;
					cout << "2. Remove a room from the menu" << endl;
					cout << "3. Search a room in the menu" << endl;
					cout << "4. Return to last page"<<endl;
					cout<<"Option: ";
					int opnum;
					cin >> opnum;
					while (opnum != 1 && opnum != 2 && opnum != 3 && opnum != 4){
						cout << "Sorry, please choose again your choice (1,2,3 or 4) => ";
						cin >> opnum;
					}
					cin.ignore();
                    system("cls");
					
					int newRoomNum;
					int deleteNum;
					int searchNum;
					nodeRoom* indexMatched;

					do {
						list.displayList();
						switch(opnum)
						{
							case 1:

							cout << "\nEnter new room number     : ";
							cin >> newRoomNum;
							while (list.FindNode(newRoomNum)) {
								cout << "\nSorry, the room number is already existed! \nEnter another room number : ";
								cin >> newRoomNum;
							}
							list.InsertNode(newRoomNum);
							cout << "Room successfully added !\n";
							break;

							case 2:
							cout << "\nEnter the room number of room you want to delete : ";
							cin >> deleteNum;
							while (!list.FindNode(deleteNum)) {
								cout << "Sorry, the room number is not existed! \nEnter another room number: ";
								cin >> deleteNum;
							}
							cout << "Room successfully deleted !\n";
							list.deleteNode(deleteNum);
							break;

							case 3:
							cout << "\nEnter the room number of room you want to search : ";
							cin >> searchNum;
							indexMatched = list.FindNode(searchNum);
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
							else{
								cout<<"The room is not founded:(\n"<<endl;  
							} 
							break;

							case 4:
							break;

							default:
							cout << "Please enter the available option number. " << endl;
							break;
						}
						if (opnum == 4) break;
						cout << endl << "Press \"Y\" or \"y\" to last page"<<": "<<right;
						cin >> NextPage;
						while (NextPage != "Y" && NextPage != "y"){
							cout << "Sorry, please press \"Y\" or \"y\" to last page"<<": "<<right;
							cin >> NextPage;
						}
						system("cls");
						list.displayList();
						cout << "\nWhat operation do you want to perform? Select the option number:" <<endl;
						cout << "1. Add a new room into the menu" << endl;
						cout << "2. Remove a room from the menu" << endl;
						cout << "3. Search a room in the menu" << endl;
						cout << "4. Return to last page"<<endl;
						cout<<"Option: ";
						cin >> opnum;
						while (opnum != 1 && opnum != 2 && opnum != 3 && opnum != 4){
							cout << "Sorry, please choose again your choice (1,2,3 or 4) => ";
							cin >> opnum;
						}
						cin.ignore();
						system("cls");
					} while (opnum == 1 || opnum == 2 || opnum == 3 || opnum == 4);
					system("cls");
				}
				else if (admin_choice2 == 3) break;
				else exit(1);

				cout << header << admin_menu;
				cin >> admin_choice2;
				while (admin_choice2 != 1 && admin_choice2 != 2 && admin_choice2 != 3 && admin_choice2 != 4){
					cout << "Sorry, please choose again your choice (1,2,3 or 4) => ";
					cin >> admin_choice2;
				}
				cin.ignore();
				system("cls");
			} while (admin_choice2 == 1 || admin_choice2 == 2 || admin_choice2 == 3 || admin_choice2 == 4);
		}
		else if (choice1 == 2) { //Student
			cout << header << student_menu;
			cin >> student_choice2;
			while (student_choice2 != 1 && student_choice2 != 2 && student_choice2 != 3 && student_choice2 != 4){
				cout << "Sorry, please choose again your choice (1,2,3 or 4) => ";
				cin >> student_choice2;
			}
			cin.ignore();
			system("cls");
			do{
				if (student_choice2 == 1) {
					list.displayList();
					cout << endl << "Press \"Y\" or \"y\" to last page"<<": "<<right;
						cin >> NextPage;
						while (NextPage != "Y" && NextPage != "y"){
							cout << "Sorry, please press \"Y\" or \"y\" to last page"<<": "<<right;
							cin >> NextPage;
						}
						system("cls");
				}
				else if (student_choice2 == 2) {
					cout << header ;
					student[total_student_added].addRoom(list, size, total_student_added, true);
					cout << header << check_room_menu;
					cin >> student_choice3;
					while (student_choice3 != 1 && student_choice3 != 2 && student_choice3 != 3){
						cout << "Sorry, please choose again your choice (1,2 or 3) => ";
						cin >> student_choice3;
					}
					cin.ignore();
					system("cls");
					do {
						if (student_choice3 == 1) {
							cout << header;
							student[total_student_added-1].printDetail();
							cout << line << endl << endl << "Press \"Y\" or \"y\" to last page"<<": "<<right;
							cin >> NextPage;
							while (NextPage != "Y" && NextPage != "y"){
								cout << "Sorry, please press \"Y\" or \"y\" to last page"<<": "<<right;
								cin >> NextPage;
							}
							system("cls");
						}
						else if (student_choice3 == 2) {
							cout << header;
							student[total_student_added-1].addRoom(list, size, total_student_added, false);
						}
						else break;
						cout << header << check_room_menu;
						cin >> student_choice3;
						while (student_choice3 != 1 && student_choice3 != 2 && student_choice3 != 3){
							cout << "Sorry, please choose again your choice (1,2 or 3) => ";
							cin >> student_choice3;
						}
						cin.ignore();
						system("cls");
					} while (student_choice3 == 1 || student_choice3 == 2 || student_choice3 == 3);
				}
				else if (student_choice2 == 3) break;
				else exit(1);
				cout << header << student_menu;
				cin >> student_choice2;
				while (student_choice2 != 1 && student_choice2 != 2 && student_choice2 != 3 && student_choice2 != 4){
					cout << "Sorry, please choose again your choice (1,2,3 or 4) => ";
					cin >> student_choice2;
				}
				cin.ignore();
				system("cls");
			} while (student_choice2 == 1 || student_choice2 == 2 || student_choice2 == 3 || student_choice2 == 4);
		}
		else exit(1);
		cout << header << user_menu;
		cin >> choice1;
		while (choice1 != 1 && choice1 != 2 && choice1 != 3){
			cout << "Sorry, please choose again your choice (1,2 or 3) => ";
			cin >> choice1;
		}
		cin.ignore();
		system("cls");
	} while (choice1 == 1 || choice1 == 2 || choice1 == 3);

	system("pause");
	return 0;
}