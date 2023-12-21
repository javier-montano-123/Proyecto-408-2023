#include "actividades.h"
#include "persona.h"
#include <vector>
#include <string.h>
#include "bd.h"


void BD::nfA(char *nombreFichero, vector<Actividades> *actividades)
{

    (*actividades).clear();
    ifstream f(nombreFichero);
    if (!f.is_open())
    {
        cout << "Error, no se puede establecer conexión con la base de datos." << endl;
        exit(-1);
    }

    string datoLeido;
    int id, aforo;
    string nombre, directorAcademico, organizador, fechainicio, descripcion;
    double precio;
    while (getline(f, datoLeido, ';'))
    {
        id = atoi(datoLeido.c_str());        
        getline(f, datoLeido, ';');
        nombre = datoLeido;
        getline(f, datoLeido, ';');
        directorAcademico = datoLeido;
        getline(f, datoLeido, ';');
        organizador = datoLeido;
        getline(f, datoLeido, ';');
        fechainicio = datoLeido;
        getline(f, datoLeido, ';');
        descripcion = datoLeido;
        getline(f, datoLeido, ';');
        aforo = atoi(datoLeido.c_str());
        getline(f, datoLeido, '\n');
        precio = atof(datoLeido.c_str());
       

        Actividades aux(id, nombre, directorAcademico, organizador, fechainicio, descripcion, aforo, precio);

        (*actividades).push_back(aux);
    }

    f.close();
}

void BD::nfP(char *nombreFichero, vector<Persona> *persona)
{

    (*persona).clear();
    ifstream f(nombreFichero);
    if (!f.is_open())
    {
        cout << "Error, no se puede establecer conexión con la base de datos." << endl;
        exit(-1);
    }

    string datoLeido;
    int id, edad, rol, preIns;
    string nombre, apellidos, correo, lugar, dni;
    while (getline(f, datoLeido, ';'))
    {
        dni = datoLeido;
        getline(f, datoLeido, ';');
        nombre = datoLeido;
        getline(f, datoLeido, ';');
        apellidos = datoLeido;
        getline(f, datoLeido, ';');
        edad = atoi(datoLeido.c_str());
        getline(f, datoLeido, ';');
        lugar = datoLeido;
        getline(f, datoLeido, ';');
        correo = datoLeido;
        getline(f, datoLeido, ';');
        id = atoi(datoLeido.c_str());
        getline(f, datoLeido, ';');
        rol = atoi(datoLeido.c_str());
        getline(f, datoLeido, '\n');
        preIns= atoi(datoLeido.c_str());
       

        Persona aux(dni, nombre, apellidos, edad, lugar, correo, id, rol, preIns);

        (*persona).push_back(aux);
    }

    f.close();
}
void BD::mostrarUsuarios(vector<Persona> *personas)
{
    for (auto it = (*personas).begin(); it != (*personas).end(); it++)
    {
        cout << it->getFulldata();
    }
}
void BD::mostrarUsuariosPre(vector<Persona> *personas)
{
    for (auto it = (*personas).begin(); it != (*personas).end(); it++)
    {
        if(it->getpreIns()==2)
        {
        cout << "Usuario preinscrito encontrado: " << it->getDni() << endl;
        }
    }
}
bool BD::inscribirUsuario(string dni, vector<Persona> *personas,int n)
{
    for (auto it = (*personas).begin(); it != (*personas).end(); it++)
    {
        
        if(it->getDni() == dni)
        {
            it->setpreIns(n);
            return true;
        }
    } 
    return false;
}


