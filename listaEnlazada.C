#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//para las mayusculas
/* agregar funcion para convertir nombre a minusculas, crear el char y el strcpy o meterlo todo a la funcion convertir a minusculas.
   mejorar comparacion con operadores hacer que las listas sean tipo globales y no llamarlas siempre como argumentos. */

typedef struct nodo {
    char nombre[50];
    struct nodo *sgte;
} lista;

void mostrar(lista *legisladores);
void insertar(char nombre[], lista ** legisladores);
void liberar(lista *legisladores);
void convertir_a_minusculas(char *cadena);
void suprimir(char nombre[], lista **legisladores);
int es_miembro(char nombre[], lista **legisladores);
void registrar_voto_legisladores(lista **chicosBuenos, lista **chicosMalos);

int main() {
    printf("La Sociedad para la Prevencion de Injusticias con el Atun (SPIA) cuenta con diez (10) legisladores.\n"
           "En la ultima votacion acerca de la prohibicion de la pesca de atun en el Lago Escondido termino en empate con cinco (5) a favor y cinco (5) en contra.\n"
           "Es por eso, que en el dia de hoy se realizara de nuevo.\n\n");
           
    lista *inicioChicosBuenos = NULL;
    lista *inicioChicosMalos = NULL;

    // Insertar nombres en las listas
    insertar("cristina", &inicioChicosBuenos);
    insertar("bruno", &inicioChicosBuenos);
    insertar("ALBERTO", &inicioChicosMalos);
    insertar("david", &inicioChicosMalos);

    printf("chicos buenos:\n");
    mostrar(inicioChicosBuenos);
    printf("chicos malos:\n");
    mostrar(inicioChicosMalos);

    // Verificar si se encuentra en la lista
    if (es_miembro("Cristina", &inicioChicosBuenos)) {
        printf("\nCristina es un miembro de los chicos buenos.\n");
    } else {
        printf("Cristina no es un miembro de los chicos buenos.\n");
    }

    if (es_miembro("alberto", &inicioChicosMalos)) {
        printf("alberto es un miembro de los chicos malos.\n");
    } else {
        printf("alberto no es un miembro de los chicos malos.\n");
    }

    if (es_miembro("bruno", &inicioChicosBuenos)) {
        printf("bruno es un miembro de los chicos buenos.\n");
    } else {
        printf("bruno no es un miembro de los chicos buenos.\n");
    }

    if (es_miembro("david", &inicioChicosMalos)) {
        printf("david es un miembro de los chicos malos.\n");
    } else {
        printf("david no es un miembro de los chicos malos.\n");
    }

    // Realizar eliminaciones
    suprimir("alberto", &inicioChicosMalos);
    suprimir("pedro", &inicioChicosBuenos);
    suprimir("juan", &inicioChicosMalos);
    suprimir("cristina", &inicioChicosBuenos);

    printf("\nya con los legisladores eliminados:\n");
    printf("chicos buenos:\n");
    mostrar(inicioChicosBuenos);
    printf("chicos malos:\n");
    mostrar(inicioChicosMalos);

    registrar_voto_legisladores(&inicioChicosBuenos, &inicioChicosMalos);

    printf("luego de registrar:\n\n");
    printf("chicos buenos:\n");
    mostrar(inicioChicosBuenos);
    printf("chicos malos:\n");
    mostrar(inicioChicosMalos);

    // Liberar memoria
    liberar(inicioChicosBuenos);
    liberar(inicioChicosMalos);
    
    return 0;
}

void mostrar(lista *legisladores) //es bien generica para que cuando vos le pases el argumento que quieras solo muestre lo que contiene dentro.
{
    if (legisladores != NULL) {
        printf("%s\n", legisladores->nombre);
        mostrar(legisladores->sgte);
    }
}

void insertar(char nombre[], lista ** legisladores) //para insertar los nombres.
{
    char nombre_minusculas[50];
    strcpy(nombre_minusculas, nombre); //hago la copia del nombre, lo reemplazo en el resto que diga nombre
    convertir_a_minusculas(nombre_minusculas); // Convertir a minúsculas por si alguno pone todo en mayusculas.

    lista *nuevo = (lista *)malloc(sizeof(lista)); //asignando el tamaño de el primer nodo.
    strcpy(nuevo->nombre, nombre_minusculas);
    nuevo->sgte = NULL; //lo inicializa en null siempre

    if (*legisladores == NULL || strcmp((*legisladores)->nombre, nombre_minusculas) > 0) //en el caso de que la lista este vacia o el dato que ingresas (en este caso un nombre) es menor a 0 (menor a otro nombre ya inicializado)
    {
        nuevo->sgte = *legisladores; //como nuevo->sgte estaba en null, ahora lo apunto a legisladores (el valor previamente inicializado)
        *legisladores = nuevo; // hago que la lista arranque en este valor nuevo q ingrese.
    } else // al no darse que no es nulo y que el dato que ingresas no es menor a 0 (su resta con el otro nombre) entra aca, quiere decir q va en el medio.
    {
        lista *actual = *legisladores; //nodo auxiliar.
        while (actual->sgte != NULL && strcmp(actual->sgte->nombre, nombre_minusculas) < 0) //aca tiene q pasar que actual->sgte sea disinto de null y que el nombre que previamente ingresaste menos el q ingreaste ahora sea menor q 0
        {
            actual = actual->sgte;
        } //en caso que no se cumpla el while.
        nuevo->sgte = actual->sgte; // Inserta en la posición correcta
        actual->sgte = nuevo; // lo ordena para no perder el enlace.
    }
}

