# Proyecto Registro de Asistencia
## Descripción

El objetivo del programa es gestionar y registrar la asistencia de los estudiantes a las clases en una universidad de manera eficiente y precisa. El sistema debe ser capaz de manejar un gran número de materias y estudiantes, permitiendo búsquedas rápidas y actualizaciones de los registros de asistencia.

## Cómo compilar y ejecutar



````
Solo se debe presionar el boton Run que se encuentra en parte superior
````

## Funcionalidades
### Funcionando correctamente:

- Marcar Asistencia
- Mostrar Asistencias Generales
- Mostrar Asistencia Por RUT
- Mostrar Asistencia Por Curso
- Avanzar A La Siguiente Clase


## Ejemplo de uso

**Opcion 1: Cargar Estudiantes**

```
Ingrese su opción: 1

Estudiantes cargados exitosamente.
```
**Opcion 2: Marcar Asistencia**

Se pide al usuario que ingrese su rut y el curso donde se quiere registrar su asistencia

```
Ingrese su opción: 2

Ingrese el RUT del estudiante: 17223344-5

Ingrese el nombre del curso: Fisica

Ingrese el día (1 a 30): 1

¿Estuvo presente? (1 para presente, 0 para ausente): 1

Asistencia marcada para Juan Pérez en el curso Fisica el día 1.
```
Marca la asistencia dentro del curso.


**Opcion 3: Mostrar Asistencia General**

```
RUT: 17223344-5, Nombre: Juan Pérez, Carrera: Ingeniería Civil

RUT: 17223344-5, Nombre: Juan Pérez, Carrera: Ingeniería Civil
  Curso: Física 
  Asistencias:
    Dia 1: Presente
    Dia 2: Ausente
    
  Curso: Cálculo 
  Asistencias:
    Dia 1: Presente
    Dia 2: Presente
    
  Curso: Álgebra 
  Asistencias:
    Dia 1: Presente
    Dia 2: Presente
    
  Curso: Filosofía 
  Asistencias:
    Dia 1: Ausente
    Dia 2: Presente
    
  Curso: Programación 
  Asistencias:
    Dia 1: Presente
    Dia 2: Ausente

RUT: 17334455-6, Nombre: Ana Gómez, Carrera: Ingeniería Comercial
  Curso: Fisica
  Asistencias:
    Día 1: Ausente
    Día 2: Presente

  Curso: Calculo
  Asistencias:
    Día 1: Presente
    Día 2: Presente

  Curso: Algebra
  Asistencias:
    Día 1: Presente
    Día 2: Presente

  Curso: Filosofia
  Asistencias:
    Día 1: Presente
    Día 2: Ausente

  Curso: Programacion
  Asistencias:
    Día 1: Ausente
    Día 2: Ausente
```
El programa imprime todas las clases registradas de todos los estudiantes hasta el momento


**Opcion 4: Mostrar Asistencia por Rut**

El programa pide el rut para buscar al estudiante dentro del mapa

```
RUT: 17223344-5, Nombre: Juan Pérez, Carrera: Ingeniería Civil

Curso: Física 
Asistencias:
    Dia 1: Presente
    Dia 2: Ausente
Curso: Cálculo 
Asistencias:
    Dia 1: Presente
    Dia 2: Presente
Curso: Álgebra 
Asistencias:
    Dia 1: Presente
    Dia 2: Presente
Curso: Filosofía 
Asistencias:
    Dia 1: Ausente
    Dia 2: Presente
Curso: Programación 
Asistencias:
    Dia 1: Presente
    Dia 2: Ausente
```

Se muestra toda la informacion relevante del estudiante

**Opcion 5: Mostrar Asistencia por Curso**

El programa pide al usuario que se ingrese el curso

```
Ingrese el nombre del curso que quiere buscar: Física
Asistencia hasta la clase 2

RUT: 17223344-5, Nombre: Juan Pérez, Carrera: Ingeniería Civil

Curso: Física 
Asistencias:
    Clase 1: Presente
    Clase 2: Ausente

RUT: 17778899-0, Nombre: José Hernández, Carrera: Ingeniería Civil

Curso: Física 
Asistencias:
    Clase 1: Ausente
    Clase 2: Presente

RUT: 18223344-5, Nombre: Rosa Gutiérrez, Carrera: Ingeniería Informática

Curso: Física 
Asistencias:
    Clase 1: Presente
    Clase 2: Presente
```

Imprime todas las clases que los estudiantes han asistido hasta el momento

**Paso 6: Salir**

Al ingresar la opcion 6 se finalizara el programa.
```
Ingrese su opción: 6
Presione una tecla para continuar...
```