void BD::mostrarActividades(vector<Actividades> *actividades)
{
    for (auto it = (*actividades).begin(); it != (*actividades).end(); it++)
    {
        cout << it->getData();
    }
}
// Funcion para modificar los actividades
bool BD::modificarActividades(int modificar, vector<Actividades> *actividades)
{
    int repetir;
    int op;
    int cambiarI;
    string cambiarS;
    Actividades a1;
    for (auto it = (*actividades).begin(); it != (*actividades).end(); it++)
    {
        if (((*it).getId()) == modificar)
        {
            do
            {
                cout << "Seleecione el parámetro que desee modificar: \n\n";
                cout << "1.Nombre\n";
                cout << "2.Fecha de inicio\n";
                cout << "3.Descripcion\n";
                cout << "4.Aforo\n";
                cout << "5.Precio\n";
                cout << "6.Salir\n";
                cin >> op;
                system("clear");
                switch (op)
                {
                case 1:
                    cout << "Introduzca el nuevo nombre para la actividad: ";
                    cin >> cambiarS;
                    (*it).setNombre(cambiarS);
                    system("clear");
                    break;
                case 2:
                    cout << "Introduzca la nueva fecha de inicio de la actividad: \n";
                    cin >> cambiarS;
                    (*it).setFechainicio(cambiarS);
                    system("clear");
                    break;
                case 3:
                    cout << "Introduzca la nueva descripción de la actividad: ";
                    cin.ignore();
                    getline(cin, cambiarS);
                    (*it).setDescripcion(cambiarS);
                    system("clear");
                    break; 
                case 4:
                    cout << "Introduzca el nuevo aforo de la actividad: ";
                    cin >> cambiarI;
                    if (a1.comprobarAforo(cambiarI) == false)
                    {
                        for (int i = 0; i < 99; i++)
                        {
                            if (a1.comprobarAforo(cambiarI) == false)
                            {
                                cout << "Error no se puede introducir un aforo mayor de 200" << endl;
                            }
                        }
                    }
                    else
                    {
                        (*it).setAforo(cambiarI);
                    }
                    system("clear");
                    break;   
                case 5:
                    cout << "Introduzca el nuevo precio de la actividad: ";
                    cin >> cambiarI;
                    (*it).setPrecio(cambiarI);
                    system("clear");
                    break;              
                        
                case 6:
                    repetir = false;
                    break;
                }
            } while (repetir);
            return true;
        }
    }
    return false;
}

bool BD::modificarR(int modificar, vector<Actividades> *actividades)
{
    int repetir;
    int op;
    int cambiarI;
    string cambiarS;
    Actividades a1;
    for (auto it = (*actividades).begin(); it != (*actividades).end(); it++)
    {
        if (((*it).getId()) == modificar)
        {
            do
            {
                cout << "Introduzca el número correspondiente al parámetro que desee modificar: \n\n";
                cout << "1.Aforo\n";
                cout << "2.Salir\n";
                cin >> op;
                system("clear");
                switch (op)
                {
              
                case 1:
                    cout << "Introduzca el nuevo aforo: ";
                    cin >> cambiarI;
                    if (a1.comprobarAforo(cambiarI) == false)
                    {
                        for (int i = 0; i < 99; i++)
                        {
                            if (a1.comprobarAforo(cambiarI) == false)
                            {
                                cout << "error no se puede introducir un aforo mayor de 200" << endl;
                            }
                        }
                    }
                    else
                    {
                        (*it).setAforo(cambiarI);
                    }
                    system("clear");
                    break;

                case 2:
                    repetir = false;
                    break;
                }

            } while (repetir);
            return true;
        }
    }
    return false;
}
// Funcion para eliminar un registro
bool BD::eliminar(int modificar, vector<Actividades> *actividades)
{
    if (modificar == 0)
    {
        return false;
    }
    for (auto it = ((*actividades).begin()); it != ((*actividades).end()); it++)
    {
        if (((*it).getId()) == modificar)
        {
            (*actividades).erase(it);
            return true;
        }
    }
    return false;
}
// Función para insertar un actividad
bool BD::insertarActividades(vector<Actividades> *actividades)
{
    int id, aforo;
    double precio;
    string nombre, descripcion, directorAcademico, organizador, fechainicio;
    Actividades a1;
    cout << "Introduzca la id de la nueva actividad: \n";
    cin >> id;
    if (a1.comprobarID(id, actividades) == true)
    {
        for (int i = 0; i < 99; i++)
        {
            if (a1.comprobarID(id, actividades) == true)
            {
                cout << "Error esa id no esta disponible,introduzca id una correcta" << endl;
                cin >> id;
            }
            else
            {
                a1.setId(id);
            }
        }
    }
    else
    {
        a1.setId(id);
    }

    cout << "Introduzca el precio de la nueva actividad: \n";
    cin >> precio;
    a1.setPrecio(precio);
    cout << "Introduzca el nombre de la nueva actividad: \n";
    cin.ignore();
    getline(cin, nombre);
    a1.setNombre(nombre);
    cout << "Introduzca la fecha de inicio de la nueva actividad(DD/MM/AA): \n";
    cin >> fechainicio;
    a1.setFechainicio(fechainicio);
    cout << "Introduzca la descripción de la nueva actividad: \n";
    cin.ignore();
    getline(cin, descripcion);
    a1.setDescripcion(descripcion);
    cout << "Introduzca el director académico  de la nueva actividad: \n";
    getline(cin, directorAcademico);
    a1.setDirectorAcademico(directorAcademico);
    cout << "Introduzca el organizador de la nueva actividad: \n";
    getline(cin, organizador);
    a1.setOrganizador(organizador);
    cout << "Introduzca el aforo de la nueva actividad: \n";
    cin >> aforo;
    if ((a1.comprobarAforo(aforo)) == false)
    {
        for (int i = 0; i < 99; i++)
        {
            if ((a1.comprobarAforo(aforo)) == false)
            {
                cout << "Error, se debe fijar un aforo mayor que 0 y menor o igual que 200. Introduzca de nuevo un aforo correcto\n";
                cin >> aforo;
            }
            else
            {
                a1.setAforo(aforo);
            }
        }
    }
    else
    {
        a1.setAforo(aforo);
    }

    cout << "La actividad ha sido añadida con éxito\n";
    (*actividades).push_back(a1);
    return true;
}

