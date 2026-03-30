#ifndef ROOM_HPP
#define ROOM_HPP
#include <string>
#include "Reservation.hpp"

// Representa uma sala de aula no sistema
class Room {
private:
    int capacity;
    int count;
    int max_reservations;
    Reservation* reservations;

public:
    Room& operator=(const Room& other);
    Room();
    Room(int capacity);
    ~Room();
// Getters
    int getCapacity();
    int getCount();

    bool addReservation(Reservation reservation);
    bool removeReservation(std::string course_name); 
    void sortReservations();
    Reservation getReservation(int index);
};

#endif