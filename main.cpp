#include "ReservationRequest.hpp"
#include "ReservationSystem.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
    
    // Criando uma instância de sistema de reservas, com 3 salas e suas capacidades alunos
    int capacities[3] = {30, 50, 80};
    ReservationSystem system(3, capacities);

    // Reservas já realizadas

    ReservationRequest req1("Data Structures", "segunda", 7, 9, 30);
    
    if (system.reserve(req1)) {
    std::cout << "reserva bem sucedida! "<< std::endl;
    }
    else{
    std::cout << "essa reserva não é possível. Tente outra"<<std::endl;
    }

    ReservationRequest req2("Calculus", "segunda", 8, 10, 30);
    if (system.reserve(req2)) {
    std::cout << "reserva bem sucedida! "<< std::endl;
    }
    else{
    std::cout << "essa reserva não é possível. Tente outra"<<std::endl;
    }

    if (system.cancel("Calculus")) {
    std::cout << "reserva cancelada!" << std::endl;
    } else {
    std::cout << "disciplina não encontrada." << std::endl;
    }

    ReservationRequest req3("Calculus", "segunda", 11, 13, 50);
    system.reserve(req3);

    ReservationRequest req4("Probability", "quarta", 7, 9, 50);
    system.reserve(req4);

    ReservationRequest req5("Machine Learning", "quinta", 15, 17, 80);
    system.reserve(req5);

    //cout << "Reserva(s) realizadas com sucesso" << endl;
    system.printSchedule();

    return 0;
}