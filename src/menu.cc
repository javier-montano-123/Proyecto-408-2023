#include "actividades.h"
#include "persona.h"
#include <vector>
#include <string.h>
#include "bd.h"
#define ANSI_COLOR_WHITE "\033[1;37m"
#define ANSI_COLOR_RESET "\x1b[39m"
#define ANSI_COLOR_CYAN "\033[1;36m"



using namespace std;

void BD::menu(vector<Actividades> *actividades, vector<Persona> *persona)
{
  string dni;
  Persona p1;
  int opcion, tecla;
  bool repetir = true;
  do
  {

    cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES\n" ANSI_COLOR_RESET;
    cout << ANSI_COLOR_CYAN "1.LOGIN\n" ANSI_COLOR_RESET;
    cout << ANSI_COLOR_CYAN "2.VISITANTE\n" ANSI_COLOR_RESET;
    cout << ANSI_COLOR_CYAN "0.SALIR\n" ANSI_COLOR_RESET;
    cin >> opcion;
    system("clear");

    switch (opcion)
    {
    case 1:
      cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES---LOGIN\n" ANSI_COLOR_RESET;
      login(persona, actividades);
      cout << ANSI_COLOR_CYAN "0.SALIR\n" ANSI_COLOR_RESET;
      cin >> tecla;
      system("clear");

      break;

    case 2:
      menu_visitante(actividades, persona);
      system("clear");
      break;
    case 0:
      repetir = false;
    default:
      opcion = 0;
      break;
    }
  } while (repetir);
}

void BD::login(vector<Persona> *persona, vector<Actividades> *actividades)
{
  string dni;
  Persona p1;
  cout << "\nIntroduzca su Dni: ";
  cin >> dni;
  int rol;
  if ((p1.Comprobardni(dni, *persona) == false))
  {
    for (int i = 0; i < 99; i++)
    {
      if ((p1.Comprobardni(dni, *persona)) == false)
      {
        cout << "Este DNI no esta registrado, introduzca un Dni registrado. En caso de no estar registrado, contacte con el administrador: \n";
        cin >> dni;
      }
      else
      {
        rol = p1.ComprobarRol(dni, (persona));
      }
    }
  }
else
{
  rol = p1.ComprobarRol(dni, (persona));
}
system("clear");

if (rol == 1)
{
  menu_organizador_de_Actividades(actividades, persona);
}

if (rol == 2)
{
  menu_directorAcademico(actividades, persona);
}

if (rol == 3)
{
  menu_usuarioRegistrado(actividades, persona);
}
/*
if (rol != 1 || 2 || 3)
{
  cout << "ERROR\n";
}*/
}


// MENU ORGANIZADOR

