#ifndef BD_H
#define BD_H

#include "actividades.h"
#include "persona.h"
#include <vector>
#include <fstream>
#include <string.h>

using namespace std;
// Clase para volcar los vectores de registros de actividadess en un vector
class BD
{
private:
public:
    void nfA(char *nombreFichero, vector<Actividades> *actividades);
    void nfP(char *nombreFichero, vector<Persona> *persona);
    void mostrarUsuarios(vector<Persona> *personas);
    void mostrarActividades(vector<Actividades> *actividades);
    bool modificarActividades(int modificar, vector<Actividades> *actividades);
    bool modificarR(int modificar, vector<Actividades> *actividades);
    bool eliminar(int modificar, vector<Actividades> *actividades);
    bool insertarActividades(vector<Actividades> *actividades);
    void insertarUsuario(vector<Persona> *personas, vector<Actividades> *actividades);
    bool inscribirseActividades(int id, string Dni, vector<Actividades> *actividades, vector<Persona> *personas);
    void mostrarAaP(string Dni, vector<Actividades> *actividades, vector<Persona> *personas);
    void mostrarAP(int id, vector<Actividades> *actividades, vector<Persona> *personas);
    void backupA(char *nombreFichero, vector<Actividades> actividades);
    void backupP(char *nombreFichero, vector<Persona> personas);
    void menu(vector<Actividades> *actividades, vector<Persona> *persona);
    void menu_organizador_de_Actividades(vector<Actividades> *actividades, vector<Persona> *persona);
    void menu_directorAcademico(vector<Actividades> *actividades, vector<Persona> *persona);
    void menu_visitante(vector<Actividades> *actividades, vector<Persona> *persona);
    void menu_usuarioRegistrado(vector<Actividades> *actividades, vector<Persona> *persona);
    void modificarUsuario(string modificarp, vector<Persona> *personas, vector<Actividades> *actividades);
    bool eliminarP(string modificarp, vector<Persona> *personas);
    void login(vector<Persona> *persona,vector<Actividades>*actividades);
    void mostrarUsuariosPre(vector<Persona> *personas);
bool inscribirUsuario(string dni, vector<Persona> *personas,int n);
    




     
};

#endif
