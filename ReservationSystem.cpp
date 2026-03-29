#include "ReservationRequest.hpp"
#include "ReservationSystem.hpp"
#include <iostream>
#include <string>

//Construtor: não há return type
ReservationSystem::ReservationSystem(int room_count, int* room_capacities) {
    this->room_count = room_count;
    this->room_capacities = new int[room_count];

    for(int i=0; i<room_count; i++) {
        this->room_capacities[i] = room_capacities[i];
    }
}

//Destrutor: não há return type
ReservationSystem::~ReservationSystem() {
    delete[] this->room_capacities;
}
bool ReservationSystem::reserve(ReservationRequest request) {

}

bool ReservationSystem::cancel(std::string course_name) {

}

void ReservationSystem::printSchedule() {
    std::cout << "Cronograma" << std::endl;
    


}