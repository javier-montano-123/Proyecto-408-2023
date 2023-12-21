#include "gtest/gtest.h"
#include "persona.h"
#include "bd.h"
#include "actividades.h"

TEST(Comprobardni,PO1){
    vector<Persona> a;
    Persona p("12345678D");
    a.push_back(p);
    EXPECT_TRUE(p.Comprobardni("12345678D",a));
    EXPECT_FALSE(p.Comprobardni("45678939O",a));
    EXPECT_FALSE(p.Comprobardni("89671238L",a));
}  

TEST(comprobarID,P02){
    vector<Actividades> a1;
    Actividades a(6);
    Actividades a2(7);
    a1.push_back(a);
    a1.push_back(a2);
    EXPECT_FALSE(a.comprobarID(8,&a1));
    EXPECT_TRUE(a.comprobarID(6,&a1));
    EXPECT_TRUE(a.comprobarID(7,&a1));
}



TEST(comprobarAforo,P03){
    Actividades a;
    EXPECT_TRUE(a.comprobarAforo(13));
    EXPECT_TRUE(a.comprobarAforo(14));
    EXPECT_FALSE(a.comprobarAforo(201));
    EXPECT_FALSE(a.comprobarAforo(0));
    EXPECT_FALSE(a.comprobarAforo(-3));
}


TEST(inscribirseActividades,P04){
    BD bd;
    vector<Persona> p;
    vector<Actividades>a;
    Actividades a1(8);
    Actividades a2(9);
    Actividades a3(5);
    Persona p1;
    p1.setDni("12345678B");
    Persona p2;
    p2.setDni("12345678C");
    Persona p3;
    p3.setDni("45781268O");
    a.push_back(a1);
    a.push_back(a2);
    a.push_back(a3);
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    EXPECT_TRUE(bd.inscribirseActividades(8,"12345678B",&a,&p));
    EXPECT_TRUE(bd.inscribirseActividades(9,"12345678C",&a,&p));;
    EXPECT_FALSE(bd.inscribirseActividades(25,"45781268O",&a,&p));
    EXPECT_FALSE(bd.inscribirseActividades(30,"78324911R",&a,&p));
}

TEST(eliminarP,P05){
    vector<Persona>p1;
    BD bd;
    Persona p("12345678D");
    Persona p2("12345678E");
    p1.push_back(p);
    p1.push_back(p2);
    EXPECT_TRUE(bd.eliminarP("12345678D",&p1));
    EXPECT_TRUE(bd.eliminarP("12345678E",&p1));
    EXPECT_FALSE(bd.eliminarP("19283764M",&p1));
    EXPECT_FALSE(bd.eliminarP("37281946S",&p1));

}

TEST(eliminar,P06){
      vector<Actividades>p1;
    BD bd;
    Actividades p(1);
    Actividades p2(2);
    p1.push_back(p);
    p1.push_back(p2);
    EXPECT_TRUE(bd.eliminar(1,&p1));
    EXPECT_TRUE(bd.eliminar(2,&p1));
    EXPECT_FALSE(bd.eliminar(3,&p1));
    EXPECT_FALSE(bd.eliminar(4,&p1));
    EXPECT_FALSE(bd.eliminar(0,&p1));
}


TEST(insertarUsuario,P07){
    vector<Persona> a;
    Persona p("12345678D");
    Persona p2("12345678E");
    a.push_back(p);
    a.push_back(p2);
    EXPECT_TRUE(p.Comprobardni("12345678D",a));
    EXPECT_FALSE(p.Comprobardni("30982567F",a));
    EXPECT_FALSE(p.Comprobardni("78124423D",a));
    EXPECT_TRUE(p.Comprobardni("12345678E",a));
} 




TEST(insertarActividades,P08){
    vector<Actividades> a1;
    Actividades a(5);
    Actividades a2(6);
    a1.push_back(a);
    a1.push_back(a2);
    EXPECT_FALSE(a.comprobarID(7,&a1));
    EXPECT_TRUE(a.comprobarID(5,&a1));
    EXPECT_TRUE(a.comprobarID(6,&a1));
}

