#include "Room.hpp"

Room::Room(std::string room_name, int room_capacity) {
    this->room_name = room_name;
    this->room_capacity = room_capacity;
    this->occupied_monday = new int[14]; 
    this->occupied_tuesday = new int[14]; 
    this->occupied_wednesday = new int[14];
    this->occupied_thursday = new int[14]; 
    this->occupied_friday = new int[14];
    for(int i=0; i<14; i++) {
        this->occupied_monday[i]=0;
        this->occupied_tuesday[i]=0;
        this->occupied_wednesday[i]=0;
        this->occupied_thursday[i]=0;
        this->occupied_friday[i]=0;
    }

}

Room::~Room() {
    delete[] this->occupied_monday;
    delete[] this->occupied_tuesday;
    delete[] this->occupied_wednesday;
    delete[] this->occupied_thursday;
    delete[] this->occupied_friday;
}
