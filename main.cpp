#include <iostream>

int main(){
   

    std::cout << "Seleccione una opcion";
    int option;
    std::cin >> option;

    switch (option)
    {
    case 1:
            
        break;
    case 2:
        /* code */
        break;    
    default:
        break;
    }










   
   /* int x = 100;
    double result = 2.5*x;
    bool isBigger = x > 5;
    float sum =x + 3 * 2;

    std::cout << "Variable x: " << x << std::endl;
    std::cout << "The result of " << x << " * 2.5 is: " << result << std::endl;
    std::cout << "Is " << x << " > 5:? " << isBigger << std::endl;
    std::cout << "The Sum of " << x << " + 3 * 2 is: " << sum <<std::endl;


    std::cout<<std::endl;
    std::cout<<"operadores logicos"<<std::endl;
    bool c = true, e=false;
    bool AND=c&&e;
    bool OR=c||e;
    bool NOT=!c;
    bool NAND=!AND;
    bool NOR=!OR;
    bool XOR=((!c)&&e)||(c&&(!e));

    */
    return 0;
}









/*#include <iostream> //directiva de procesamiento (obligarorio)
#define PI 3.14159
using namespace std;   //No repetir std en cada variable verde
int variable = 3.5;

int funcion(float a, int b){
    cout<<"La suma es: " <<variable<<endl;
    return a+b;
}

int main(int argc, char* argv[]){  //Los atributos del main no son obligatorios
    //setlocale(LC-All,"Es_UTF-8");

    float variable2 = 3.5;
    double variable3 = 3.55;
    char variable4 ='1';
    bool variable5 = true;
    //Variables compuestas
    string cadena = "Este es un texto";
    int v1=1, v2=2, v3=3;
    int arreglo [6] ={1,2,3,4,5,6};
    //variables globales antes de la funcion main
    //Varibles locales dentro de cada función

    cout<<variable<<endl;
    variable=variable*variable;

    variable= funcion(3.55,2);
    cout<<"La suma es: "<<variable<<endl;
    cout<<"La variables es: "<<arreglo[5]<<endl;
    cout<<"EL tamaño de la variables  int es: "<<sizeof(variable)<<endl;
    cout<<"EL tamaño de la variables  float es: "<<sizeof(variable2)<<endl;
    cout<<"EL tamaño de la variables  double es: "<<sizeof(variable3)<<endl;
    cout<<"EL tamaño de la variables  char es: "<<sizeof(variable4)<<endl;
    cout<<"EL tamaño de la variables  bool es: "<<sizeof(variable5)<<endl;
    cout<<"EL tamaño de la variables  String es: "<<sizeof(cadena)<<endl;
    return 0;
}




#include <iostream>
#define PI 3.14159265359
#ifdef DEBUG

#endif //DEBUG

#pragma warning (disable: 4996)

#undef PI

using namespace std;
namespace miEspacio{
    void funcion(int a, int b){
        cout << a+b <<endl;

    }
    float numero =321.123;
}
using namespace miEspacio;
int main()
{
    std::cout<<"Este es un mensaje"<<endl; //sin el espacio (std)
    miEscpacio::funcion(4,9);
    miEspacio::funcion(2,1);
    cout <<miEspacio::numero<<endl;
    return 0;
}
*/