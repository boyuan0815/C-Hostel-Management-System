#include "Room.h"
#include <iostream>
using namespace std;

Room::Room(int _roomNumber, string _roomType, int _roomPrice, int _duration)
{
    roomNumber = _roomNumber;
    string roomType = _roomType;
    roomPrice = _roomPrice;
    duration = _duration;
}

void Room::setRoomNumber(int _roomNumber){roomNumber = _roomNumber;}

void Room::setRoomType(string _roomType){roomType = _roomType;}

void Room::setRoomPrice(int _roomPrice){roomPrice = _roomPrice;}

void Room::setDuration(int _duration){duration = _duration;}

int Room::getRoomNumber(){return roomNumber;}

string Room::getRoomType(){return roomType;}

int Room::getRoomPrice(){return roomPrice;}

int Room::getDuration(){return duration;}

int Room::getTotal(){return roomPrice*duration;}
