#include "ReservationRequest.hpp"
#include "ReservationSystem.hpp"
#include "Room.hpp"

//Construtor: não há return type
ReservationSystem::ReservationSystem(int room_count, int* room_capacities, std::string* room_names) {
    this->room_count = room_count;
    this->room_capacities = new int[room_count];
    this->room_names = new std::string[room_count];

    for(int i=0; i<room_count; i++) {
        this->room_capacities[i] = room_capacities[i];
        this->room_names[i] = room_names[i];
    }
}

//Destrutor: não há return type
ReservationSystem::~ReservationSystem() {
    delete[] this->room_capacities;
    delete[] this->room_names;
}

void ReservationSystem::setRooms(int* room_capacities, std::string* room_names, int room_count) {
    for(int i=0; i<room_count; i++) {
        Room this->room_names[i]()
    }
}

bool ReservationSystem::reserve(ReservationRequest request) {
    int start;
    int end;
    std::string course;
    start = request.getStartHour();
    end = request.getEndHour();
    course = request.getCourseName();
    //Validações
    if(start<7 or start>20 or end<8 or end>21) {
        std::cerr << "Horário do requerimento fora do período de funcionamento do sistema\n";
        return false;
    }
    if(start>end) {
        std::cerr << "Horário de início deve ser anterior ao horário de término da reserva\n";
        return false;
    }

}

bool ReservationSystem::cancel(std::string course_name) {
    std::cout << "Esta reserva foi cancelada" << std::endl;

}

void ReservationSystem::printSchedule() {
    std::cout << "Cronograma" << std::endl;

    


}