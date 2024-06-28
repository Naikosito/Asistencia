# Proyecto Registro de Asistencia
## Descripción

El objetivo del programa es gestionar y registrar la asistencia de los estudiantes a las clases en una universidad de manera eficiente y precisa. El sistema debe ser capaz de manejar un gran número de materias y estudiantes, permitiendo búsquedas rápidas y actualizaciones de los registros de asistencia.

## Cómo compilar y ejecutar



````
gcc tdas/*.c main.c -Wno-unused-result -o main.c
````

Y luego ejecutar:
````
./main.c
````

## Funcionalidades
### Funcionando correctamente:

- Marcar Asistencia
- Mostrar Asistencias Generales
- Mostrar Asistencia Por RUT
- Mostrar Asistencia Por Curso
- Avanzar A La Siguiente Clase


## Ejemplo de uso

**Opcion 1: Marcar Asistencia**

Se pide al usuario que ingrese su rut y el curso donde se quiere registrar su asistencia

```
Ingrese el RUT del estudiante: 17223344-5

Ingrese el nombre del curso: 

Fisica
Calculo
Algebra
Filosofía
Programacion

Curso Ingresado: Fisica

Estuvo Presente?
1 para presente, 0 para ausente

Opcion ingresada: 1

Alumno Juan Perez ha quedado presente en la clase 1
```

 Marca la asistencia dentro del curso.

**Opcion 2: Mostrar Asistencia General**

```
RUT: 17223344-5, Nombre: Juan Pérez, Carrera: Ingeniería Civil

Curso: Física Paralelo 1
Asistencias:
    Clase 1: Presente
    Clase 2: Ausente
Curso: Cálculo Paralelo 1
Asistencias:
    Clase 1: Presente
    Clase 2: Presente
Curso: Álgebra Paralelo 1
Asistencias:
    Clase 1: Presente
    Clase 2: Presente
Curso: Filosofía Paralelo 1
Asistencias:
    Clase 1: Ausente
    Clase 2: Presente
Curso: Programación Paralelo 1
Asistencias:
    Clase 1: Presente
    Clase 2: Ausente

RUT: 17334455-6, Nombre: Ana Gómez, Carrera: Ingeniería Comercial

Curso: Física Paralelo 2
Asistencias:
    Clase 1: Presente
    Clase 2: Presente


```
El programa imprime todas las clases registradas de todos los estudiantes hasta el momento


**Opcion 3: Mostrar Asistencia por Rut**

El programa pide el rut para buscar al estudiante dentro del mapa

```
RUT: 17223344-5, Nombre: Juan Pérez, Carrera: Ingeniería Civil

Curso: Física Paralelo 1
Asistencias:
    Clase 1: Presente
    Clase 2: Ausente
Curso: Cálculo Paralelo 1
Asistencias:
    Clase 1: Presente
    Clase 2: Presente
Curso: Álgebra Paralelo 1
Asistencias:
    Clase 1: Presente
    Clase 2: Presente
Curso: Filosofía Paralelo 1
Asistencias:
    Clase 1: Ausente
    Clase 2: Presente
Curso: Programación Paralelo 1
Asistencias:
    Clase 1: Presente
    Clase 2: Ausente
```

Se muestra toda la informacion relevante del estudiante

**Opcion 4: Mostrar Asistencia por Curso**

El programa pide al usuario que se ingrese el curso

```
Ingrese el nombre del curso que quiere buscar: Física
Asistencia hasta la clase 2

RUT: 17223344-5, Nombre: Juan Pérez, Carrera: Ingeniería Civil

Curso: Física Paralelo: 1
Asistencias:
    Clase 1: Presente
    Clase 2: Ausente

RUT: 17778899-0, Nombre: José Hernández, Carrera: Ingeniería Civil

Curso: Física Paralelo: 1
Asistencias:
    Clase 1: Ausente
    Clase 2: Ausente

RUT: 18223344-5, Nombre: Rosa Gutiérrez, Carrera: Ingeniería Informática

Curso: Física Paralelo: 1
Asistencias:
    Clase 1: Presente
    Clase 2: Presente
```

Imprime todas las clases que los estudiantes han asistido hasta el momento

**Opcion 5: Avanzar A La Siguiente Clase**

```
Estabas en la clase 1, Has avanzado a la clase 2
```
Avanza a la siguiente clase lo que permite registrar la asistencia de la siguiente clase 

**Paso 6: Salir**

Al ingresar la opcion 6 se finalizara el programa.
```
Ingrese su opción: 6
Presione una tecla para continuar...
```