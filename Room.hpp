#ifndef ROOM_HPP
#define ROOM_HPP
#include <string>
class Room {

private:
    // nome da sala
    std::string room_name;
    int room_capacity;
    // dinâmicas listas dos horários da sala para determinado dia
    int* occupied_monday;
    int* occupied_tuesday;
    int* occupied_wednesday;
    int* occupied_thursday;
    int* occupied_friday;

public:
    Room(std::string room_name, int room_capacity);
    ~Room();

    //getters
    std::string getRoomName();
    int getCapacity();

    void append_monday();

};


#endif