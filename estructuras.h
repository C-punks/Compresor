#ifndef  _ESTRUCTURAS_H_
#define _ESTRUCTURAS_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


typedef int ArrFrec;

typedef struct 
{
	int frec;
	char codigo[12];
}Tabla;

struct nodo{
	int caracter;
	int frecuencia;
	char  cod[15];
	struct nodo *ant;
	struct nodo *sig;
	struct nodo *hijoI;
	struct nodo *hijoD; 
};

typedef struct 
{
	struct nodo * inicio;
	struct nodo * final;
	int tam;		
}Lista;




#endif