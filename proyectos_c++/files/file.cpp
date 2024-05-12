#include <iostream>
#include <fstream>
#include <direct.h>
#include <string>
using namespace std;

void crearDirectorioOrFichero(){

    cout << "Opciones : " << endl << "1 crear directorio,2 crear Archivo,3 Salir ";
    string opcion;
    getline(cin,opcion);
    if(opcion == "1"){
        cout << "Ruta : ";
        string ruta;
        getline(cin,ruta);
        cout << "Nombre de la carpeta: ";
        string carpeta;
        getline(cin,carpeta);
        string ruta_absoluta = ruta + carpeta;
        if(mkdir(ruta_absoluta.c_str()) == 0){
            cout << "Carpeta creada correctamente";
        }else{
            cout << "Error al crear la carpeta";
        }
        crearDirectorioOrFichero();
    }else if(opcion == "2"){
        cout << "Ruta : ";
        string ruta;
        getline(cin,ruta);
        cout << "Nombre del archivo : ";
        string archivo;
        getline(cin,archivo);
        string ruta_absoluta = ruta + archivo;
        FILE * arch;
        if(arch = fopen(ruta_absoluta.c_str(),"a")){
            cout << "Archivo creado correctamente"<< endl;
        }else{
            cout << "Fallo al crear el archivo" << endl;
        }
        crearDirectorioOrFichero();
    }else if(opcion=="3"){
        exit;
    }

}

int main(int argc,char *argv[]) {
    crearDirectorioOrFichero();
    system("PAUSE");//Mantiene la consola en modo de pausa
}