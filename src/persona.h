#ifndef PERSONA_H
#define PERSONA_H

#include <string.h>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Persona
{
private:
    string dni_;
    string nombre_;
    string apellidos_;
    int edad_;
    string lugar_;
    string correo_;
    int id_;
    int rol_;
    int preIns_;

public:
    Persona(string dni = "empty", string nombre = "empty", string apellidos = "empty", int edad = 0, string lugar = "empty", string correo = "empty", int id = 0, int rol = 0, int preIns = 0 )
    {
        dni_ = dni;
        nombre_ = nombre;
        apellidos_ = apellidos;
        edad_ = edad;
        lugar_ = lugar;
        correo_ = correo;
        id_ = id;
        rol_ = rol;
        preIns_ = preIns;
    }
    // observadores
    int getRol()
    {
        return rol_;
    }
    int getpreIns()
    {
        return preIns_;
    }
    int getId()
    {
        return id_;
    }
    string getDni()
    {
        return dni_;
    }
    string getNombre()
    {
        return nombre_;
    }
    string getApellidos()
    {
        return apellidos_;
    }
    string getfullName()
    {
        return nombre_ + "  " + apellidos_;
    }
    int getEdad()
    {
        return edad_;
    }
    string getLugar()
    {
        return lugar_;
    }
    string getCorreo()
    {
        return correo_;
    }

    string getFulldata()
    {
        return "dni: " + dni_ + "\n" + "Nombre completo: " + getfullName() + "\n" + "Correo: " + correo_ + "\n" + "Edad: " + to_string(edad_) + "\n" + "Lugar de residencia: " + lugar_ + "\n" + "id Actividad: " + to_string(id_) + "\n\n";
    }

    // modificadores
    void setDni(string dni)
    {
        dni_ = dni;
    }
    void setNombre(string nombre)
    {
        nombre_ = nombre;
    }
    void setApellidos(string apellidos)
    {
        apellidos_ = apellidos;
    }

    void setEdad(int edad)
    {
        edad_ = edad;
    }
    void setLugar(string lugar)
    {

        lugar_ = lugar;
    }
    void setCorreo(string correo)
    {
        correo_ = correo;
    }
    void setId(int id)
    {
        id_ = id;
    }
    void setRol(int rol)
    {
        rol_ = rol;
    }
    void setpreIns(int preIns)
    {
        preIns_ = preIns;
    }
    bool Comprobardni(string dni, vector<Persona> p)
    {
        for (auto it = p.begin(); it != p.end(); it++)
        {
            if (((*it).getDni()) == dni)
            {
                return true;
            }
        }
        return false;
    }
    int ComprobarRol(string dni,vector<Persona>*p)
    {
        for(auto it=(*p).begin();it!=(*p).end();it++)
        {
            if((*it).getDni()==dni)
            {
                return (*it).getRol();
            }
        }
        return 0;
    
    
    }

    bool ComprobarpreIns(string dni, vector<Persona> p)
    {
        for (auto it = p.begin(); it != p.end(); it++)
        {
            if (((*it).getDni()) == dni && (*it).getpreIns() == 2)
            {   
                return true;
            }
        }
        return false;
    }

};

#endif