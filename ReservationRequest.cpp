#include "ReservationRequest.hpp"
#include <iostream>

//Inicialização do construtor
ReservationRequest::ReservationRequest(std::string course_name, std::string weekday, int start_hour, int end_hour, int student_count) {
    //Validações
    if(start_hour<7 or start_hour>20 or end_hour<8 or end_hour>21) {
        std::cerr << "Horário do requerimento fora do período de funcionamento do sistema\n";
    }
    if(start_hour>end_hour) {
        std::cerr << "Horário de início  deve ser anterior ao horário de término da reserva\n";
    }
    //Atributos
    this->course_name = course_name;
    this->weekday = weekday;
    this->start_hour = start_hour;
    this->end_hour = end_hour;
    this->student_count = student_count;
}
//Destrutor: como não há, por enquanto, nada a destruir, exceto a prórpia classe, ele não tem conteúdo
ReservationRequest::~ReservationRequest() {
    std::cout << "reservationrequest destruído" << std::endl; // linha apenas para verificação, depois será apagada
}
//Getters
int ReservationRequest::getStartHour() {
    return this->start_hour;
}

int ReservationRequest::getEndHour() {
    return this->end_hour;
}

std::string ReservationRequest::getCourseName() {
    return this->course_name;
}

std::string ReservationRequest::getWeekday() {
    return this->weekday;
}

int ReservationRequest::getStudentCount() {
    return this->student_count;
}