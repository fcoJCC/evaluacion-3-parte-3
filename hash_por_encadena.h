#ifndef STDIO_H
#include <stdio.h>
#define STDIO_H
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#define STDLIB_H
#endif

#ifndef STRING_H
#include <string.h>
#define STRING_H
#endif

#ifndef TIME_H
#include <time.h>
#define TIME_H
#endif

#define m 5 //sera el mod del codigo y tamaño de nuestro arreglo

typedef long int KEY;

typedef struct registro
{
    KEY rut; // agregar nombre y apellidos
    int region,mes,parte,edad;
    char sexo[15];
    char nacion[20];
    char calidad[15];
    char e_civil[15];

}Registro;

typedef struct nodo
{
    Registro datos;
    struct nodo *sig_dato;
}Nodo;

int hash(KEY aux_rut)
{
    return (aux_rut%m);
}

Nodo *iniciar_nodo(long aux_rut, int aux_region, int aux_mes, int aux_parte, int aux_edad, char aux_sexo[15], char aux_nacion[20], char aux_calidad[15], char aux_e_civil[15]){
	Nodo *aux=(Nodo*)malloc(sizeof(struct nodo));
	aux->datos.rut=aux_rut;
    aux->datos.region=aux_region;
	aux->datos.parte=aux_parte;
	aux->datos.mes=aux_mes;
	aux->datos.edad=aux_edad;
	strcpy(aux->datos.sexo, aux_sexo);
	strcpy(aux->datos.nacion, aux_nacion);
	strcpy(aux->datos.calidad, aux_calidad);
	strcpy(aux->datos.e_civil, aux_e_civil);
	aux->sig_dato=NULL;
	return aux;
}

void iniciar_nodos_tabla(Nodo *aux_tabla[m]){
    int i = 0;
    while( i < m ){
        aux_tabla[i]=iniciar_nodo(0,0,0,0,0,"0","0","0","0");
        i++;
    }

}


void ingresar_datos_a_tabla(Nodo *aux_tabla[m])
{
    FILE *fp=fopen("datos_detenidos.csv", "r");

    long int key_rut;
    int region;
    int mes;
    int parte;
    int edad;
    char sexo[15];
    char nacion[20];
    char calidad[15];
    char e_civil[15];
    clock_t start = clock();

    while(!feof(fp)){
        fscanf(fp, "%d;", &region);
        fscanf(fp, "%d;", &mes);
        fscanf(fp, "%d;", &parte);
        fscanf(fp, "%[^;];", &sexo);
        fscanf(fp, "%d;", &edad);
        fscanf(fp, "%[^;];", &e_civil);
        fscanf(fp, "%[^\n];", &nacion);
        fscanf(fp, "%[^\n];", &calidad);
        fscanf(fp, "%ld;", &key_rut);

        if(aux_tabla[hash(key_rut)]->datos.rut==0){
            aux_tabla[hash(key_rut)]=iniciar_nodo(key_rut, region, mes, parte, edad, sexo, nacion, calidad, e_civil);
        }
        else
        {
            Nodo *aux=aux_tabla[hash(key_rut)]->sig_dato;
            aux_tabla[hash(key_rut)]->sig_dato=iniciar_nodo(key_rut, region, mes, parte, edad, sexo, nacion, calidad, e_civil);
            aux_tabla[hash(key_rut)]->sig_dato->sig_dato
            =aux;

        }
    }    printf("tiempo de suceso: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);

    fclose(fp);

}
    Nodo *buscar_datos_en_tabla(Nodo * aux_tabla[m], int indice_hash, long key_rut){
    Nodo *recorrido=aux_tabla[indice_hash];
    clock_t start = clock();
    while(recorrido!=NULL)
    {
        if(recorrido->datos.rut==key_rut)
            {
            printf("Tiempo transcurrido de Búsqueda: %f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
            return(recorrido);
        }
        recorrido=recorrido->sig_dato;
    }
    return(NULL);

}
