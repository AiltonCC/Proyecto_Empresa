#include <iostream>

using namespace std;

string ar1[50];
string ar2[50];
int ar3[50];
int ar4[50];
int n = 0;
float total = 0;

class Inventarios{
    public:
        string nombreproducto;
        int clave;
        string tipoproducto;
        float costop, costoinv;
    public:
        Inventarios();
        void AgregarP(string,string,int,float);
        virtual void MostrarInv();
        virtual void CalcularCosto();
};

class Facturacion : Inventarios{
    private:
        int folio;
        int dia,mes,anio;
        float vendido;
    public:
        Facturacion(int,int,int,int,float);
        virtual void MostrarInv();

};

class RRHH : Inventarios
{
private:
    string nombre;
    int empleado, RFC;
    float sueldo;
public:
    RRHH();
    virtual void MostrarInv();
    void AgregarE(string,int,int,float);
};

class Mantenimiento : Inventarios
{
private:
    int m1,m2,m3;
public:
    Mantenimiento(int, int, int);
    virtual void CalcularCosto();
};


Inventarios::Inventarios(){}
void Inventarios :: AgregarP(string nombreproducto, string tipoproducto, int clave, float costop){
    cout << "Ingrese el nombre del producto " << endl;
    cin >> nombreproducto;
    ar1[n] = nombreproducto;
    cout << "Ingrese el tipo de producto" << endl;
    cin >> tipoproducto;
    ar2[n] = tipoproducto;
    cout << "Ingrese la clave del producto" << endl;
    cin >> clave;
    ar3[n] = clave;
    cout << "Ingrese el costo del producto " << endl;
    cin >> costop;
    ar4[n] = costop;
    n++;
    
}

void Inventarios :: MostrarInv(){
    for(int i=0; i<=n-1; i++){
        cout << "Producto " << i+1 << endl;
        cout << "Nombre del producto: " << ar1[i] << endl;
        cout << "Tipo de producto: " << ar2[i] << endl;
        cout << "Clave del producto: " << ar3[i] << endl;
        cout << "Costo del producto: " << ar4[i] << "   pesos" << endl;
    }
}

void Inventarios :: CalcularCosto(){
    for(int i=0; i<=n-1; i++){
        total += ar4[i]; 
    }
    cout <<"El costo total pro producto en stock es: "  << total << endl;
}

Facturacion :: Facturacion (int f,int d,int m,int an,float v)
{
    folio = f;
    dia = d;
    mes = m;
    anio = an;
    vendido = v;
}

void Facturacion :: MostrarInv()
{
    cout << "Folio: " << folio << "\n Fecha: " << dia << "/" << mes << "/" << anio << "\n Valor que se tenia en inventario: " << total << "\n Valor vendido en el mes: " << vendido << endl;
}

RRHH :: RRHH(){}
void RRHH :: AgregarE(string a, int b, int c, float d)
{
    nombre = a;
    empleado = b;
    RFC = c;
    sueldo = d;
}

void RRHH :: MostrarInv()
{
    cout << "Empleado: " << nombre << endl;
    cout << "Clave: " << empleado << endl;
    cout << "RFC: " << RFC << endl;
    cout << "Sueldo: " << sueldo << endl;
}

Mantenimiento::Mantenimiento(int a1, int b1, int c1)
{
    m1 = a1;
    m2 = b1;
    m3 = c1;
}

void Mantenimiento::CalcularCosto()
{
    int totl = m1 + m2 + m3;
    cout << "Costo de mantenimiento: " << totl << endl;
}