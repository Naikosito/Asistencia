#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "TDAs/list.h"
#include "TDAs/extra.h"
#include "TDAs/hashmap.h"

#define MAX_DIAS 30  // Máximo número de días que se pueden registrar
#define NUM_CURSOS 5  // Número de cursos

const char *cursos[NUM_CURSOS] = {"Fisica", "Calculo", "Algebra", "Filosofia", "Programacion"};

typedef struct {
    char rut[12];
    char nombre[50];
    char carrera[50];
    List* cursos;
    int asistencias[NUM_CURSOS][MAX_DIAS];  // Asistencias por curso y por día
} Alumno;

typedef struct {
    char nombreCurso[50];
    int paralelo;
    List* alumnos; 
    List* asistenciaClases[60]; 
} Curso;


int main() {

    HashMap *estudiantes_byRut = createMap(200);

    char rut[20], nombre_curso[50];
    int dia_actual = 1;
    int paralelo;
    int dia, presente;
    
    char opcion;
    do {
        puts("==============================================");
        puts("  Control de Asistencia Universidad PUCV 2024");
        puts("==============================================");

        puts("1) Marcar Asistencia");
        puts("2) Mostrar Asistencias Generales");
        puts("3) Mostrar Asistencia Por RUT");
        puts("4) Mostrar Asistencia Por Curso");
        puts("5) Avanzar A La Siguiente Clase");
        puts("6) Salir");

        printf("Ingrese su opción: ");
        scanf(" %c", &opcion);

      switch (opcion) {      
        case '1':
            // marcarAsistencia();        
            break;
          
        case '2':
            // mostrarAsistencias();
            break;
          
        case '3':
            // buscarAsistenciaPorRUT();
            break;

        case '4':
            // mostrarAsistenciaPorCurso();
            break;
          
        case '5':
            // avanzarClase();
            break;
          
        default:
            printf("Opción no válida, por favor intente nuevamente.\n");
            break;
        }
        presioneTeclaParaContinuar();
        limpiarPantalla();

  } while (opcion != '6');

  return 0;
}