#include <iostream>
#ifdef __MINGW32__
#define LIMPIAR "CLS"
#endif // __MINGW32__
#include <stdio.h>
#include "./sysinfo.hpp"
using namespace std;

int main() {
  sysinfo s_i = get_sysinfo();
  cout << "Nombre del SO: " << s_i.os << std::endl;
  cout << "Nombre del procesador: "<< s_i.cpu << std::endl;
  cout << "Cantidad de RAM: "<< s_i.ram << std::endl;
  system("systeminfo");
  cout << "Datos del pc con comando en powershell: "<< endl;
}