void BD::menu_organizador_de_Actividades(vector<Actividades> *actividades, vector<Persona> *persona)
{
  int tecla;
  int opcion;
  int modificar;
  bool repetir = true;
  do
  {
    cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES---MODO ORGANIZADOR DE ACTIVIDADES\n" ANSI_COLOR_RESET
              << endl;
    cout << ANSI_COLOR_CYAN "1.VER ACTIVIDADES\n" ANSI_COLOR_RESET;
    cout << ANSI_COLOR_CYAN "2.AÑADIR ACTIVIDADES\n" ANSI_COLOR_RESET;
    cout << ANSI_COLOR_CYAN "3.ELIMINAR ACTIVIDADES\n" ANSI_COLOR_RESET;
    cout << ANSI_COLOR_CYAN "4.CONTACTO\n" ANSI_COLOR_RESET;
    cout << ANSI_COLOR_CYAN "0.SALIR\n" ANSI_COLOR_RESET;

    cout << "\nSeleccione una opcion: ";
    cin >> opcion;
    system("clear");

    switch (opcion)
    {
    case 1:
      cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES---MODO ORGANIZADOR DE ACTIVIDADES\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN DE MOSTRAR ACTIVIDADES
      mostrarActividades(actividades);
      cout << ANSI_COLOR_CYAN "O. SALIR\n" ANSI_COLOR_RESET;

      cout << "\nSeleccione una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 2:
      cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES---MODO ORGANIZADOR DE ACTIVIDADES\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN PARA AÑADIR ACTIVIDADES
      insertarActividades(actividades);
      cout << ANSI_COLOR_CYAN "O. SALIR\n" ANSI_COLOR_RESET;

      cout << "\nSeleccione una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 3:
      cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES---MODO ORGANIZADOR DE ACTIVIDADES\n" ANSI_COLOR_RESET
                << endl;
      cout << "Introduzca la id de la actividad que desea eliminar: \n";
      cin >> modificar;
      // FUNCIÓN PARA ELIMINAR ACTIVIDADES
      if (eliminar(modificar, actividades) == true)
      {
        cout << "La actividad ha sido eliminada con éxito\n\n";
      }
      else
      {
        cout << "No se ha podido eliminar la actividad,debido a su inexistencia \n";
      }
      cout << "0. VOLVER AL MENÚ" << endl;
      cout << "\nSeleccione una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 4:
      // FUNCIÓN DE CONTACTO  DEL ADMINISTRADOR
      cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES---MODO CORDINADOR DE ACTIVIDADES\n" ANSI_COLOR_RESET
                << endl;
      cout << "Javier Montaño Ruiz" << endl;
      cout << "i12moruj@uco.es" << endl;
      cout << ANSI_COLOR_CYAN "O. SALIR\n" ANSI_COLOR_RESET;

      cin >> tecla;
      system("clear");
      break;

    case 0:
      repetir = false;
      break;
    }
  } while (repetir);
}


