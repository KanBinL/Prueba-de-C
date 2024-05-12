#include <iostream>
using namespace std;

bool validarString(string n){
    if(n == "SI" || n == "NO" || n== "si" || n == "no" || n == "Si" || n =="No"){
        return true;
    }else{
        return false;
    }
}
int main(){
    int numero,n1,n2=0;
    double d1;
    long l1;
    string name1,yes;
    bool state=true;

    cout << "Introduce 1 Int,2 Double,3 Long,4 Boolean,5 String,6 Char" << endl;

    cin >> numero;
    switch(numero){
        
        case 1:
            cout << "Introduce un numero " << endl;
            cin >> n1;
            cout << "El numero escrito es "<< n1;
            break;
        case 2:
            cout << "Introduce un numero con decimales : "<< endl;
            cin >> d1;
            cout << "Numero escrito "<< d1;
            break;
        case 3:
            cout << "Introduce un numero long: "<< endl;
            
            cin >> l1;
            cout << "Numeo escrito : "<< l1;
            break;
        
        case 4:
            cout << "Escribe Si/No "<<endl;
            cin >> yes;
            state = validarString(yes);
            cout << "Valor escrito: " << yes;
            cout << "Valor de la variable "<<state;
            break;
        default:
            cout << "No se ha seleccionado ningun numero anterior";
    }
}