void BD::insertarUsuario(vector<Persona> *personas, vector<Actividades> *actividades)
{
    int id, edad, rol;
    string nombre, apellidos, correo, lugar, dni;
    Persona p1;
    Actividades a1;
    cout << "Introduzca el DNI del nuevo usuario: \n ";
    cin >> dni;
    if ((p1.Comprobardni(dni, (*personas))) == true)
    {
        for (int i = 0; i < 99; i++)
        {
            if ((p1.Comprobardni(dni, (*personas))) == true)
            {
                cout << "Error, este DNI pertenece a otra persona. Introduzca de nuevo su DNI: \n";
                cin >> dni;
            }
        }
    }
    else
    {
        p1.setDni(dni);
    }

    cout << "Introduzca el nombre del nuevo usuario: \n";
    cin.ignore();
    getline(cin, nombre);
    p1.setNombre(nombre);
    cout << "Introduzca los apellidos del nuevo usuario: \n";
    getline(cin, apellidos);
    p1.setApellidos(apellidos);
    cout << "Introduzca el correo del nuevo usuario: \n";
    cin >> correo;
    p1.setCorreo(correo);
    cout << "Introduzca el lugar de residencia del nuevo usuario: \n";
    cin.ignore();
    getline(cin, lugar);
    p1.setLugar(lugar);
    cout << "Introduzca la edad del nuevo usuario: \n";
    cin >> edad;
    p1.setEdad(edad);
    cout << "Introduzca la id de la actividad a la que pertenece el usuario. Si no pertenece a ninguna, introduzca un 0: \n";
    cin >> id;
    cout << "Introduzca el rol del nuevo usuario:\n1: Organizador\n2: Director academico\n3: Usuario registrado\n";
    cin >> rol;
    p1.setRol(rol);
    if (a1.comprobarID(id, actividades) == false)
    {
        for (int i = 0; i < 99; i++)
        {
            if (a1.comprobarID(id, actividades) == false)
            {
                cout << "Error esa id no esta disponible, introduzca de nuevo una id correcta" << endl;
                cin >> id;
            }
        }
    }
    else
    {
        p1.setId(id);
    }

    cout << "El usuario ha sido añadido con éxito\n";
    (*personas).push_back(p1);
}

bool BD::inscribirseActividades(int id, string dni, vector<Actividades> *actividades, vector<Persona> *personas)
{
    for (auto it = (*actividades).begin(); it != (*actividades).end(); it++)
    {

        if (((*it).getId()) == id)
        {
            for (auto it2 = (*personas).begin(); it2 != (*personas).end(); it2++)
            {
                if (((*it2).getDni()) == dni)
                {
                    (*it2).setId(id);
                    return true;
                }
            }
        }
    }
    return false;
}  

void BD::mostrarAaP(string dni, vector<Actividades> *actividades, vector<Persona> *personas)
{
    bool inscrito = false; // Variable para verificar si está inscrito en alguna actividad
    
    for (auto it = (*actividades).begin(); it != (*actividades).end(); it++)
    {
        for (auto it2 = (*personas).begin(); it2 != (*personas).end(); it2++)
        {
            if (((*it).getId()) == ((*it2).getId()) && ((*it2).getDni()) == dni)
            {
                cout << "Usted está inscrito en la actividad " << (*it).getNombre() << endl;
                inscrito = true; // La persona está inscrita en alguna actividad
                break; // Salir del bucle interno
            }
        }
        
        if (inscrito) {
            break; // Salir del bucle externo si la persona está inscrita
        }
    }
    
    if (!inscrito) {
        cout << "Usted no está inscrito en ninguna actividad " << endl;
    }
}


