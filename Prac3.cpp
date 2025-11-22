#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

struct Cuenta { // Estructura para representar una cuenta bancaria
    int id;          // Numero de cuenta
    string titular;  // Nombre del dueño
    double saldo;    // Saldo actual
};


const int NUM_CUENTAS = 3; // Numero de cuentas predefinidas

Cuenta cuentas[NUM_CUENTAS] = { // Arreglo de cuentas predefinidas
    {1001, "Juan Perez", 1500.0}, // Cuenta predefinida
    {1002, "Maria Lopez", 2500.0}, // Cuenta predefinida
    {1003, "Carlos Ruiz", 500.0} // Cuenta predefinida
};
