#include <iostream>
#include <fstream>
using namespace std;

/**
 * Pido el nombre y lo guardo en un fichero
*/

void escribirEnFichero(){
    //Array de caracteres que inicializamos el fichero
    char data[100];
    string nombre;
   // open a file in write mode.
   ofstream outfile;
   outfile.open("datos.txt");

   cout << "Writing to the file" << endl;
   cout << "Enter your name: "; 
   //cin >> nombre;
    cin.getline(data,100);

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
    return 0;
}