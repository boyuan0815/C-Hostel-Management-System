#ifndef _ROOM_H_
#define _ROOM_H_
#include <string>
using namespace std;
class Room{
    private: 
        int roomNumber;
        string roomType;
        int roomPrice;
        int duration;
    public: 
        Room (int = 0, string = "",int=0,int=0);
        void setRoomNumber(int);
        void setRoomType(string);
        void setRoomPrice(int);
        void setDuration(int);
        int getRoomNumber();
        string getRoomType();
        int getRoomPrice();
        int getDuration();
        int getTotal();
};
#endif