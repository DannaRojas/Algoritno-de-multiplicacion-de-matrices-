/**************************************************************************************
 * Fecha: 11 Septiembre de 2025
 * Autor: Danna Gabriela Rojas Bernal 
 * Materia: Sistemas Operativos
 * Tema: Concurrencia
 * Objetivo: Hacer una metodología para la implementación de la multiplicación de matrices.
 * La idea principal, es construir paso a paso la implementación para hacer uso de la
 * biblioteca PTHREAD. Se implementa el Algoritmo Clásico de multiplicación de matrices, para
 * matrices cuadradas, es decir, la dimensión de filas es igual a la de columnas.
 * A continuación se describen los paso
 *  - Reserva de memoria
 *      - Creación de punteros para matrices del tipo doble
 *      - Asignación de memoria
 *      - Ingreso de argumentos de entrada (Dimensión matriz, número de hilos)
 *      - Validación argumentos de entrada
 *      - Inicializar las matrices
 *      - Imprimir las matrices
 *      - Función para inicializar las matrices
 *      - Función para imprimir las matrices
 *      - Algoritmo clásico de multiplicación matrices
 *  - Se verifica el resultado
 *      - Función para multiplicación las matrices
 *      - Declaración vector de hilos
 *      - Creación de hilos según tamaño de vector de hilos
 *      - Crear estructura de datos que encapsule los argumentos de entrada de la función MM
 * Implementación de paralelismo: resolución de la multiplicación de matrices
 *  - Se crea el vector de hilos
 *  - Se tiene pendiente la exclusión de los hilos
 *  - Se pasa a globales las matrices
 *  - Encapsular los datos para enviarlos a la función MxM
 *  - Se desencapsulan los datos dentro de la función MxM (descomprimen)
*************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "modulo.h"


//metodo principal 
int main(int argc, char *argv[]) {

    if(argc < 2){
        printf("Numero argumentos incorrectos\n");
        printf("\n\t $ejecutable DIM \n");
        return -1;
    }

    int n = atoi(argv[1]);
    if(n <= 0){
        printf("\n Valores deben ser mayor que cero\n");
        return -1;
    }

    // Reservar memoria dinamica para matrices
    mA = (double *) malloc(n*n*sizeof(double));
    mB = (double *) malloc(n*n*sizeof(double));
    mC = (double *) malloc(n*n*sizeof(double));
    // Verificar memoria
    if(!mA || !mB || !mC){
        printf("Error al reservar memoria\n");
        return -1;
    }

    // Inicializar matrices
    iniMatriz(n, mA, mB);

    // Imprimir matrices A y B
    // printf("\nMatriz A:\n");
    // imprMatrices(n, mA);
    // printf("\nMatriz B:\n");
    // imprMatrices(n, mB);

    InicioMuestra();
    printf("\nTiempo en microsegundos: \n");
    // Multiplicación clásica
    multiMatrixClasica(mA, mB, n);
    FinMuestra();
    
    // Imprimir resultado
    // printf("\nMatriz C (resultado):\n");
    // imprMatrices(n, mC);

    printf("\n\tFin del programa.............!\n");
    // Liberar memoria
    free(mA);
    free(mB);
    free(mC);
    return 0;
}
