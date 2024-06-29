#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "TDAs/list.h"
#include "TDAs/extra.h"
#include "TDAs/map.h"

#define MAX_DIAS 30  // Máximo número de días que se pueden registrar
#define NUM_CURSOS 5  // Número de cursos

// Arreglo estatico donde se guardan los ramos que estan registrados en el programa
const char *cursos[NUM_CURSOS] = {"Fisica", "Calculo", "Algebra", "Filosofia", "Programacion"};

typedef struct {
    char rut[20]; // Rut del estudiante
    char nombre[50]; // Nombre del estudiante
    char carrera[50]; // Carrera del estudiante
    int asistencias[NUM_CURSOS][MAX_DIAS];  // Asistencias por curso y por día
    int num_dias[NUM_CURSOS];  // Número de días registrados por curso
} Estudiante;

/**
 * Compara dos claves de tipo string para determinar si son iguales.
 * Esta función se utiliza para inicializar mapas con claves de tipo string.
 *
 * @param key1 Primer puntero a la clave string.
 * @param key2 Segundo puntero a la clave string.
 * @return Retorna 1 si las claves son iguales, 0 de lo contrario.
 */

int is_equal_string(void *key1, void *key2) {
    return strcmp((char *)key1, (char *)key2) == 0;
}

/**
 * Carga los estudiantes desde un archivo CSV y las almacena en un mapa por su Rut.
 */

void cargarEstudiantes(Map *estudiantes_byRut) {
    FILE *archivo = fopen("CVS/Data.csv", "r"); // abre el archivo csv en modo lectura
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    char linea[256]; // buffer para almacenar la cadena leida
    fgets(linea, sizeof(linea), archivo); // Omitir la primera línea (cabecera)
    while (fgets(linea, sizeof(linea), archivo)) 
    {
        Estudiante *est = (Estudiante *)malloc(sizeof(Estudiante)); // asignar memoria para un nuevo estudiante
        // Parsear la línea leída y almacenar los valores en el struct del estudiante
        sscanf(linea, "%19[^,],%49[^,],%49[^,]", est->rut, est->nombre, est->carrera);
        // Inicializar los arrays de asistencias y num_dias a 0
        memset(est->asistencias, 0, sizeof(est->asistencias));
        memset(est->num_dias, 0, sizeof(est->num_dias));
        // Insertar el estudiante en el mapa de estudiantes por Rut
        map_insert(estudiantes_byRut, est->rut, est);
    }

    fclose(archivo); // cierro el archivo csv
    printf("Estudiantes cargados exitosamente.\n");
}

// Funcion para registrar la asistencia en un curso
void marcarAsistencia(Estudiante *estudiante, const char *nombre_curso, int dia, int presente) {
    int curso_index = -1; // Inicializamos el índice del curso a -1
    for (int i = 0; i < NUM_CURSOS; i++) { // buscamos el curso en el arreglo de cursos
        if (strcmp(cursos[i], nombre_curso) == 0) {
            curso_index = i;
            break;
        }
    }
    // si no lo encontramos se acaba el programa
    if (curso_index == -1) {
        printf("Curso no encontrado.\n\n");
        return;
    }

    // si el dia actual excede al maximo de dias permitidos se acaba el programa
    if (dia < MAX_DIAS) {
        // se registra al estudiante en el curso y dia correcto dentro de la matriz
        estudiante->asistencias[curso_index][dia] = presente; 
        // se actualiza el numero de dias registrados por el curso
        if (dia >= estudiante->num_dias[curso_index]) {
            estudiante->num_dias[curso_index] = dia + 1;
        }
        printf("Asistencia marcada para %s en el curso %s el día %d.\n", estudiante->nombre, nombre_curso, dia + 1);
    } else {
        printf("Número de día excede el máximo permitido.\n");
    }
}

// Funcion para mostrar la asistencia de todos los estudiantes registrados, 
void mostrarAsistencias(Map *estudiantes_byRut) {
    // obtenemos la primera entrada del mapa
    MapPair *pair = map_first(estudiantes_byRut);
    while (pair != NULL) { // ciclo que recorre el mapa por completo
        Estudiante *est = pair->value; // sacamos el estudiante del mapa
        printf("RUT: %s, Nombre: %s, Carrera: %s\n", est->rut, est->nombre, est->carrera);

        for (int i = 0; i < NUM_CURSOS; i++) { // ciclo que recorre los 5 cursos
            printf("  Curso: %s\n", cursos[i]);
            printf("  Asistencias:\n");
            for (int j = 0; j < est->num_dias[i]; j++) { // ciclo que imprime las asistencias hasta el dia actual
                printf("    Día %d: %s\n", j + 1, est->asistencias[i][j] ? "Presente" : "Ausente");
            }
            printf("\n");
        }

        pair = map_next(estudiantes_byRut); // se avanza al siguiente estudiante en el mapa
    }
}

