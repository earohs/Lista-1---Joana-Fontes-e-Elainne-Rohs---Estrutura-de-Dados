#include <iostream>
#include "ReservationSystem.hpp"
#include "Room.hpp"
#include "Reservation.hpp"

// Construtor: inicializa o sistema criando um array de salas e atribuindo a capacidade correta para cada uma
ReservationSystem::ReservationSystem(int room_count, int* room_capacities) {
    this->room_count = room_count;
    this->rooms = new Room[room_count];
    for (int i = 0; i < room_count; i++) {
        rooms[i] = Room(room_capacities[i]);
    }
}

// Destrutor: libera o array de salas da memória, não há return type
ReservationSystem::~ReservationSystem() {
    delete[] rooms;
}

// Percorre as salas em ordem e tenta realizar a reserva na primeira que tiver capacidade suficiente e horário disponível
bool ReservationSystem::reserve(ReservationRequest request) {
    int start;
    int end;
    start = request.getStartHour();
    end = request.getEndHour();
    //Validações
    if(start<7 or start>20 or end<8 or end>21) {
        std::cerr << "Horário do requerimento fora do período de funcionamento do sistema\n";
        return false;
    }
    if(start>end) {
        std::cerr << "Horário de início deve ser anterior ao horário de término da reserva\n";
        return false;
    }

    for (int i = 0; i < room_count; i++) {
        Room& room = rooms[i];
        if (room.getCapacity() >= request.getStudentCount()) {
            Reservation nova(
                request.getCourseName(),
                request.getWeekday(),
                request.getStartHour(),
                request.getEndHour(),
                request.getStudentCount()
            );
            if (room.addReservation(nova)) {
                return true;
            }
        }
    }
    return false;
}

// Percorre as salas procurando a reserva pelo nome da disciplina
bool ReservationSystem::cancel(std::string course_name) {
    for (int i = 0; i < room_count; i++) {
        if (rooms[i].removeReservation(course_name)) {
            return true;
        }
    }
    return false; 
}

// Exibe a grade completa de reservas
void ReservationSystem::printSchedule() {
    for (int k = 0; k < room_count; k++) {
        std::cout << "Room " << k + 1 << std::endl;
        
        rooms[k].sortReservations();
        
        for (int l = 0; l < rooms[k].getCount(); l++) {
            std::cout << rooms[k].getReservation(l).getWeekday() << ":" << std::endl;
            std::cout << rooms[k].getReservation(l).getStartHour() << "h~" << rooms[k].getReservation(l).getEndHour() << "h: "<< rooms[k].getReservation(l).getCourseName() << std::endl;
        }
        
        std::cout << std::endl; 
    }
}
