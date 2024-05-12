#include <fstream>
#include <iostream>
#ifdef __MINGW32__
#define LIMPIAR "CLS"
#endif // __MINGW32__
#include <stdio.h>
#include "./sysinfo.hpp"
#include <iterator>
#include <list>
#include<cstdlib>
#include <ctime>
#include <stdlib.h>
#include <limits.h>
#include <winsock2.h>
#include <windows.h>
#include <windows.h>
#include <lmcons.h>
using namespace std;


list<string> getPCInfo() {
  list<string> datos;
  sysinfo s_i = get_sysinfo();
  datos.push_back(s_i.os);
  datos.push_back(s_i.cpu);
  datos.push_back(s_i.ram);
  return datos;
}

 
void verDatosLista(list<std::string> const &list){
    for (string i: list) {
        cout << i << endl;
    }
}

string mostrarFecha(){
    struct tm myt;
    myt.tm_sec = 1;   myt.tm_min = 30; myt.tm_hour = 9;
    myt.tm_mday = 22; myt.tm_mon = 11; myt.tm_year = 56;
    myt.tm_wday = 4;  myt.tm_yday = 0; myt.tm_isdst = 0;
    char* cTim = asctime(&myt);
    string fecha = cTim;
    return fecha;
}

void getUsername(){
    TCHAR* username[UNLEN+1];
    DWORD username_len=UNLEN+1;
    GetUserName((TCHAR*)username,&username_len);
    wcout << username << endl;
}


void mostrarHostname(){
   
}

void guardarDatosLista(list<string> const &list){

    string nombreArchivo = "datos.txt";
    ofstream archivo;
	// Abrimos el archivo
	archivo.open(nombreArchivo.c_str(), fstream::out);
	// Y le escribimos redirigiendo
    for(string i : list){
        archivo << i << endl;
    }
    // Finalmente lo cerramos
    archivo.close();
}

void showPcInfo(list<string> lista){
    list<string>::iterator pos;
    pos = lista.begin();
    while( pos != lista.end()){
        cout << *pos << endl;
        pos++;
    }
}

void escribirEnFichero(){
    //Array de caracteres que inicializamos el fichero
    char data[100];
    string nombre;
   // open a file in write mode.
   ofstream outfile;
   ifstream in;
   in.open("datos.txt");
   outfile.open("datos.txt");

   cout << "Writing to the file" << endl;
   showPcInfo(getPCInfo());
   //cin >> nombre;
   string linea="";
   while(getline(in,linea)){
    outfile << linea << endl;
   }

   // write inputted data into the file.
   outfile << data << endl;

   // close the opened file.
   outfile.close();
}

void leerFichero(){
    //Array de caracteres que inicializamos el fichero
    char data[100];
// open a file in read mode.
   ifstream infile; 
   infile.open("datos.txt"); 
 
   cout << "Reading from the file" << endl; 
   infile >> data; 

   // write the data at the screen.
   cout << data << endl;
   
   // again read the data from the file and display it.
   infile >> data; 
   cout << data << endl; 

   // close the opened file.
   infile.close();
}



int main(){

    cout << "Escribiendo en fichero ... "<< endl;
    escribirEnFichero();
    cout << " Leyendo fichero ..." << endl;
    leerFichero();



   list<string> lista = getPCInfo();
   verDatosLista(lista);
   guardarDatosLista(lista);



    TCHAR compname[UNCLEN+1];   
    DWORD compname_len = UNCLEN+1;

    GetComputerName((TCHAR*)compname,&compname_len);

    wcout<<compname<<endl;

    cin.get();
    
    return 0;
}

