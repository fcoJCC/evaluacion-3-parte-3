#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif

#ifndef HASH_POR_ENCADENAMIENTO_H
#include "hash_por_encadena.h"
#define HASH_POR_ENCADENAMIENTO_H
#endif


int main(){
    Nodo *tabla[m];
    iniciar_nodos_tabla(tabla);

    ingresar_datos_a_tabla(tabla);

    int in_rut;
    printf("ingresa el rut:\n");
    scanf("%ld", &in_rut);


    Nodo* encuentra=buscar_datos_en_tabla(tabla, hash(in_rut), in_rut);
    if(encuentra!=NULL){
        printf("\n\n Detenido Registrado:\n\n");
        printf("Calidad: %s \n",encuentra->datos.calidad);
        printf("Mes de captura: %d \n",encuentra->datos.mes);
        printf("Numero de parte: %d \n ",encuentra->datos.parte);
        printf("Rut: %ld \n", encuentra->datos.rut);
        printf("Sexo: %s \n", encuentra->datos.sexo);
        printf("Nacion de origen: %s \n", encuentra->datos.nacion);
        printf("Estado civil: %s \n", encuentra->datos.e_civil);
    }else
        printf("\n\nEl detenido no se encuentra en nuestra base de datos...\n");


    return 0;
}
