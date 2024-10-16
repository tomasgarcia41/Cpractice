#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOMBRE 25
#define MAX_VOTO 5

// Estructura de nodo para la lista enlazada
typedef struct nodo {
    char nombre[MAX_NOMBRE]; // Nombre del legislador
    struct nodo *sgte; // Puntero al siguiente nodo
} Lista;

// Funciones
void mostrar(Lista *legisladores);
void insertar(const char *nombre, Lista **legisladores);
void liberar(Lista *legisladores);
void convertir_a_minusculas(char *cadena);
void suprimir(const char *nombre, Lista **legisladores);
void registrar_voto_legisladores(Lista **chicos_buenos, Lista **chicos_malos);
void *asignar_memoria(size_t size);
int es_miembro(const char *nombre, Lista **legisladores);

int main() {
    printf("/////////////////////////////////////////\n");

    // Inicialización de listas para legisladores
    Lista *inicio_chicos_buenos = NULL;
    Lista *inicio_chicos_malos = NULL;

    char nombre[MAX_NOMBRE]; // Buffer para el nombre del legislador
    char voto[MAX_VOTO]; // Buffer para el voto del legislador

    int cont = 1; // Contador para el número de legisladores ingresados
    // Bucle para insertar nombres y votos
    while (cont > 0) {
        printf("Ingrese el nombre de un legislador ('E' para salir):\n");
        scanf("%s", nombre);
        if (strcmp(nombre, "E") == 0) {
            break; // Salir del bucle si se ingresa 'E'
        }
        printf("Inserte su voto F (favorable) o D (desfavorable):\n");
        scanf("%s", voto);

        // Insertar el legislador en la lista correspondiente según el voto
        if (strcmp(voto, "F") == 0) {
            insertar(nombre, &inicio_chicos_buenos);
        } else if (strcmp(voto, "D") == 0) {
            insertar(nombre, &inicio_chicos_malos);
        }

        cont++; // Incrementar contador
    }

    // Mostrar resultados de la votación
    printf("Luego de la votación, los resultados fueron:\n\n");
    printf("Chicos buenos:\n\n");
    mostrar(inicio_chicos_buenos);
    printf("Chicos malos:\n\n");
    mostrar(inicio_chicos_malos);

    int respuesta = 0; // Variable para controlar si se desea volver a votar
    printf("¿Quiere volver a votar? (responda con '1' para votar): ");
    scanf("%d", &respuesta);
    getchar(); // Limpiar el buffer

    // Bucle para registrar nuevos votos
    while (respuesta == 1) {
        for (int i = 1; i < cont; i++) {
            registrar_voto_legisladores(&inicio_chicos_buenos, &inicio_chicos_malos);
        }
        respuesta = 0; // Reiniciar respuesta para salir del bucle
    }

    // Mostrar resultados finales de la votación
    printf("Luego de la votación, los resultados fueron:\n\n");
    printf("Chicos buenos:\n\n");
    mostrar(inicio_chicos_buenos);
    printf("Chicos malos:\n\n");
    mostrar(inicio_chicos_malos);

    // Liberar memoria asignada a las listas
    liberar(inicio_chicos_buenos);
    liberar(inicio_chicos_malos);

    return 0; // Finalizar programa
}

// Función para mostrar la lista de legisladores
void mostrar(Lista *legisladores) {
    if (legisladores != NULL) {
        printf("%s\n", legisladores->nombre); // Imprimir el nombre del legislador
        mostrar(legisladores->sgte); // Llamada recursiva para el siguiente legislador
    }
}

