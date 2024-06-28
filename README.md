# Proyecto
## Descripción
La aplicación permitirá cargar datos de Estudiantes desde un archivo CSV y ofrecerá varias funcionalidades como Marcar Asistencia, como Mostrar Asistencia de manera general, o como Mostrar Asistencia por RUT.
## Cómo compilar y ejecutar
Para ejecutar la `tarea2.c`, primero debemos compilar los archivos fuente. Desde la carpeta raíz del proyecto, ejecuta el siguiente comando en tu terminal:
````
gcc tdas/*.c tarea2.c -Wno-unused-result -o tarea2
````

Y luego ejecutar:
````
./tarea2
````

## Funcionalidades
### Funcionando correctamente:
- Cargar películas desde el csv: Se cargan las películas desde el archivo "Top1500.csv".
- Buscar por id: Se le pide pide al usuario el ID que quiere buscar, y se le muestra la película correspondiente.
- Buscar por género: Se le pide al usuario el Género que quiere buscar, y se le muestran las peliculas correspondientes a ese Género.
- Buscar por década: Se le pide al usuario la Década que quiere buscar, y se le muestran las películas correspondientes. Es IMPORTANTE ingresar la década como por ej. "2000, 1990, 1980".
- Buscar por década y género: Se le pide al usuario el Género que quiere buscar, y si se encuentra el Género se le pide la Década para mostrar las películas correspondientes.
- Salir: Sale del programa finalizando el sistema.
  
### Problemas conocidos:
- Podria ocurrir problemas al ingresar numeros o palabras en las funciones de búsqueda que no deberian ir, lo que podría provocar que el programa no funcione correctamente o que no responda como se espera.

### A mejorar:
- Implementar una interfaz de usuario más amigable.
- Permitir que el programa pueda leer diferentes csv de peliculas.

## Ejemplo de uso

**Paso 1: Cargar las Películas**

Se comienza cargando las películas del "Top1500.csv".

```
Ingrese su opción: 1
Eligio la opcion de Cargar Películas
ID: tt0068646, Título: The Godfather, Año: 1972
Genero: Crime
Genero: Drama
Presione una tecla para continuar...
```

El programa muestra las 1500 películas que se cargaron a la base de datos, mostrando su ID, Título, Año y Géneros.

**Paso 2: Buscar por id**

Si ingresa el ID valido de una pelicula, se le mostrara la pelicula correspondiente junto a su titulo, y año. 

```
Ingrese su opción: 2
Eligio la opcion de Buscar por id
Ingrese el id de la película: tt0068646
Título: The Godfather, Año: 1972
Presione una tecla para continuar...
```

**Paso 3: Buscar por director**

Esta funcion no la realice ya que era opcional
```
Ingrese su opción: 3
Presione una tecla para continuar...
```

**Paso 4: Buscar por género**

Si ingresa un género, se le mostraran las peliculas que corresponden a ese género, mostrandole el titulo, año y género.

```
Ingrese su opción: 4
Eligio la opcion de Buscar por Género
Ingrese el genero que quiere buscar: 
Drama
Título: Casablanca, Año: 1942
Genero: Drama
Genero: Romance
Genero: War
...
```

**Paso 5: Buscar por década**

Si ingresa la decada que quiere buscar, se le mostraran películas que corresponden a esa década, junto a su titulo y año.
```
Ingrese su opción: 5
Eligio la opcion de Buscar por Década
Ingrese la decada que quiere buscar: 
2000
Título: The Lord of the Rings: The Fellowship of the Ring, Año: 2001
...
```

**Paso 6: Buscar por rango de calificaciones**

Esta funcion no la realice ya que era opcional
```
Ingrese su opción: 6
Presione una tecla para continuar...
```

**Paso 7: Buscar por década y género**

Si ingresa el género y luego la década, se le mostraran las peliculas que corresponden junto a su titulo y año.
```
Ingrese su opción: 7
Eligio la opcion de Buscar por Década y Género
Ingrese el genero de las peliculas que quiere buscar: 
Drama
Ingrese la decada de las peliculas que quiere buscar: 
2000
Título: The Lord of the Rings: The Return of the King, Año: 2003
...
```
**Paso 8: Salir**

Al ingresar la opcion 8 se finalizara el programa.
```
Ingrese su opción: 8
Presione una tecla para continuar...
```