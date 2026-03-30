#include "Reservation.hpp"

// construtor - todos os dados das disciplinas

Reservation::Reservation(std::string course_name, std::string weekday, int start_hour, int end_hour, int student_count) {

    this->course_name = course_name;
    this->weekday = weekday;
    this->start_hour = start_hour;
    this->end_hour = end_hour;
    this->student_count = student_count;
}

// retorna o nome da disciplina
std::string Reservation::getCourseName() {
    return course_name;
}

// Retorna o dia da semana da reserva
std::string Reservation::getWeekday() {
    return weekday;
}

// Retorna o horário de início da aula
int Reservation::getStartHour() {
    return start_hour;
}

// Retorna o horário de término da aula
int Reservation::getEndHour() {
    return end_hour;
}

// Retorna o número de alunos da disciplina
int Reservation::getStudentCount() {
    return student_count;
}

// construtor vazio - array dinamico em Reservation
Reservation::Reservation() {
    course_name = "";
    weekday = "";
    start_hour = 0;
    end_hour = 0;
    student_count = 0;
}

// copia os dados de outra reserva
//evita cópias rasas de ponteiros
Reservation& Reservation::operator=(const Reservation& other) {
    course_name = other.course_name;
    weekday = other.weekday;
    start_hour = other.start_hour;
    end_hour = other.end_hour;
    student_count = other.student_count;
    return *this;
}