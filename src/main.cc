#include <string.h>
#include "actividades.h"
#include <iostream>
#include <vector>
#include "bd.h"

using namespace std;

int main()
{
  system("clear");
  string cambiarS; // variables para cambiar datos
  Actividades a1;        // objeto actividades
  vector<Actividades> a;// vector de actividadess
  vector<Persona> p;  // vector de personas
  char fichero[] = "actividades.txt";
  char fichero1[] = "usuarios.txt";
  BD bd;
  bd.nfP(fichero1,&p);
  bd.nfA(fichero,&a); // vuelco el fichero en un vector
  bd.menu(&a,&p);
  bd.backupP(fichero1,p);
  bd.backupA(fichero,a);

}
