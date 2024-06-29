#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "TDAs/list.h"
#include "TDAs/extra.h"
#include "TDAs/hashmap.h"

typedef struct {
    char rut[12]; // Rut del alumno
    char nombre[50]; // Nombre del alumno
    char carrera[50]; // Nombre de la carrera
    HashMap* cursos; // Mapa de cursos del alumno
} Alumno;

typedef struct {
    char nombreCurso[50]; // Nombre del curso
    int numParalelo; // Número del paralelo
    HashMap* alumnos; // Mapa de alumnos en el curso
    int asistenciaClases[60]; // Lista de alumnos presentes para cada clase / 60 Son las clases totales de un ramo
} Curso;

// Definición de la estructura Paralelo
typedef struct{
    List* cursos; //Lista de cursos en este paralelo
} Paralelo;


#define HASHMAP_SIZE 100

// Mapa global para almacenar todos los cursos
static Hashmap* cursosMap;

void insertarCurso(Curso* curso) {
    hashmapInsert(cursosMap, curso->nombreCurso, curso);
}

Curso* buscarCurso(char *nombreCurso, int paralelo) {
    Pair* curso = searchMap(cursosMap, nombreCurso);
    if (curso != NULL && curso->numParalelo == paralelo) {
        return curso;
    }
    return NULL;
}

void cargarEstudiantes() {
    cursosMap = createHashmap(HASHMAP_SIZE);
    FILE *archivo = fopen("CVS/Data.csv", "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    char linea[256];
    fgets(linea, sizeof(linea), archivo); // Omitir la primera línea (cabecera)
    while (fgets(linea, sizeof(linea), archivo)) {
        Alumno *alumno = malloc(sizeof(Alumno));
        alumno->cursos = createHashmap(HASHMAP_SIZE);
        sscanf(linea, "%[^,],%[^,],%[^,]", alumno->rut, alumno->nombre, alumno->carrera);

        int paraleloFisica, paraleloCalculo, paraleloAlgebra, paraleloFilosofia, paraleloProgramacion;
        sscanf(linea, "%*[^,],%*[^,],%*[^,],%d,%d,%d,%d,%d", &paraleloFisica, &paraleloCalculo, &paraleloAlgebra, &paraleloFilosofia, &paraleloProgramacion);

        insertarEnCurso("fisica", paraleloFisica, alumno);
        insertarEnCurso("calculo", paraleloCalculo, alumno);
        insertarEnCurso("algebra", paraleloAlgebra, alumno);
        insertarEnCurso("filosofia", paraleloFilosofia, alumno);
        insertarEnCurso("programacion", paraleloProgramacion, alumno);
    }
    fclose(archivo);
    printf("Estudiantes cargados exitosamente.\n");
}

void insertarEnCurso(char *nombreCurso, int paralelo, Alumno* alumno) {
    Curso *curso = buscarCurso(nombreCurso, paralelo);
    if (curso == NULL) {
        curso = malloc(sizeof(Curso));
        strcpy(curso->nombreCurso, nombreCurso);
        curso->numParalelo = paralelo;
        curso->alumnos = createHashmap(HASHMAP_SIZE);

        for (int i = 0; i < 60; i++) {
            curso->asistenciaClases[i] = list_create();
        }
        insertarCurso(curso);
    }

    hashmapInsert(curso->alumnos, alumno->rut, alumno);
    hashmapInsert(alumno->cursos, nombreCurso, curso);

    for (int i = 0; i < 60; i++) {
        list_pushBack(curso->asistenciaClases[i], false);
    }
}

Pair* buscarAlumnoPorRUT(Curso *curso, const char *rut) {
    return searchMap(curso->alumnos, &rut);
}


int main() {

    cargarEstudiantes();
    
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
            marcarAsistencia();        
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