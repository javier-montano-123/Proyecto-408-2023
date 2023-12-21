#include "gtest/gtest.h"
#include "persona.h"
#include "bd.h"
#include "actividades.h"

TEST(Comprobardni,PO1){
    vector<Persona> a;
    Persona p("12345678E");
    a.push_back(p);
    EXPECT_TRUE(p.Comprobardni("12345678E",a));
    EXPECT_FALSE(p.Comprobardni("12378946S",a));
    EXPECT_FALSE(p.Comprobardni("98732165D",a));
}  

TEST(comprobarID,P02){
    vector<Actividades> a1;
    Actividades a(13);
    Actividades a2(23);
    a1.push_back(a);
    a1.push_back(a2);
    EXPECT_FALSE(a.comprobarID(33,&a1));
    EXPECT_TRUE(a.comprobarID(13,&a1));
    EXPECT_TRUE(a.comprobarID(23,&a1));
}



TEST(comprobarAforo,P03){
    Actividades a;
    EXPECT_TRUE(a.comprobarAforo(2));
    EXPECT_TRUE(a.comprobarAforo(5));
    EXPECT_FALSE(a.comprobarAforo(201));
    EXPECT_FALSE(a.comprobarAforo(0));
    EXPECT_FALSE(a.comprobarAforo(-3));
}


TEST(inscribirseActividades,P04){
    BD bd;
    vector<Persona> p;
    vector<Actividades>a;
    Actividades a1(4);
    Actividades a2(3);
    Actividades a3(2);
    Persona p1;
    p1.setDni("12345678C");
    Persona p2;
    p2.setDni("12345678E");
    Persona p3;
    p3.setDni("45781263F");
    a.push_back(a1);
    a.push_back(a2);
    a.push_back(a3);
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    EXPECT_TRUE(bd.inscribirseActividades(4,"12345678C",&a,&p));
    EXPECT_TRUE(bd.inscribirseActividades(3,"12345678E",&a,&p));;
    EXPECT_FALSE(bd.inscribirseActividades(5,"45781263F",&a,&p));
    EXPECT_FALSE(bd.inscribirseActividades(6,"78324915R",&a,&p));
}

TEST(eliminarP,P05){
    vector<Persona>p1;
    BD bd;
    Persona p("12345678B");
    Persona p2("12345678D");
    p1.push_back(p);
    p1.push_back(p2);
    EXPECT_TRUE(bd.eliminarP("12345678B",&p1));
    EXPECT_TRUE(bd.eliminarP("12345678D",&p1));
    EXPECT_FALSE(bd.eliminarP("45632179M",&p1));
    EXPECT_FALSE(bd.eliminarP("87921354L",&p1));

}

TEST(eliminar,P06){
      vector<Actividades>p1;
    BD bd;
    Actividades p(4);
    Actividades p2(5);
    p1.push_back(p);
    p1.push_back(p2);
    EXPECT_TRUE(bd.eliminar(4,&p1));
    EXPECT_TRUE(bd.eliminar(5,&p1));
    EXPECT_FALSE(bd.eliminar(6,&p1));
    EXPECT_FALSE(bd.eliminar(7,&p1));
    EXPECT_FALSE(bd.eliminar(0,&p1));
}


TEST(insertarUsuario,P07){
    vector<Persona> a;
    Persona p("12345678C");
    Persona p2("12345678D");
    a.push_back(p);
    a.push_back(p2);
    EXPECT_TRUE(p.Comprobardni("12345678C",a));
    EXPECT_FALSE(p.Comprobardni("57319426K",a));
    EXPECT_FALSE(p.Comprobardni("24681937J",a));
    EXPECT_TRUE(p.Comprobardni("12345678D",a));
} 




TEST(insertarActividades,P08){
    vector<Actividades> a1;
    Actividades a(4);
    Actividades a2(5);
    a1.push_back(a);
    a1.push_back(a2);
    EXPECT_FALSE(a.comprobarID(1,&a1));
    EXPECT_TRUE(a.comprobarID(4,&a1));
    EXPECT_TRUE(a.comprobarID(5,&a1));
}

