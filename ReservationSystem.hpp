#ifndef RESERVATIONSYSTEM_HPP
#define RESERVATIONSYSTEM_HPP
#include <string>
#include "Reservation.hpp"
#include "Room.hpp"
#include "ReservationRequest.hpp"

// Gerencia todas as salas e reservas do sistema
class ReservationSystem {
private:
    int room_count;
    Room* rooms;

public:
    ReservationSystem(int room_count, int* room_capacities);
    ~ReservationSystem();

    bool reserve(ReservationRequest request); // tenta realizar uma reserva na primeira sala disponível
    bool cancel(std::string course_name); // cancela a reserva de uma disciplina pelo nome
    void printSchedule(); // exibe a grade completa ordenada por sala, dia e horário
};

#endif