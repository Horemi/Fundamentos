//hay que quitar, lo de crear una base de datos, porque ya habra una, solo hay que abrila.
#include <iostream>
#include <string>
#include "Database.h"  // Incluir el archivo donde está la clase Database

using namespace std;

// Función para agregar un medicamento a la base de datos
void agregarMedicamento(Database& db, const string& codigoPaciente) {
    string nombreMedicamento;
    int dosisMedicamento;
    string horarioMedicamento;
    
    cout << "Ingrese el nombre del medicamento: ";
    cin.ignore(); 
    getline(cin, nombreMedicamento);  

    cout << "Ingrese la dosis del medicamento: ";
    cin >> dosisMedicamento; 

    cout << "Ingrese los horarios de las dosis (separados por comas, por ejemplo: 8:00, 14:00): ";
    cin.ignore();  
    getline(cin, horarioMedicamento);

    // Insertar el medicamento en la base de datos
    db.agregarMedicamento(nombreMedicamento, dosisMedicamento, horarioMedicamento, codigoPaciente);

    // Confirmar que el medicamento se ha agregado correctamente
    cout << "Medicamento '" << nombreMedicamento << "' agregado correctamente." << endl;
}

// Función para mostrar los medicamentos de un paciente
void mostrarMedicamentos(Database& db, const string& codigoPaciente) {
    string query = "SELECT NOMBRE, DOSIS, HORARIO FROM Medicamentos WHERE CODIGO_PACIENTE = '" + codigoPaciente + "';";
    db.selectlist(query);  // Llamada a la función de consulta que muestra los medicamentos del paciente
}
void monitoreoMedicamentos(Database& db, const string& codigoPaciente) {
    string query = "SELECT NOMBRE, DOSIS, HORARIO FROM Medicamentos WHERE CODIGO_PACIENTE = '" + codigoPaciente + "';";
    db.selectmoni(query);  // Llamada a la función de consulta que muestra los medicamentos del paciente
}

int main() {
    // Crear instancia de la base de datos
    Database db("mi_base_de_datos.db");

    // Crear la tabla de medicamentos si no existe
    db.crearTablaMedicamentos();

    int opcion;
    string codigoPaciente = "codigo123";  // Suponiendo que el paciente tenga este código

    // Selección del tipo de usuario
    int tipoUsuario;
    do {
        cout << "Selecciona el tipo de usuario:" << endl;
        cout << "1. Paciente" << endl;
        cout << "2. Cuidador/Médico" << endl;
        cout << "Seleccione una opción: ";
        cin >> tipoUsuario;

        if (tipoUsuario == 1) {
            // Menú Paciente
            do {
                cout << "Menu de Opciones: " << endl;
                cout << "1. Lista de medicamentos" << endl;
                cout << "2. Monitorear cumplimiento de tratamiento" << endl;
                cout << "0. Salir" << endl;
                cout << "Seleccione una opción: ";
                cin >> opcion;

                switch (opcion) {
                case 1:
                    // Mostrar medicamentos del paciente
                    mostrarMedicamentos(db, codigoPaciente);
                    break;

                case 2:
                    //mostrar monitoreo (simulacion, todo si)
                    monitoreoMedicamentos(db, codigoPaciente);
                    break;

                case 0:
                    cout << "Saliendo del programa...\n";
                    break;

                default:
                    cout << "Opción no válida. Por favor, seleccione una opción válida.\n";
                }

            } while (opcion != 0);

        }
        else if (tipoUsuario == 2) {
            // Menú Cuidador o Médico
            do {
                cout << "Menu de Opciones: " << endl;
                cout << "1. Lista de medicamentos" << endl;
                cout << "2. Monitorear cumplimiento de tratamiento" << endl;
                cout << "3. Agregar medicamentos" << endl;
                cout << "0. Salir" << endl;
                cout << "Seleccione una opción: ";
                cin >> opcion;

                switch (opcion) {
                case 1:
                    // Mostrar medicamentos del paciente
                    mostrarMedicamentos(db, codigoPaciente);
                    break;

                case 2:
                    // mostrar monitoreo(simulacion, todo si)
                    monitoreoMedicamentos(db, codigoPaciente);
                    break;

                case 3:
                    // Agregar medicamentos
                    agregarMedicamento(db, codigoPaciente);
                    break;

                case 0:
                    cout << "Saliendo del programa...\n";
                    break;

                default:
                    cout << "Opción no válida. Por favor, seleccione una opción válida.\n";
                }

            } while (opcion != 0);

        }
        else {
            cout << "Opción no válida. Por favor, seleccione una opción válida.\n";
        }

    } while (tipoUsuario != 0);

    return 0;
