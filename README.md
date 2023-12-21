## PROYECTO 408

Este proyecto se basa en la implementación de un  programa que contenga un menú el cúal permitirá a diferentes usuarios que accedan a él, desarrollar una serie de funciones diferentes dependiendo de su rol.


## Uso

Explicación sobre cómo usar el programa.

Para comenzar a usar nuestro programa, en primer lugar deberá acceder al directorio 'src'. Una vez dentro deberá ejecutar las siguientes líneas de comandos : 

'g++ main.cc menu.cc bd.cc -o proyecto408'
'./proyecto408'

Escribiremos estas líneas de comando para compilar y ejecutar el programa respectivamente.
Una vez ejecutado el programa, accederá a un menú principal en el que tendrás las siguientes opciónes :

1. Login
2. Visitante
0. Salir

Si seleccionas la opción 1. Login, deberás saber que hay tres tipos distintos de roles asociados a un parámetro de tipo entero reflejado en el fichero "usuarios.txt"

Para hacer Login deberás acceder con un DNi. Estos son los DNI con los cúales puedes hacer Login. A su derecha le informo del rol asociado a cada DNI.

12345678A --> Organizador ( rol 1 )
12345678B --> Director Académico ( rol 2 )
12345678C --> Usuario Registrado ( rol 3 )
12345678D --> Usuario Registrado ( rol 3 )	
12345678E --> Usuario Registrado ( rol 3 )
12345678F --> Usuario Registrado ( rol 3 )

Al hacer Login con uno de los anteriores DNI obtendrás acceso a las diferentes partes del menú dependiendo del rol asociado a tal DNI.


Si seleccionas la opción 2. Visitante, no deberás hacer login y entrarás directamente al Menú Visitante con sus respectivas funcionalidades.


Si seleecionas la opción 3. Salir, el programá se cerrará.



Si desea comprobar que los tests funcionan, deberás acceder al directorio 'src'. Una vez dentro deberá ejecutar las siguientes líneas de comandos :

'make test1'
'./test1'

'make test2'
'./test2'

'make test3'
'./test3'

'make test4'
'./test4'

'make test5'
'./test5'

'make test6'
'./test6'



## Autores

Javier Montaño Ruiz, David García Peragón, Sergio Sampedro Guerrero.











