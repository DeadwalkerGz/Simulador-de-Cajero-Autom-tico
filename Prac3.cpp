#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>

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


void mostrarMenu() { // funcion para mostrar el menu principal
    cout << "\n===== CAJERO AUTOMÁTICO =====\n"; // Titulo del menu
    cout << "1. Consultar saldo\n"; // Opcion 1 del menu
    cout << "2. Depositar\n"; // Opcion 2 del menu
    cout << "3. Retirar\n"; // Opcion 3 del menu 
    cout << "4. Transferir\n"; // Opcion 4 del menu
    cout << "5. Salir\n"; // Opcion 5 del menu
}

int leerEntero(const string &mensaje) { // funcion para leer un entero con validacion
    int valor; // variable para almacenar el valor ingresado
    cout << mensaje; // mostrar el mensaje al usuario

    // Si la entrada NO es un entero válido:
    if (!(cin >> valor)) { // intentar leer el valor
        cin.clear(); // limpiar error interno de cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar el buffer
        throw runtime_error("Entrada no válida. Debe ingresar un número entero."); // lanzar excepción
    }

    return valor; // devolver el valor leído
}

double leerMontoPositivo(const string &mensaje) { // funcion para leer un monto positivo con validacion
    double monto; // variable para almacenar el monto ingresado
    cout << mensaje; // mostrar el mensaje al usuario

    // Validar que la entrada sea numérica
    if (!(cin >> monto)) { // intentar leer el monto
        cin.clear(); // limpiar error interno de cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiar el buffer
        throw runtime_error("Entrada no válida. Debe ingresar un número."); // lanzar excepción
    }

    // Validar que el número sea positivo
    if (monto <= 0) { // verificar si el monto es menor o igual a cero
        throw runtime_error("El monto debe ser mayor que cero."); // lanzar excepción
    }

    return monto;    // devolver el monto leído
}
int buscarCuenta(Cuenta cuentas[], int numCuentas, int idBuscado) { // funcion para buscar una cuenta por su ID
    for (int i = 0; i < numCuentas; i++) { // recorrer el arreglo de cuentas
        if (cuentas[i].id == idBuscado) { // si se encuentra la cuenta
            return i; // devuelve la posición donde está la cuenta
        }
    }
    throw runtime_error("La cuenta ingresada no existe."); // lanzar excepción si no se encuentra la cuenta
}