void liberar(lista *legisladores) //para liberar espacio en la memoria.
{
    while (legisladores != NULL) {
        lista *temp = legisladores; //auxiliar para guardar el nodo completo.
        legisladores = legisladores->sgte; //para que pase al siguiente nodo de legisladores, cambio el puntero. Y el nodo previo queda listo para borrar, no pierdo el enlace a la referencia del siguiente.
        free(temp); //ya teniendo el siguiente apuntado, libero el previo con temp.
    }
}

void convertir_a_minusculas(char *cadena) //en caso que ingrese un nombre en mayusculas, lo convierte a minusculas.
{
    int i = 0;
    while (cadena[i] != '\0') //para las condiciones siempre comillas simples ''
    {
        cadena[i] = tolower(cadena[i]); //tolower pasa las mayusculas a minusculas, toupper al reves.
        i++;
    }
    cadena[i] = '\0'; // asegurarse de que la cadena esté bien terminada
}

void suprimir(char nombre[], lista **legisladores) {
    char nombre_minusculas[50];
    strcpy(nombre_minusculas, nombre); // hago la copia del nombre
    convertir_a_minusculas(nombre_minusculas); // Convertir a minúsculas

    lista *actual = *legisladores;
    if (strcmp((*legisladores)->nombre, nombre_minusculas) == 0) {
        // Si el nodo a eliminar es el primero
        *legisladores = actual->sgte; // actualiza el inicio de la lista
        free(actual); // libera el nodo
    } else {
        while (actual->sgte != NULL && strcmp(actual->sgte->nombre, nombre_minusculas) != 0) {
            actual = actual->sgte; // busca el nodo a eliminar
        }
        if (actual->sgte != NULL) { // Si se encontró el nodo a eliminar
            lista *tmp = actual->sgte; // guarda el nodo a eliminar
            actual->sgte = tmp->sgte; // actualiza el puntero del nodo anterior
            free(tmp); // libera el nodo
        } else {
            // Mensaje si no se encuentra el legislador
            printf("\nEl legislador \"%s\" no se encuentra en la lista\n", nombre);
        }
    }
}

int es_miembro(char nombre[], lista **legisladores) //recibirá nombre del legislador y el conjunto que corresponda, retornando verdadero/falso si esta presente o no.
{
    char nombre_minusculas[50];
    strcpy(nombre_minusculas, nombre); //hago la copia del nombre, lo reemplazo en el resto que diga nombre
    convertir_a_minusculas(nombre_minusculas); // Convertir a minúsculas por si alguno pone todo en mayusculas.

    lista *actual = *legisladores;
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre_minusculas) == 0) //compara dos cadenas de caracteres.
        {
            return 1; // Legislador encontrado
        }
        actual = actual->sgte; // Avanzar al siguiente nodo
    }
    return 0;
}

void registrar_voto_legisladores(lista **chicosBuenos, lista **chicosMalos) {
    char nombre[50];
    char voto[5];

    printf("ingrese un nombre para el legislador:\n");
    //fgets(nombre , sizeof(nombre) , stdin); //como un scanf, sirve si tenes un nombre compuesto no corta cuando pones el espacio.
    scanf("%s", nombre);
    getchar();
    convertir_a_minusculas(nombre); // Convertir a minúsculas

    if (es_miembro(nombre, chicosBuenos) == 1) {
        printf("Inserte su voto F (favorable) o D (desfavorable):\n");
        scanf("%s", voto);
        if (strcmp(voto, "D") == 0) {
            suprimir(nombre, chicosBuenos);
            insertar(nombre, chicosMalos);
        }
    } else if (es_miembro(nombre, chicosMalos) == 1) {
        printf("Inserte su voto F (favorable) o D (desfavorable):\n");
        scanf("%s", voto);
        if (strcmp(voto, "F") == 0) {
            suprimir(nombre, chicosMalos);
            insertar(nombre, chicosBuenos);
        }
    } else {
        printf("el nombre ingresado no es de ningun legislador.");
    }
}