// MENU DEL DIRECTOR ACADÉMICO
void BD::menu_directorAcademico(vector<Actividades> *actividades, vector<Persona> *persona)
{
  int id;
  int tecla;
  int opcion;
  int modificar;
  string modificarp;
  string dni;

  bool repetir = true;
  do
  {
    cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES---MODO DIRECTOR ACADÉMICO\n" ANSI_COLOR_RESET;
    cout << ANSI_COLOR_CYAN "1.VER ACTIVIDADES\n" ANSI_COLOR_RESET;
    cout << ANSI_COLOR_CYAN "2.MODIFICAR DATOS DE LAS ACTIVIDADES\n" ANSI_COLOR_RESET;
    cout << ANSI_COLOR_CYAN "3.AÑADIR USUARIOS\n" ANSI_COLOR_RESET;
    cout << ANSI_COLOR_CYAN "4.MODIFICAR INFORMACION DE USUARIOS\n" ANSI_COLOR_RESET;
    cout << ANSI_COLOR_CYAN "5.VER LOS USUARIOS DE LAS ACTIVIDADES\n" ANSI_COLOR_RESET;
    cout << ANSI_COLOR_CYAN "6.ELIMINAR USUARIOS\n" ANSI_COLOR_RESET;
    cout << ANSI_COLOR_CYAN "7.ACEPTAR PREINSCRIPCIONES DE USUARIOS EN UNA ACTIVIDAD\n" ANSI_COLOR_RESET;



    cout << ANSI_COLOR_CYAN "0.SALIR\n" ANSI_COLOR_RESET;

    cout << "\nSeleccione una opcion: ";
    cin >> opcion;
    system("clear");

    switch (opcion)
    {
    case 1:
      cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES---MODO DIRECTOR ACADÉMICO\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN DE MOSTRAR ACTIVIDADES
      mostrarActividades(actividades);
      cout << ANSI_COLOR_CYAN "O. SALIR\n" ANSI_COLOR_RESET;

      cout << "\nSeleccione una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 2:
      cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES---MODO DIRECTOR ACADÉMICO\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN MODIFICAR ACTIVIDADES
      cout << "Introduzca la id de la actividad que desea modificar: \n";
      cin >> modificar;
      if (modificarActividades(modificar, actividades) == true)
      {
        cout << "La actividad ha sido modificada con éxito\n\n";
      }
      else
      {
        cout << "No se ha podido modificar la actividad,debido a su inexistencia\n";
      }
      cout << "0.VOLVER AL MENÚ" << endl;
      cout << "\nSeleccione una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 3:
      cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES---MODO DIRECTOR ACADÉMICO\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN DE AÑADIR USUARIOS

      insertarUsuario(persona, actividades);
      cout << ANSI_COLOR_CYAN "O. SALIR\n" ANSI_COLOR_RESET;

      cout << "\nSeleccione una opcion: ";
      cin >> tecla;
      system("clear");
      break;
    case 4:
      cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES---MODO DIRECTOR ACADÉMICO\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN DE MODIFICAR USUARIOS
      cout << "Introduzca el DNI del usuario que desea modificar: \n";
      cin >> modificarp;
      modificarUsuario(modificarp, persona, actividades);
      cout << "0.VOLVER AL MENÚ" << endl;
      cout << "\nSeleccione una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 5:
      cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES---MODO DIRECTOR ACADÉMICO\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN DE MOSTRAR USUARIOS
      cout << "Introduzca la id de la actividad que desea ver los usuarios: \n";
      cin >> id;
      mostrarAP(id, actividades,persona);
      cout << ANSI_COLOR_CYAN "O. SALIR\n" ANSI_COLOR_RESET;

      cout << "\nSeleccione una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 6:
      cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES---MODO DIRECTOR ACADÉMICO\n" ANSI_COLOR_RESET
                << endl;
      cout << "Introduzca el DNI del usuario que desea eliminar: \n";
      cin >> modificarp;
      // FUNCIÓN ELIMINAR USUARIOS

      if (eliminarP(modificarp, persona) == true)
      {
        cout << "Ha sido eliminado con éxito\n\n";
      }
      else
      {
        cout << "No se ha podido eliminar el usuario\n";
      }

      cout << "0.VOLVER AL MENÚ" << endl;
      cout << "\nSeleccione una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 7:
      cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES---MODO DIRECTOR ACADÉMICO\n" ANSI_COLOR_RESET
                << endl;
      cout << "Estos son los usuarios preinscritos en las actividades \n";
      mostrarUsuariosPre(persona);

      cout << "Introduzca el dni del usuario preinscrito que desea aceptar \n";
      cin >> dni;
      if(inscribirUsuario(dni, persona,2)==true)
      {
        cout << "El usuario ha sido aceptado con éxito \n";
      }
      

      cout << "0.VOLVER AL MENÚ" << endl;
      cout << "\nSeleccione una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 0:
      repetir = false;
      break;
    }

  } while (repetir);
}

