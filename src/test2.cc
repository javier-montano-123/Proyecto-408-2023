#include "gtest/gtest.h"
#include "persona.h"
#include "bd.h"
#include "actividades.h"

TEST(Comprobardni,PO1){
    vector<Persona> a;
    Persona p("12345678B");
    a.push_back(p);
    EXPECT_TRUE(p.Comprobardni("12345678B",a));
    EXPECT_FALSE(p.Comprobardni("45678938C",a));
    EXPECT_FALSE(p.Comprobardni("89671235C",a));
}  

TEST(comprobarID,P02){
    vector<Actividades> a1;
    Actividades a(2);
    Actividades a2(3);
    a1.push_back(a);
    a1.push_back(a2);
    EXPECT_FALSE(a.comprobarID(4,&a1));
    EXPECT_TRUE(a.comprobarID(2,&a1));
    EXPECT_TRUE(a.comprobarID(3,&a1));
}



TEST(comprobarAforo,P03){
    Actividades a;
    EXPECT_TRUE(a.comprobarAforo(21));
    EXPECT_TRUE(a.comprobarAforo(26));
    EXPECT_FALSE(a.comprobarAforo(201));
    EXPECT_FALSE(a.comprobarAforo(0));
    EXPECT_FALSE(a.comprobarAforo(-3));
}


TEST(inscribirseActividades,P04){
    BD bd;
    vector<Persona> p;
    vector<Actividades>a;
    Actividades a1(11);
    Actividades a2(7);
    Actividades a3(3);
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
    EXPECT_TRUE(bd.inscribirseActividades(11,"12345678A",&a,&p));
    EXPECT_TRUE(bd.inscribirseActividades(7,"12345678B",&a,&p));;
    EXPECT_FALSE(bd.inscribirseActividades(16,"45781263F",&a,&p));
    EXPECT_FALSE(bd.inscribirseActividades(21,"78324915R",&a,&p));
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
    EXPECT_FALSE(bd.eliminarP("78936125G",&p1));
    EXPECT_FALSE(bd.eliminarP("19463875D",&p1));

}

TEST(eliminar,P06){
      vector<Actividades>p1;
    BD bd;
    Actividades p(1);
    Actividades p2(4);
    p1.push_back(p);
    p1.push_back(p2);
    EXPECT_TRUE(bd.eliminar(1,&p1));
    EXPECT_TRUE(bd.eliminar(4,&p1));
    EXPECT_FALSE(bd.eliminar(3,&p1));
    EXPECT_FALSE(bd.eliminar(6,&p1));
    EXPECT_FALSE(bd.eliminar(0,&p1));
}


TEST(insertarUsuario,P07){
    vector<Persona> a;
    Persona p("12345678B");
    Persona p2("12345678C");
    a.push_back(p);
    a.push_back(p2);
    EXPECT_TRUE(p.Comprobardni("12345678B",a));
    EXPECT_FALSE(p.Comprobardni("30982434E",a));
    EXPECT_FALSE(p.Comprobardni("78124598T",a));
    EXPECT_TRUE(p.Comprobardni("12345678C",a));
} 




TEST(insertarActividades,P08){
    vector<Actividades> a1;
    Actividades a(2);
    Actividades a2(3);
    a1.push_back(a);
    a1.push_back(a2);
    EXPECT_FALSE(a.comprobarID(4,&a1));
    EXPECT_TRUE(a.comprobarID(2,&a1));
    EXPECT_TRUE(a.comprobarID(3,&a1));
}

