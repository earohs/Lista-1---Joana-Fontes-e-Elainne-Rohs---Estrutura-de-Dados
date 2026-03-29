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
    ReservationRequest request1("Estrutura de Dados", "segunda", 7, 9, 30);

    // Sua reserva
    string subject;
    string weekday;
    int start_hour;
    int end_hour;
    cout << "Escolha a matéria que será ministrada nesse período" << endl;
    cin >> subject;
    cout << "Escolha o dia da reserva" << endl;
    cin >> weekday;
    cout << "Horário de início da reserva" << endl;
    cin >> start_hour;
    cout << "Horário de término da reserva" << endl;
    cin >> end_hour;

    ReservationRequest request2(subject, "segunda", 9, 10, 30);

    cout << "Verificando a disponibilidade de sala para este requerimento..." << endl;
    system.reserve(request2);

    //cout << "Reserva(s) realizadas com sucesso" << endl;
    system.printSchedule();

    return 0;
}