// MENU USUARIO REGISTRADO
void BD::menu_usuarioRegistrado(vector<Actividades> *actividades, vector<Persona> *persona)
{
  int id;
  string dni;
  Persona p1;
  int tecla;
  int opcion;
  bool repetir = true;
  do
  {
    cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES---MODO USUARIO REGISTRADO\n" ANSI_COLOR_RESET
              << endl;
    cout << ANSI_COLOR_CYAN "1.VER ACTIVIDADES\n" ANSI_COLOR_RESET;
    cout << ANSI_COLOR_CYAN "2.INSCRIPCION EN ACTIVIDADES\n" ANSI_COLOR_RESET;
    cout << ANSI_COLOR_CYAN "3.VER LAS ACTIVIDADES EN LAS QUE ESTOY INSCRITO\n" ANSI_COLOR_RESET;
    cout << ANSI_COLOR_CYAN "4.CONTACTO\n" ANSI_COLOR_RESET;
    cout << ANSI_COLOR_CYAN "0.SALIR\n" ANSI_COLOR_RESET;

    cout << "\nSeleccione una opcion: ";
    cin >> opcion;
    system("clear");

    switch (opcion)
    {
    case 1:
      cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES---MODO USUARIO REGISTRADO\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN DE MOSTRAR ACTIVIDADES
      mostrarActividades(actividades);                                                        
      cout << ANSI_COLOR_CYAN "O. SALIR\n" ANSI_COLOR_RESET;

      cout << "\nSeleccione una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 2:
      cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES---MODO USUARIO REGISTRADO\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN INSCRIPCIÓN EN ACTIVIDADES
      cout << "Introduzca su DNI:\n";
      cin >> dni;
      cout << "Introduzca la id de la actividad en la que desea inscribirse\n ";
      cin >> id;
      if(p1.Comprobardni(dni, *persona)== true && p1.ComprobarpreIns(dni, *persona) == false)
      {
        inscribirUsuario(dni,persona,2);
        
        cout << "Ha sido preinscrito con éxito. \n";

      }

      else
      {
      if (inscribirseActividades(id, dni, actividades, persona) == true)
      {
        cout << "Ha sido inscrito con éxito\n\n";
      }
      else
      {
        cout << "No se ha podido inscribir en la actividad\n";
      }
      }
      cout << "0.VOLVER AL MENÚ" << endl;
      cout << "\nSeleccione una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 3:
      cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES---MODO USUARIO REGISTRADO\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN PARA VER LAS ACTIVIDADES EN LAS QUE ESTÁ INSCRITO
      cout << "Introduzca su DNI: \n";
      cin >> dni;
      mostrarAaP(dni, actividades, persona);
      cout << ANSI_COLOR_CYAN "O. SALIR\n" ANSI_COLOR_RESET;

      cout << "\nSeleccione una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 4:
      // FUNCIÓN CONTACTO DIRECTOR ACADÉMICO
      cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES---MODO USUARIO REGISTRADO\n" ANSI_COLOR_RESET
                << endl;
      cout << "Javier Montaño Ruiz" << endl;
      cout << "i12moruj@uco.es" << endl;
      cout << ANSI_COLOR_CYAN "O. SALIR\n" ANSI_COLOR_RESET;

      cin >> tecla;
      system("clear");
      break;

    case 0:
      repetir = false;
      break;
    }

  } while (repetir);
}

// MENU VISITANTE
void BD::menu_visitante(vector<Actividades> *actividades, vector<Persona> *persona)
{
  int tecla;
  int opcion;
  bool repetir = true;
  do
  {
    cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES---MODO VISITANTE\n" ANSI_COLOR_RESET
              << endl;
    cout << ANSI_COLOR_CYAN "1.VER ACTIVIDADES\n" ANSI_COLOR_RESET;
    cout << ANSI_COLOR_CYAN "2.CONTACTO\n" ANSI_COLOR_RESET;
    cout << ANSI_COLOR_CYAN "0.SALIR\n" ANSI_COLOR_RESET;

    cout << "\nSeleccione una opcion: ";
    cin >> opcion;
    system("clear");

    switch (opcion)
    {
    case 1:
      cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES---MODO VISITANTE\n" ANSI_COLOR_RESET
                << endl;
      // FUNCIÓN DE MOSTRAR ACTIVIDADES
      mostrarActividades(actividades);
      cout << ANSI_COLOR_CYAN "O. SALIR\n" ANSI_COLOR_RESET;

      cout << "\nSeleccione una opcion: ";
      cin >> tecla;
      system("clear");
      break;

    case 2:
      // FUNCIÓN DE CONTACTO DE DIRECTOR ACADÉMICO
      cout << ANSI_COLOR_WHITE "UCO ACTIVIDADES---MODO VISITANTE\n" ANSI_COLOR_RESET
                << endl;
      cout << "Javier Montaño Ruiz" << endl;
      cout << "i12moruj@uco.es" << endl;
      cout << ANSI_COLOR_CYAN "O. SALIR\n" ANSI_COLOR_RESET;

      cin >> tecla;
      system("clear");
      break;

    case 0:
      repetir = false;
      break;
    }

  } while (repetir);
}
