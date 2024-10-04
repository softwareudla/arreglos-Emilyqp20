#include <stdio.h>
#include <string.h>

#define NUM_ESTUDIANTES 5
#define NUM_ASIGNATURAS 3
#define NOTA_APROBACION 6
#define MAX_NOMBRE 50

int main() {
    float notas[NUM_ESTUDIANTES][NUM_ASIGNATURAS];
    float sumaEstudiante, sumaMateria[NUM_ASIGNATURAS] = {0};
    float promedioEstudiante[NUM_ESTUDIANTES], promedioMateria[NUM_ASIGNATURAS];
    float maxNotaEstudiante, minNotaEstudiante, maxNotaMateria[NUM_ASIGNATURAS], minNotaMateria[NUM_ASIGNATURAS];
    int aprobados[NUM_ASIGNATURAS] = {0}, reprobados[NUM_ASIGNATURAS] = {0};
    char nombres[NUM_ESTUDIANTES][MAX_NOMBRE];
    char asignaturas[NUM_ASIGNATURAS][MAX_NOMBRE];

    // El usuario ingresa los nombres de cada asignatura
    for (int j = 0; j < NUM_ASIGNATURAS; j++) {
        printf("Ingrese el nombre de la asignatura %d: ", j + 1);
        scanf("%s", asignaturas[j]);
    }

    // Notas mínimas y máximas para cada materia
    for (int i = 0; i < NUM_ASIGNATURAS; i++) {
        maxNotaMateria[i] = 0;
        minNotaMateria[i] = 10;
    }

    // Ingreso de los nombres de cada estudiante y sus respectivas notas por asignatura
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        printf("Ingrese el nombre del estudiante %d: ", i + 1);
        getchar(); 
        fgets(nombres[i], MAX_NOMBRE, stdin);
        nombres[i][strcspn(nombres[i], "\n")] = 0; 
        
        printf("Estudiante: %s\n", nombres[i]);
        for (int j = 0; j < NUM_ASIGNATURAS; j++) {
            do {
                printf("Ingrese la nota para %s (0-10): ", asignaturas[j]);
                scanf("%f", &notas[i][j]);
                if (notas[i][j] < 0 || notas[i][j] > 10) {
                    printf("Nota no válida. Intente nuevamente.\n");
                }
            } while (notas[i][j] < 0 || notas[i][j] > 10);
            
            // Sumatoria de las notas para calcular promedios de materia
            sumaMateria[j] += notas[i][j];

            // Aprobados y reprobados por materia
            if (notas[i][j] >= NOTA_APROBACION) {
                aprobados[j]++;
            } else {
                reprobados[j]++;
            }

            // Actualizar la nota máxima y mínima por materia
            if (notas[i][j] > maxNotaMateria[j]) maxNotaMateria[j] = notas[i][j];
            if (notas[i][j] < minNotaMateria[j]) minNotaMateria[j] = notas[i][j];
        }
    }

    // Calcular promedios, máximos y mínimos por estudiante
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        sumaEstudiante = 0;
        maxNotaEstudiante = 0;
        minNotaEstudiante = 10;

        for (int j = 0; j < NUM_ASIGNATURAS; j++) {
            sumaEstudiante += notas[i][j];
            if (notas[i][j] > maxNotaEstudiante) maxNotaEstudiante = notas[i][j];
            if (notas[i][j] < minNotaEstudiante) minNotaEstudiante = notas[i][j];
        }

        promedioEstudiante[i] = sumaEstudiante / NUM_ASIGNATURAS;
        printf("\nEstudiante: %s - Promedio: %.2f, Nota mas alta: %.2f, Nota mas baja: %.2f\n", 
                nombres[i], promedioEstudiante[i], maxNotaEstudiante, minNotaEstudiante);
    }

    // Calcular promedios por materia
    for (int j = 0; j < NUM_ASIGNATURAS; j++) {
        promedioMateria[j] = sumaMateria[j] / NUM_ESTUDIANTES;
        printf("\nAsignatura: %s - Promedio: %.2f, Nota mas alta: %.2f, Nota mas baja: %.2f", 
                asignaturas[j], promedioMateria[j], maxNotaMateria[j], minNotaMateria[j]);
        printf("\nEstudiantes aprobados: %d, Reprobados: %d\n", aprobados[j], reprobados[j]);
    }

    return 0;
}
