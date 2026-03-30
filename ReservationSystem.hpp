#ifndef RESERVATIONSYSTEM_HPP
#define RESERVATIONSYSTEM_HPP

#include "ReservationRequest.hpp"
#include "Room.hpp"
#include <iostream>
#include <string>

class ReservationSystem {

private:
    //quatidade de salas
    int room_count;
    //capacidade de alunos de cada sala
    int* room_capacities;

    // Estruturas internas escolhidas pelos alunos
    // para armazenar e gerenciar as reservas, os horários, ...
    std::string* room_names;
public:

    ReservationSystem(int room_count, int* room_capacities, std::string* room_names);
    ~ReservationSystem();

    bool reserve(ReservationRequest request);
    bool cancel(std::string course_name);
    void printSchedule();

    // Outros métodos utilitários necessários
    // para auxiliar nas funções requisitadas
    //void confirm_reservation();
    void setRooms(int* room_capacities, std::string* room_names, int room_count);
};

#endif