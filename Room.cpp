#include "Room.hpp"
#include <iostream>

Room::Room() {
    capacity = 0;
    count = 0;
    max_reservations = 10;
    reservations = new Reservation[10];
}

//transforma os dias em numeros
int dayToNumber(std::string day) {
    if (day == "segunda") return 1;
    if (day == "terca")   return 2;
    if (day == "quarta")  return 3;
    if (day == "quinta")  return 4;
    if (day == "sexta")   return 5;
    return -1;
}

//organiza por dia e horario
bool comeFirst(Reservation a, Reservation b) {
    if (dayToNumber(a.getWeekday()) < dayToNumber(b.getWeekday())) {
        return true;
    }
    else if (dayToNumber(a.getWeekday()) == dayToNumber(b.getWeekday())) {
        if (a.getStartHour() < b.getStartHour()) {
            return true;
        }
        return false;
    }
    else {
        return false;
    }
}

//construtor
Room::Room(int capacity) {
    this->capacity = capacity;
    this->count = 0;
    this->max_reservations = 10;
    this->reservations = new Reservation[this->max_reservations];
}

//destrutor
Room::~Room() {
    delete[] reservations;
}

// getters
int Room::getCapacity() {
    return capacity;
}

int Room::getCount() {
    return count;
}

// impede overlapping de reservas
bool Room::addReservation(Reservation reservation) {

    for (int i = 0; i < count; i++) {
        Reservation current = reservations[i];
        if (current.getWeekday() == reservation.getWeekday()) {
            if (reservation.getStartHour() < current.getEndHour() && current.getStartHour() < reservation.getEndHour()) {
                return false; 
            }
        }
    }

    //aumenta o array caso chegue no limite - array dinamico
    if (count == max_reservations) {
        int new_max = max_reservations * 2;
        Reservation* new_array = new Reservation[new_max];
        for (int i = 0; i < count; i++) {
            new_array[i] = reservations[i];
        }
        delete[] reservations;
        reservations = new_array;
        max_reservations = new_max;
    }

    reservations[count] = reservation;
    count++;
    return true;
}

//organiza o array apos remoção
bool Room::removeReservation(std::string course_name) {
    for (int i = 0; i < count; i++) {
        if (reservations[i].getCourseName() == course_name) {
            for (int j = i; j < count - 1; j++) {
                reservations[j] = reservations[j + 1];
            }
            count--;
            return true;
        }
    }
    return false; 
}

// Ordena as reservas da sala por dia e horário usando Bubble Sort
void Room::sortReservations() {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - 1; j++) {
            if (comeFirst(reservations[j+1], reservations[j])) {
                Reservation temp = reservations[j];
                reservations[j] = reservations[j+1];
                reservations[j+1] = temp;
            }
        }
    }
}

Reservation Room::getReservation(int index) {
    return reservations[index];
}

//garante cópia correta entre salas, criando um array independente para cada objeto
Room& Room::operator=(const Room& other) {
    if (this != &other) {
        delete[] reservations;
        capacity = other.capacity;
        count = other.count;
        max_reservations = other.max_reservations;
        reservations = new Reservation[max_reservations];
        for (int i = 0; i < count; i++) {
            reservations[i] = other.reservations[i];
        }
    }
    return *this;
}