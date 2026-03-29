#ifndef ROOM_HPP
#define ROOM_HPP

class Room {

private:
    // capacidade méxima de alunos na sala
    int capacity;
    // disponibilidade de cada sala para determinado dia e horário
    bool* room_available;

public:
    Room(int capacity);
    ~Room();

};


#endif