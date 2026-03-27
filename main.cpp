#include "ReservationRequest.hpp"
#include "ReservationSystem.hpp"
#include <iostream>
#include <string>
using namespace std;

int main() {
    int capacities[3] = {30, 50, 80};
    ReservationSystem system(3, capacities);

    string subject;
    cout << "Escolha a matéria que será ministrada nesse período" << endl;
    cin >> subject;
    ReservationRequest request1("Estrutura de Dados", "segunda", 7, 9, 30);
    ReservationRequest request2(subject, "segunda", 9, 10, 30);

    cout << "Verificando a disponibilidade de sala para este requerimento..." << endl;
    system.reserve(request1);

    cout << "Verificando a disponibilidade de sala para este requerimento..." << endl;
    system.reserve(request2);

    cout << "Reserva(s) realizadas com sucesso" << endl;
    system.printSchedule();

    return 0;
}