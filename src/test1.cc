#include "gtest/gtest.h"
#include "persona.h"
#include "bd.h"
#include "actividades.h"

TEST(Comprobardni,PO1){
    vector<Persona> a;
    Persona p("12345678A");
    a.push_back(p);
    EXPECT_TRUE(p.Comprobardni("12345678A",a));
    EXPECT_FALSE(p.Comprobardni("45678938B",a));
    EXPECT_FALSE(p.Comprobardni("89671235B",a));
}  

TEST(comprobarID,P02){
    vector<Actividades> a1;
    Actividades a(1);
    Actividades a2(2);
    a1.push_back(a);
    a1.push_back(a2);
    EXPECT_FALSE(a.comprobarID(3,&a1));
    EXPECT_TRUE(a.comprobarID(1,&a1));
    EXPECT_TRUE(a.comprobarID(2,&a1));
}



TEST(comprobarAforo,P03){
    Actividades a;
    EXPECT_TRUE(a.comprobarAforo(20));
    EXPECT_TRUE(a.comprobarAforo(25));
    EXPECT_FALSE(a.comprobarAforo(201));
    EXPECT_FALSE(a.comprobarAforo(0));
    EXPECT_FALSE(a.comprobarAforo(-3));
}


TEST(inscribirseActividades,P04){
    BD bd;
    vector<Persona> p;
    vector<Actividades>a;
    Actividades a1(10);
    Actividades a2(6);
    Actividades a3(2);
    Persona p1;
    p1.setDni("12345678A");
    Persona p2;
    p2.setDni("12345678B");
    Persona p3;
    p3.setDni("45781263F");
    a.push_back(a1);
    a.push_back(a2);
    a.push_back(a3);
    p.push_back(p1);
    p.push_back(p2);
    p.push_back(p3);
    EXPECT_TRUE(bd.inscribirseActividades(10,"12345678A",&a,&p));
    EXPECT_TRUE(bd.inscribirseActividades(6,"12345678B",&a,&p));;
    EXPECT_FALSE(bd.inscribirseActividades(15,"45781263F",&a,&p));
    EXPECT_FALSE(bd.inscribirseActividades(20,"78324915R",&a,&p));
}

TEST(eliminarP,P05){
    vector<Persona>p1;
    BD bd;
    Persona p("12345678A");
    Persona p2("12345678C");
    p1.push_back(p);
    p1.push_back(p2);
    EXPECT_TRUE(bd.eliminarP("12345678A",&p1));
    EXPECT_TRUE(bd.eliminarP("12345678C",&p1));
    EXPECT_FALSE(bd.eliminarP("78936125K",&p1));
    EXPECT_FALSE(bd.eliminarP("19463875E",&p1));

}

TEST(eliminar,P06){
      vector<Actividades>p1;
    BD bd;
    Actividades p(2);
    Actividades p2(5);
    p1.push_back(p);
    p1.push_back(p2);
    EXPECT_TRUE(bd.eliminar(2,&p1));
    EXPECT_TRUE(bd.eliminar(5,&p1));
    EXPECT_FALSE(bd.eliminar(3,&p1));
    EXPECT_FALSE(bd.eliminar(4,&p1));
    EXPECT_FALSE(bd.eliminar(0,&p1));
}


TEST(insertarUsuario,P07){
    vector<Persona> a;
    Persona p("12345678A");
    Persona p2("12345678B");
    a.push_back(p);
    a.push_back(p2);
    EXPECT_TRUE(p.Comprobardni("12345678A",a));
    EXPECT_FALSE(p.Comprobardni("30982434D",a));
    EXPECT_FALSE(p.Comprobardni("78124598B",a));
    EXPECT_TRUE(p.Comprobardni("12345678B",a));
} 




TEST(insertarActividades,P08){
    vector<Actividades> a1;
    Actividades a(1);
    Actividades a2(2);
    a1.push_back(a);
    a1.push_back(a2);
    EXPECT_FALSE(a.comprobarID(3,&a1));
    EXPECT_TRUE(a.comprobarID(1,&a1));
    EXPECT_TRUE(a.comprobarID(2,&a1));
}

