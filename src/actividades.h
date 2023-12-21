#ifndef ACTIVIDADES_H
#define ACTIVIDADES_H
#include <string.h>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Actividades
{
private:
    int id_; 
    string nombre_;
    string directorAcademico_;
    string organizador_;
    string fechainicio_;
    string descripcion_;
    int aforo_;
    double precio_;
    
    
    

public:
    Actividades(int id = 0, string nombre = "EMPTY",string directorAcademico = "EMPTY", string organizador = "EMPTY", string fechainicio = "EMPTY", string descripcion = "EMPTY", int aforo = 0, double precio = 0.0)
    {
        id_ = id;
        nombre_ = nombre;
        directorAcademico_=directorAcademico;
        organizador_ = organizador;
        fechainicio_ = fechainicio;
        descripcion_ = descripcion;
        aforo_ = aforo;
        precio_ = precio;
        
    }

    // Observadores
    
    int getAforo()
    {
        return aforo_;
    }
    int getId()
    {
        return id_;
    }
    string getNombre()
    {
        return nombre_;
    }
    string getDirectorAcademico()
    {
        return directorAcademico_;
    }
    string getOrganizador()
    {
        return organizador_;
    }
    string getFechainicio()
    {
        return fechainicio_;
    }
    string getDescripcion()
    {
        return descripcion_;
    }
    double get_precio()
    {
        return precio_;
    }
    

    string getData()
    {
        return "id: " + to_string(id_) + "\n" +
               "Nombre: " + nombre_ + "\n" + "Director Académico: " + directorAcademico_ + " \n" + "Organizador: " + organizador_ + " \n" + "Fecha inicio: " + fechainicio_ + "\n" + "Descripcion: " + descripcion_ + "\n" + "Aforo: " + to_string(aforo_) + "\n" + "Precio: " + to_string(precio_) + "\n\n";
    }

    // Modificadores

    void setAforo(int aforo)
    {
        aforo_ = aforo;
    }
    void setId(int id)
    {

        id_ = id;
    }
    void setNombre(string nombre)
    {
        nombre_ = nombre;
    }
    void setFechainicio(string fechainicio)
    {
        fechainicio_ = fechainicio;
    }

    void setDescripcion(string descripcion)
    {
        descripcion_ = descripcion;
    }
    void setPrecio(double precio)
    {
        precio_ = precio;
    }
    void setDirectorAcademico(string directorAcademico)
    {
        directorAcademico_ = directorAcademico;
    }
    void setOrganizador(string organizador)
    {
        organizador_ = organizador;
    }
    
    bool comprobarAforo(int aforo)
    {
        if (aforo <= 0 || aforo > 200)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    bool comprobarID(int id, vector<Actividades> *actividades)
    {
        for (auto it = (*actividades).begin(); it != (*actividades).end(); it++)
        {
            if ((*it).getId() == id || id==0)
            {
                return true;
            }
        }

        return false;
    }
};

#endif