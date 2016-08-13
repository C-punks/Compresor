#include "estructuras.h"

#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_

Lista *CreaLista();


void ImprimeLista(Lista *);
void OrdenarLista(Lista *);

void SumarNodos(Lista *);
void EnlazaArbol(Lista *,struct nodo* );
void ArmarArbol(Lista *);
void RecorreArbol(struct nodo *,Tabla*);
void ImprimeCaracter(struct nodo* );

void EscribirArbol(struct nodo * ,FILE *);
void EscribeCodificacionCaracter(Tabla* ,FILE *, FILE *);

#endif