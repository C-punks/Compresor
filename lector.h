#include "estructuras.h"

#ifndef  _LECTOR_H_
#define  _LECTOR_H_

void InicializaArreglo(ArrFrec*);
void InicializaTabla(Tabla *mitabla);
void AnalizaFrecuencias(ArrFrec* , int );
void ImprimeFrecuencias(ArrFrec*,Lista *);
void ImprimeTabla(Tabla *mitabla);
void AgregarNodo(Lista*, int, int);

#endif