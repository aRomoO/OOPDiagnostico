//
// Created by fredi on 2023-05-18.
//
//
// Created by fredi on 2023-05-17.
//

using namespace std;
#include "Habitacion.h"
#include "string"
#ifndef OOP_HOTEL_H
#define OOP_HOTEL_H

class Hotel{
private:
    string nombre;
    int numHabitaciones = 50;
    Habitacion * habitaciones[50] = {nullptr};
public:
    Hotel(string);
    int checkin(string, int, int, double);
    bool checkout(int);
    bool realizarCargosHabitacion(int, double);
    double getTotalXTarifaBase();
    void imprimeOcupacion();
};

Hotel::Hotel(string _nombre) {
    nombre = _nombre;
    numHabitaciones = 50;

}

int Hotel::checkin(string _nombreHuesped, int _adultos, int _infantes, double _credito) {

    //Check for Room Availability
    int i;
    for (i = 0; i <= numHabitaciones; i++)
    {
        if (habitaciones[i] == nullptr)
        {
            habitaciones[i] = new Habitacion(100+i);
            habitaciones[i]->checkin(_nombreHuesped,_adultos,_infantes,_credito);
            return habitaciones[i]->getNumero();
        }

    }

    return-1;

}

bool Hotel::checkout(int _numero) {
    if (_numero >= 100 && _numero <= 149)
    {
        habitaciones[100-_numero]->checkOut();
    }
    return false;
}

bool Hotel::realizarCargosHabitacion(int, double) {
    return false;
}

double Hotel::getTotalXTarifaBase() {
    return 0;
}

void Hotel::imprimeOcupacion() {

}


#endif //OOP_HOTEL_H