// Función para insertar un nuevo legislador en la lista
void insertar(const char *nombre, Lista **legisladores) {
    char nombre_minusculas[MAX_NOMBRE];
    strcpy(nombre_minusculas, nombre);
    convertir_a_minusculas(nombre_minusculas); // Convertir el nombre a minúsculas

    // Asignar memoria para el nuevo nodo
    Lista *nuevo = (Lista *)asignar_memoria(sizeof(Lista));
    strcpy(nuevo->nombre, nombre_minusculas); // Copiar nombre al nuevo nodo
    nuevo->sgte = NULL; // Inicializar puntero al siguiente nodo

    // Insertar en la lista en orden alfabético
    if (*legisladores == NULL || strcmp((*legisladores)->nombre, nombre_minusculas) > 0) {
        nuevo->sgte = *legisladores;
        *legisladores = nuevo; // Nuevo nodo se convierte en el inicio de la lista
    } else {
        Lista *actual = *legisladores;
        while (actual->sgte != NULL && strcmp(actual->sgte->nombre, nombre_minusculas) < 0) {
            actual = actual->sgte; // Buscar la posición adecuada para insertar
        }
        nuevo->sgte = actual->sgte;
        actual->sgte = nuevo; // Insertar el nuevo nodo en la lista
    }
}

// Función para liberar la memoria asignada a la lista
void liberar(Lista *legisladores) {
    while (legisladores != NULL) {
        Lista *temp = legisladores; // Almacenar el nodo actual
        legisladores = legisladores->sgte; // Avanzar al siguiente nodo
        free(temp); // Liberar la memoria del nodo actual
    }
}

// Función para convertir una cadena a minúsculas
void convertir_a_minusculas(char *cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        cadena[i] = tolower(cadena[i]); // Convertir cada carácter a minúscula
    }
}

// Función para suprimir un legislador de la lista
void suprimir(const char *nombre, Lista **legisladores) {
    char nombre_minusculas[MAX_NOMBRE];
    strcpy(nombre_minusculas, nombre);
    convertir_a_minusculas(nombre_minusculas); // Convertir el nombre a minúsculas

    Lista *actual = *legisladores;

    // Si el legislador a eliminar es el primero en la lista
    if (strcmp((*legisladores)->nombre, nombre_minusculas) == 0) {
        *legisladores = actual->sgte; // Actualizar el inicio de la lista
        free(actual); // Liberar memoria
    } else {
        // Buscar el legislador en la lista
        while (actual->sgte != NULL && strcmp(actual->sgte->nombre, nombre_minusculas) != 0) {
            actual = actual->sgte;
        }
        // Si se encontró el legislador
        if (actual->sgte != NULL) {
            Lista *tmp = actual->sgte;
            actual->sgte = tmp->sgte; // Actualizar puntero para eliminar el nodo
            free(tmp); // Liberar memoria
        } else {
            printf("\nEl legislador \"%s\" no se encuentra en la lista\n", nombre);
        }
    }
}

// Función para verificar si un legislador es miembro de la lista
int es_miembro(const char *nombre, Lista **legisladores) {
    char nombre_minusculas[MAX_NOMBRE];
    strcpy(nombre_minusculas, nombre);
    convertir_a_minusculas(nombre_minusculas); // Convertir el nombre a minúsculas

    Lista *actual = *legisladores;

    // Recorrer la lista para buscar el legislador
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre_minusculas) == 0) {
            return 1; // Legislador encontrado
        }
        actual = actual->sgte; // Avanzar al siguiente nodo
    }
    return 0; // Legislador no encontrado
}

// Función para registrar un nuevo voto para un legislador
void registrar_voto_legisladores(Lista **chicos_buenos, Lista **chicos_malos) {
    char nombre[MAX_NOMBRE];
    char voto[MAX_VOTO];

    printf("Ingrese un nombre para el legislador:\n");
    scanf("%s", nombre);
    getchar(); // Limpiar el buffer
    convertir_a_minusculas(nombre); // Convertir el nombre a minúsculas

    // Comprobar si el legislador es miembro de la lista de chicos buenos
    if (es_miembro(nombre, chicos_buenos) == 1) {
        do {
            printf("Inserte su voto F (favorable) o D (desfavorable):\n");
            scanf("%s", voto);
            getchar(); // Limpiar el buffer
            // Validar el voto ingresado
            if (strcmp(voto, "D") != 0 && strcmp(voto, "F") != 0) {
                printf("El voto ingresado no es válido, intente de nuevo:\n");
            }
        } while (strcmp(voto, "D") != 0 && strcmp(voto, "F") != 0);

        // Si el voto es desfavorable, mover al legislador de chicos buenos a chicos malos
        if (strcmp(voto, "D") == 0) {
            suprimir(nombre, chicos_buenos);
            insertar
