#include "gtest/gtest.h"
#include "persona.h"
#include "bd.h"
#include "actividades.h"

TEST(Comprobardni,PO1){
    vector<Persona> a;
    Persona p("12345678F");
    a.push_back(p);
    EXPECT_TRUE(p.Comprobardni("12345678F",a));
    EXPECT_FALSE(p.Comprobardni("46532817B",a));
    EXPECT_FALSE(p.Comprobardni("19554682P",a));
}  

TEST(comprobarID,P02){
    vector<Actividades> a1;
    Actividades a(3);
    Actividades a2(7);
    a1.push_back(a);
    a1.push_back(a2);
    EXPECT_FALSE(a.comprobarID(9,&a1));
    EXPECT_TRUE(a.comprobarID(3,&a1));
    EXPECT_TRUE(a.comprobarID(7,&a1));
}



TEST(comprobarAforo,P03){
    Actividades a;
    EXPECT_TRUE(a.comprobarAforo(77));
    EXPECT_TRUE(a.comprobarAforo(56));
    EXPECT_FALSE(a.comprobarAforo(201));
    EXPECT_FALSE(a.comprobarAforo(0));
    EXPECT_FALSE(a.comprobarAforo(-3));
}


TEST(inscribirseActividades,P04){
    BD bd;
    vector<Persona> p;
    vector<Actividades>a;
    Actividades a1(2);
    Actividades a2(9);
    Actividades a3(3);
    Persona p1;
    p1.setDni("12345678F");
    Persona p2;
    p2.setDni("12345678A");
    Persona p3;
    p3.setDni("14368279H");
    a.push_back(a1);
    a.push_back(a2);
    a.push_back(a3);
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    EXPECT_TRUE(bd.inscribirseActividades(2,"12345678F",&a,&p));
    EXPECT_TRUE(bd.inscribirseActividades(9,"12345678A",&a,&p));;
    EXPECT_FALSE(bd.inscribirseActividades(5,"14368279H",&a,&p));
    EXPECT_FALSE(bd.inscribirseActividades(0,"77009706L",&a,&p));
}

TEST(eliminarP,P05){
    vector<Persona>p1;
    BD bd;
    Persona p("12345678F");
    Persona p2("12345678E");
    p1.push_back(p);
    p1.push_back(p2);
    EXPECT_TRUE(bd.eliminarP("12345678F",&p1));
    EXPECT_TRUE(bd.eliminarP("12345678E",&p1));
    EXPECT_FALSE(bd.eliminarP("20212022R",&p1));
    EXPECT_FALSE(bd.eliminarP("01893467X",&p1));

}

TEST(eliminar,P06){
      vector<Actividades>p1;
    BD bd;
    Actividades p(3);
    Actividades p2(4);
    p1.push_back(p);
    p1.push_back(p2);
    EXPECT_TRUE(bd.eliminar(3,&p1));
    EXPECT_TRUE(bd.eliminar(4,&p1));
    EXPECT_FALSE(bd.eliminar(5,&p1));
    EXPECT_FALSE(bd.eliminar(6,&p1));
    EXPECT_FALSE(bd.eliminar(0,&p1));
}


TEST(insertarUsuario,P07){
    vector<Persona> a;
    Persona p("12345678F");
    Persona p2("12345678E");
    a.push_back(p);
    a.push_back(p2);
    EXPECT_TRUE(p.Comprobardni("12345678F",a));
    EXPECT_FALSE(p.Comprobardni("46971355J",a));
    EXPECT_FALSE(p.Comprobardni("97472691U",a));
    EXPECT_TRUE(p.Comprobardni("12345678E",a));
} 




TEST(insertarActividades,P08){
    vector<Actividades> a1;
    Actividades a(7);
    Actividades a2(9);
    a1.push_back(a);
    a1.push_back(a2);
    EXPECT_FALSE(a.comprobarID(5,&a1));
    EXPECT_TRUE(a.comprobarID(7,&a1));
    EXPECT_TRUE(a.comprobarID(9,&a1));
}

