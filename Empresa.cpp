#include "Empresa.hpp"

int caso = 0,casos=0;
void RecHumanos();
void mantenimiento();
void factura();

int main()
{
    string nombreproducto;
    int clave;
    string tipoproducto;
    float costop;
    Inventarios x;

    while(1){
        cout << "Elija la opcion a revisar" << endl;
        cout << "1. Inventarios" << endl;
        cout << "2. Facturacion" << endl;
        cout << "3. Recursos Humanos" << endl;
        cout << "4. Mantenimiento" << endl;
        cout << "5. Salir" << endl;
        cin >> casos;
        
        switch (casos)
        {
        case 1:
            while(caso != 4){
        
                cout << "Ingrese la opcion que desea realizar " << endl;
                cout << "1. Ver Productos" << endl;
                cout << "2. Agregar Productos" << endl;
                cout << "3. Ver costo de Inventario en stock" << endl;
                cout << "4. Regresar" << endl;
                cin >> caso;
                switch (caso)
                {
                case 1:
                    x.MostrarInv();
                    break;

                case 2:
                    x.AgregarP(nombreproducto, tipoproducto, clave, costop);
                    break;

                case 3:
                    x.CalcularCosto();
                    break;

                default:
                    caso = 4;
                    break;
                }
            }
            break;
        
        case 2:
            factura();
            break;
        
        case 3:
            RecHumanos();
            break;
        
        case 4:
            mantenimiento();
            break;

        default:
            exit(0);
            break;
        }
    }
    return 0;
}

void factura()
{
    int folio;
    int dia,mes,anio;
    float vendido;
    cout << "Ingrese el folio de venta" << endl;
    cin >> folio;
    cout << "Dia: " << endl;
    cin >> dia;
    cout << "Mes: " << endl;
    cin >> mes;
    cout << "Año: " << endl;
    cin >> anio;
    cout << "Ingrese cuanto vendio en pesos" << endl;
    cin >> vendido;

    Facturacion fact( folio, dia, mes, anio, vendido);
    fact.MostrarInv();
}

void RecHumanos()
{
    string nombre;
    int numero, Rfc,cont=0;
    float sueldo;
    RRHH empleado[50];
    caso = 0;
    while (caso != 3)
    {
        cout << "Ingrese la opcion que desea realizar." << endl;
        cout << "1. Agregar Empleados" << endl;
        cout << "2. Ver Empleados" << endl;
        cout << "3. Regresar" << endl;
        cin >> caso;

        switch (caso)
        {
        case 1:
            cout << "Nombre: " << endl;
            cin >> nombre;
            cout << "Numero de empleado: " << endl;
            cin >> numero;
            cout << "RFC: " << endl;
            cin >> Rfc;
            cout << "Sueldo: " << endl;
            cin >> sueldo;
            empleado[cont].AgregarE(nombre,numero,Rfc,sueldo);
            cont++;
            break;
        
        case 2:
            for (size_t i = 0; i < cont; i++)
            {
                cout << i <<" .-";
                empleado[i].MostrarInv();
            }
            break;
            
        default:
            caso = 3;
            break;
        }
    }
}

void mantenimiento()
{
    int ob1,ob2,ob3;
    cout << "Costo de equipo: " << endl;
    cin >> ob1;
    cout << "Costo de uso de luz: " << endl;
    cin >> ob2;
    cout << "Costo de renta: " << endl;
    cin >> ob3;
    
    Mantenimiento mant(ob1,ob2,ob3);
    mant.CalcularCosto();
}