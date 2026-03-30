#ifndef RESERVATION_HPP
#define RESERVATION_HPP
#include <string>

// Representa uma reserva confirmada no sistema
// armazenando os dados de uma aula
class Reservation {
private:
    std::string course_name;
    std::string weekday;
    int start_hour;
    int end_hour;
    int student_count;
public:
    Reservation& operator=(const Reservation& other); // cópia correta entre objetos
    Reservation();
    Reservation(std::string course_name, std::string weekday, int start_hour, int end_hour, int student_count);
    
    // Getters
    std::string getCourseName();
    std::string getWeekday();
    int getStartHour();
    int getEndHour();
    int getStudentCount();
};
#endif