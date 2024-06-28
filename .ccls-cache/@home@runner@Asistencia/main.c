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


void cargarEstudiantes(HashMap *map){
    FILE *archivo = fopen("CVS/Data.csv", "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    char linea[256];
    fgets(linea, sizeof(linea), archivo); // Omitir la primera línea (cabecera)
    while (fgets(linea, sizeof(linea), archivo)) 
    {
        Alumno *alumno = malloc(sizeof(Alumno));
        alumno->cursos = list_create();
        sscanf(linea, "%[^,],%[^,],%[^,]", alumno->rut, alumno->nombre, alumno->carrera);

        // Inicialización de asistencia
        for (int i = 0; i < 30; i++) 
        {
            for (int j = 0; j < 5; j++) 
            {
                alumno->asistencias[i][j] = 0; // Todos inicializados como ausentes
            }
        }
        

        int paraleloFisica, paraleloCalculo, paraleloAlgebra, paraleloFilosofia, paraleloProgramacion;
        sscanf(linea, "%*[^,],%*[^,],%*[^,],%d,%d,%d,%d,%d", &paraleloFisica, &paraleloCalculo, &paraleloAlgebra, &paraleloFilosofia, &paraleloProgramacion);
        

        insertarEnCurso("fisica", paraleloFisica, alumno);
        insertarEnCurso("calculo", paraleloCalculo, alumno);
        insertarEnCurso("algebra", paraleloAlgebra, alumno);
        insertarEnCurso("filosofia", paraleloFilosofia, alumno);
        insertarEnCurso("programacion", paraleloProgramacion, alumno);


        insertMap(map, alumno->rut, alumno);
    }
    
    fclose(archivo);
    printf("Estudiantes cargados exitosamente.\n");
}



void marcarAsistencia(Alumno *estudiante, const char *nombre_curso, int dia, int presente) {
    int curso_index = -1;
    for (int i = 0; i < NUM_CURSOS; i++) {
        if (strcmp(cursos[i], nombre_curso) == 0) {
            curso_index = i;
            break;
        }
    }

    if (curso_index == -1) {
        printf("Curso no encontrado.\n\n");
        return;
    }

    
}

void mostrarAsistencias(HashMap *estudiantes_byRut, int dia) {
    Pair *pair = firstMap(estudiantes_byRut);
    while (pair != NULL) {
        Alumno *est = pair->value;
        printf("RUT: %s, Nombre: %s, Carrera: %s\n\n", est->rut, est->nombre, est->carrera);

        for (int i = 0; i < NUM_CURSOS; i++) {
            printf("  Curso: %s\n", cursos[i]);
            printf("  Asistencias:\n");
            for (int j = 0; j < dia; j++) {
                printf("    Día %d: %s\n", j + 1, est->asistencias[i][j] ? "Presente" : "Ausente");
            }
            printf("\n");
        }

        pair = nextMap(estudiantes_byRut);
    }
}

void buscarAsistenciaPorRUT(HashMap *estudiantes_byRut, int dia) {
    printf("Eligió la opción de Buscar por RUT\n\n");
    char rut[20];

    printf("Ingrese el RUT que quiere buscar: \n");
    scanf(" %19s", rut); // %19s para evitar desbordamiento de buffer

    Pair *pair = searchMap(estudiantes_byRut, rut);

    if (pair == NULL) {
        printf("Estudiante con RUT %s no encontrado.\n\n", rut);
    } else {
        Alumno *est = pair->value;
        printf("\n");
        printf("RUT: %s, Nombre: %s, Carrera: %s\n\n", est->rut, est->nombre, est->carrera);

        for (int i = 0; i < NUM_CURSOS; i++) {
            printf("  Curso: %s\n", cursos[i]);
            printf("  Asistencias:\n");
            for (int j = 0; j < dia; j++) {
                printf("    Día %d: %s\n", j + 1, est->asistencias[i][j] ? "Presente" : "Ausente");
            }
            printf("\n");
        }
    } 
}

void mostrarAsistenciaPorCurso(HashMap *estudiantes_byRut, const char *nombre_curso, int dia) {
    int curso_index = -1;
    for (int i = 0; i < NUM_CURSOS; i++) {
        if (strcmp(cursos[i], nombre_curso) == 0) {
            curso_index = i;
            break;
        }
    }

    if (curso_index == -1) {
        printf("\n");
        printf("Curso no encontrado.\n");
        return;
    }
    printf("\n");
    printf("Asistencia para el curso: %s\n", nombre_curso);
    printf("RUT           Nombre                Asistencias\n");
    printf("-------------------------------------------------\n");

    Pair *pair = firstMap(estudiantes_byRut);
    while (pair != NULL) {
        Alumno *est = pair->value;
        printf("%-13s %-20s ", est->rut, est->nombre);
        for (int j = 0; j < dia; j++) {
            printf("%s ", est->asistencias[curso_index][j] ? "P" : "A");
        }
        printf("\n");
        pair = nextMap(estudiantes_byRut);
    }
}

int main() {

    HashMap *estudiantes_byRut = createMap(200);

    char rut[20], nombre_curso[50];
    int dia_actual = 1;
    char presenteausente_str[20];
    int paralelo;
    

    int dia, presente;
    char opcion;
    cargarEstudiantes(estudiantes_byRut);
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
            printf("\n");
            printf("Ingrese el RUT del estudiante: ");
            scanf(" %19s", rut);
            printf("\n");
            Pair *pair = searchMap(estudiantes_byRut, rut);
            if (pair == NULL) {
                printf("Estudiante con RUT %s no encontrado.\n", rut);
                break;
            }

            Alumno *est = pair->value;

            printf("Ingrese el nombre del curso: ");
            scanf(" %49s", nombre_curso);
            printf("\n");
            printf("Ingrese el día (1 a %d): ", MAX_DIAS);
            scanf("%d", &dia);
            dia--; // Ajustar a índice base 0
            printf("\n");
            printf("¿Estuvo presente? (1 para presente, 0 para ausente): ");
            scanf("%d", &presente);
            printf("\n");
            marcarAsistencia(est, nombre_curso, dia, presente);
            break;
          
        case '2':
            printf("\n");
            mostrarAsistencias(estudiantes_byRut, dia_actual);
            break;
          
        case '3':
            printf("\n");
            buscarAsistenciaPorRUT(estudiantes_byRut, dia_actual);
            break;

        case '4':
            printf("\n");
            printf("Ingrese el nombre del curso: ");
            scanf(" %49s", nombre_curso);
            mostrarAsistenciaPorCurso(estudiantes_byRut, nombre_curso, dia_actual);
            break;
          
        case '5':
            
            break;
          
        default:
            printf("Opción no válida, por favor intente nuevamente.\n");
            break;
        }
        presioneTeclaParaContinuar();
        limpiarPantalla();

  } while (opcion != '6');

    free(estudiantes_byRut);

  return 0;
}