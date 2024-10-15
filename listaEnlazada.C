#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOMBRE 25
#define MAX_VOTO 5

typedef struct nodo {
    char nombre[MAX_NOMBRE];
    struct nodo *sgte;
} lista;

// Funciones
void mostrar(lista *legisladores);
void insertar(const char *nombre, lista **legisladores);
void liberar(lista *legisladores);
void convertir_a_minusculas(char *cadena);
void suprimir(const char *nombre, lista **legisladores);
int es_miembro(const char *nombre, lista **legisladores);
void registrar_voto_legisladores(lista **chicosBuenos, lista **chicosMalos);
void *asignar_memoria(size_t size);

int main() {
    printf("La Sociedad para la Prevencion de Injusticias con el Atun (SPIA) cuenta con diez (10) legisladores.\n"
           "En la ultima votacion acerca de la prohibicion de la pesca de atun en el Lago Escondido termino en empate con "
           "cinco (5) a favor y cinco (5) en contra.\nEs por eso, que en el dia de hoy se realizara de nuevo.\n\n");

    lista *inicioChicosBuenos = NULL;
    lista *inicioChicosMalos = NULL;

    // Insertar nombres en las listas
    insertar("Cristina", &inicioChicosBuenos);
    insertar("Bruno", &inicioChicosBuenos);
    insertar("Alberto", &inicioChicosMalos);
    insertar("David", &inicioChicosMalos);

    printf("Chicos buenos:\n");
    mostrar(inicioChicosBuenos);
    printf("Chicos malos:\n");
    mostrar(inicioChicosMalos);
    printf("\n");

    int cantLegisladores = 4;
    for (int i = 0; i < cantLegisladores; i++) {
        registrar_voto_legisladores(&inicioChicosBuenos, &inicioChicosMalos);
    }

    printf("Luego de registrar:\n\n");
    printf("Chicos buenos:\n");
    mostrar(inicioChicosBuenos);
    printf("Chicos malos:\n");
    mostrar(inicioChicosMalos);

    // Liberar memoria
    liberar(inicioChicosBuenos);
    liberar(inicioChicosMalos);
    
    return 0;
}

void mostrar(lista *legisladores) {
    if (legisladores != NULL) {
        printf("%s\n", legisladores->nombre);
        mostrar(legisladores->sgte);
    }
}

void insertar(const char *nombre, lista **legisladores) {
    char nombre_minusculas[MAX_NOMBRE];
    strcpy(nombre_minusculas, nombre);
    convertir_a_minusculas(nombre_minusculas);
    
    lista *nuevo = (lista *)asignar_memoria(sizeof(lista));
    strcpy(nuevo->nombre, nombre_minusculas);
    nuevo->sgte = NULL;

    if (*legisladores == NULL || strcmp((*legisladores)->nombre, nombre_minusculas) > 0) {
        nuevo->sgte = *legisladores;
        *legisladores = nuevo;
    } else {
        lista *actual = *legisladores;
        while (actual->sgte != NULL && strcmp(actual->sgte->nombre, nombre_minusculas) < 0) {
            actual = actual->sgte;
        }
        nuevo->sgte = actual->sgte;
        actual->sgte = nuevo;
    }
}

void liberar(lista *legisladores) {
    while (legisladores != NULL) {
        lista *temp = legisladores;
        legisladores = legisladores->sgte;
        free(temp);
    }
}

void convertir_a_minusculas(char *cadena) {
    for (int i = 0; cadena[i] != '\0'; i++) {
        cadena[i] = tolower(cadena[i]);
    }
}

void suprimir(const char *nombre, lista **legisladores) {
    char nombre_minusculas[MAX_NOMBRE];
    strcpy(nombre_minusculas, nombre);
    convertir_a_minusculas(nombre_minusculas);

    lista *actual = *legisladores;

    if (strcmp((*legisladores)->nombre, nombre_minusculas) == 0) {
        *legisladores = actual->sgte;
        free(actual);
    } else {
        while (actual->sgte != NULL && strcmp(actual->sgte->nombre, nombre_minusculas) != 0) {
            actual = actual->sgte;
        }
        if (actual->sgte != NULL) {
            lista *tmp = actual->sgte;
            actual->sgte = tmp->sgte;
            free(tmp);
        } else {
            printf("\nEl legislador \"%s\" no se encuentra en la lista\n", nombre);
        }
    }
}

int es_miembro(const char *nombre, lista **legisladores) {
    char nombre_minusculas[MAX_NOMBRE];
    strcpy(nombre_minusculas, nombre);
    convertir_a_minusculas(nombre_minusculas);

    lista *actual = *legisladores;

    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre_minusculas) == 0) {
            return 1; // Legislador encontrado
        }
        actual = actual->sgte;
    }
    return 0;
}

void registrar_voto_legisladores(lista **chicosBuenos, lista **chicosMalos) {
    char nombre[MAX_NOMBRE];
    char voto[MAX_VOTO];

    printf("Ingrese un nombre para el legislador:\n");
    scanf("%s", nombre);
    getchar();
    convertir_a_minusculas(nombre);

    if (es_miembro(nombre, chicosBuenos) == 1) {
        do {
            printf("Inserte su voto F (favorable) o D (desfavorable):\n");
            scanf("%s", voto);
            getchar();
            if (strcmp(voto, "D") != 0 && strcmp(voto, "F") != 0) {
                printf("El voto ingresado no es valido, intente de nuevo:\n");
            }
        } while (strcmp(voto, "D") != 0 && strcmp(voto, "F") != 0);

        if (strcmp(voto, "D") == 0) {
            suprimir(nombre, chicosBuenos);
            insertar(nombre, chicosMalos);
        }
    } else if (es_miembro(nombre, chicosMalos) == 1) {
        do {
            printf("Inserte su voto F (favorable) o D (desfavorable):\n");
            scanf("%s", voto);
            getchar();
            if (strcmp(voto, "D") != 0 && strcmp(voto, "F") != 0) {
                printf("El voto ingresado no es valido, intente de nuevo:\n");
            }
        } while (strcmp(voto, "D") != 0 && strcmp(voto, "F") != 0);

        if (strcmp(voto, "F") == 0) {
            suprimir(nombre, chicosMalos);
            insertar(nombre, chicosBuenos);
        }
    } else {
        int afirmativo = 0;
        printf("\nEl nombre ingresado no es de ningun legislador, quiere ingresar uno nuevo? En caso de serlo, toque 1.\n");
        scanf("%d", &afirmativo);
        getchar();
        if (afirmativo == 1) {
            registrar_voto_legisladores(chicosBuenos, chicosMalos);
        }
    }
}

void *asignar_memoria(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: no se pudo asignar memoria.\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}