// Funcion para mostrar la asistencia de un estudiante especifico por su rut
void buscarAsistenciaPorRUT(Map *estudiantes_byRut) {
    printf("Eligió la opción de Buscar por RUT\n\n");
    char rut[20];

    printf("Ingrese el RUT que quiere buscar: \n");
    scanf(" %19s", rut); // %19s para evitar desbordamiento de buffer

    // buscamos al estudiante en el mapa por su rut
    MapPair *pair = map_search(estudiantes_byRut, rut);

    // si no se encuentra el estudiante en el mapa se acaba el programa y se avisa al usuario
    if (pair == NULL) {
        printf("Estudiante con RUT %s no encontrado.\n\n", rut);
    } else {
        // si se encuentra el estudiante se muestra su asistencia 
        Estudiante *est = pair->value;
        printf("\n");
        printf("RUT: %s, Nombre: %s, Carrera: %s\n\n", est->rut, est->nombre, est->carrera);

        for (int i = 0; i < NUM_CURSOS; i++) { // ciclo que recorre los 5 cursos 
            printf("  Curso: %s\n", cursos[i]);
            printf("  Asistencias:\n");
            for (int j = 0; j < est->num_dias[i]; j++) { // ciclo que imprime las asistencias hasta el dia actual
                printf("    Día %d: %s\n", j + 1, est->asistencias[i][j] ? "Presente" : "Ausente");
            }
            printf("\n");
        }
    } 
}

// Funcion para mostrar la asistencia de un curso en especifico
void mostrarAsistenciaPorCurso(Map *estudiantes_byRut, const char *nombre_curso) {
    // buscamos el curso en el arreglo de cursos
    int curso_index = -1;
    for (int i = 0; i < NUM_CURSOS; i++) {
        if (strcmp(cursos[i], nombre_curso) == 0) {
            curso_index = i;
            break;
        }
    }
    // si no se encuentra el curso se acaba el programa y se avisa al usuario
    if (curso_index == -1) {
        printf("\n");
        printf("Curso no encontrado.\n");
        return;
    }
    printf("\n");
    printf("Asistencia para el curso: %s\n", nombre_curso);
    printf("RUT           Nombre                Asistencias\n");
    printf("-------------------------------------------------\n");

    // recorremos el mapa de estudiantes por completo
    MapPair *pair = map_first(estudiantes_byRut);
    while (pair != NULL) { // ciclo para recorrer el mapa por completo
        Estudiante *est = pair->value;
        printf("%-13s %-20s ", est->rut, est->nombre);
        for (int j = 0; j < est->num_dias[curso_index]; j++) {
            printf("%s ", est->asistencias[curso_index][j] ? "P" : "A");
        }
        printf("\n");
        pair = map_next(estudiantes_byRut);
    }
}

int main() {
    // creamos el mapa para los estudiantes, tomando el rut como clave
    Map *estudiantes_byRut = map_create(is_equal_string);

    // variables locales para las opciones
    char rut[20], nombre_curso[50];
    int dia, presente;
    
    char opcion;
    do {
        puts("==============================================");
        puts("  Control de Asistencia Universidad PUCV 2024");
        puts("==============================================");

        puts("1) Cargar Estudiantes");
        puts("2) Marcar Asistencia");
        puts("3) Mostrar Asistencias Generales");
        puts("4) Mostrar Asistencia Por RUT");
        puts("5) Mostrar Asistencia Por Curso");
        puts("6) Salir");

        printf("Ingrese su opción: ");
        scanf(" %c", &opcion);

      switch (opcion) {
        case '1':
            printf("\n");
            cargarEstudiantes(estudiantes_byRut);
            break;

        case '2':
            printf("\n");
            printf("Ingrese el RUT del estudiante: ");
            scanf(" %19s", rut);
            printf("\n");
            MapPair *pair = map_search(estudiantes_byRut, rut);
            if (pair == NULL) {
                printf("Estudiante con RUT %s no encontrado.\n", rut);
                break;
            }

            Estudiante *est = pair->value;

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

        case '3':
            printf("\n");
            mostrarAsistencias(estudiantes_byRut);
            break;

        case '4':
            printf("\n");
            buscarAsistenciaPorRUT(estudiantes_byRut);
            break;

        case '5':
            printf("\n");
            printf("Ingrese el nombre del curso: ");
            scanf(" %49s", nombre_curso);
            mostrarAsistenciaPorCurso(estudiantes_byRut, nombre_curso);
            break;

        case '6':
            printf("Saliendo de la aplicación, su asistencia ha quedado registrada.\n");
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