void BD::mostrarAP(int id, vector<Actividades> *actividades, vector<Persona> *personas)
{
    for (auto it = (*actividades).begin(); it != (*actividades).end(); it++)
    {
        for (auto it2 = (*personas).begin(); it2 != (*personas).end(); it2++)
        {
            if (((*it).getId()) == ((*it2).getId()) && ((*it2).getId()) == id)
            {
                cout << (*it2).getFulldata();
            }
        }
    }
}

void BD::backupA(char *nombreFichero, vector<Actividades> actividades)
{
    ofstream f(nombreFichero);
    if (!f.is_open())
    {
        cout << "Error, no se puede establecer conexión con la base de datos." << endl;
        exit(-1);
    }

    for (auto it = actividades.begin(); it != actividades.end(); it++)
    {
        f << it->getId() << ";" << it->getNombre() << ";" << it->getDirectorAcademico() << ";" << it->getOrganizador() << ";" << it->getFechainicio() << ";" << it->getDescripcion() << ";" << it->getAforo() << ";" << it->get_precio() << "\n";
    }

    f.close();
}

void BD::backupP(char *nombreFichero, vector<Persona> personas)
{
    ofstream f(nombreFichero);
    if (!f.is_open())
    {
        cout << "Error, no se puede establecer conexión con la base de datos." << endl;
        exit(-1);
    }

    for (auto it = personas.begin(); it != personas.end(); it++)

    {
        f << it->getDni() << ";" << it->getNombre() << ";" << it->getApellidos() << ";" << it->getEdad() << ";" << it->getLugar() << ";" << it->getCorreo() << ";" << it->getId() << ";" << it->getRol() << ";" << it->getpreIns() << "\n";
    }

    f.close();
}

void BD::modificarUsuario(string modificarp, vector<Persona> *personas, vector<Actividades> *actividades)
{
    int repetir;
    int op;
    int cambiarI;
    string cambiarS;
    Actividades a1;
    Persona p1;
    for (auto it = (*personas).begin(); it != (*personas).end(); it++)
    {
        if (((*it).getDni()) == modificarp)
        {
            do
            {
                cout << "Seleccione el parámetro que desee modificar: \n\n";
                cout << "1.Nombre\n";
                cout << "2.Apellidos\n";
                cout << "3.Correo\n";
                cout << "4.Edad\n";
                cout << "5.Lugar de Residencia\n";
                cout << "6.Id de la actividad a la que pertenece\n";
                cout << "7.Salir\n";
                cin >> op;
                system("clear");
                switch (op)
                {
                case 1:
                    cout << "Introduzca el nuevo nombre: \n";
                    cin.ignore();
                    getline(cin, cambiarS);
                    (*it).setNombre(cambiarS);
                    system("clear");
                    break;
                case 2:
                    cout << "Introduzca los nuevos apellidos: ";
                    cin.ignore();
                    getline(cin, cambiarS);
                    (*it).setApellidos(cambiarS);
                    system("clear");
                    break;
                case 3:
                    cout << "Introduzca el nuevo correo: ";
                    cin >> cambiarS;
                    (*it).setCorreo(cambiarS);
                    system("clear");
                    break;
                case 4:
                    cout << "Introduzca la nueva edad: ";
                    cin >> cambiarI;
                    (*it).setEdad(cambiarI);
                    system("clear");
                    break;
                case 5:
                    cout << "Introduzca el nuevo lugar de residencia: ";
                    cin.ignore();
                    getline(cin, cambiarS);
                    (*it).setLugar(cambiarS);
                    system("clear");
                    break;              
                case 6:
                    cout << "Introduzca la id de la actividad a la que pertenece: ";
                    cin >> cambiarI;
                    if (a1.comprobarID(cambiarI, actividades) == false)
                    {
                        for (int i = 0; i < 99; i++)
                        {
                            if (a1.comprobarID(cambiarI, actividades) == false)
                            {
                                cout << "Error esa id no existe, introduzca de nuevo una id disponible" << endl;
                                cin >> cambiarI;
                            }
                        }
                    }
                    else
                    {
                        (*it).setId(cambiarI);
                    }
                    system("clear");
                    break;

                case 7:
                    repetir = false;
                    break;
                }
            } while (repetir);
        }
    }
}

bool BD::eliminarP(string modificarp, vector<Persona> *personas)
{
    for (auto it = (*personas).begin(); it != (*personas).end(); it++)
    {
        if (((*it).getDni()) == modificarp)
        {
            (*personas).erase(it);
            return true;
        }
    }
    return false;
}



