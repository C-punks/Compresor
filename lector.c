#include "lector.h"
#include "estructuras.h"

//**********************************************************
void InicializaArreglo(ArrFrec *Arreglo)
{
	int i;

	for (i=0;i<256;i++)
	{
		Arreglo[i] = 0;
	}
}
//***********************************************************
void AnalizaFrecuencias(ArrFrec *Arreglo, int caracter)
{
	int i;

	for (i=0;i<256;i++)
	{
		if (i == caracter)
		{
			Arreglo[i]++;
		}
	}
}
//***********************************************************
void ImprimeFrecuencias(ArrFrec *Arreglo,Lista *L)
{
	int i,j,k=0;
	int nuevoarr[256];
	int aux;

	printf("\n");
	for (i=0 ; i<256 ; i++)
	{
		if(Arreglo[i] > 0)
		{
			AgregarNodo(L,i,Arreglo[i]);
			nuevoarr[k]=Arreglo[i];
			k++;
			if (i == 10)
				printf("\t\tCaracter \t[%s]\t\t- \tFrecuencia\t[%i] \n ","ENTER",Arreglo[i]);	
			else if (i==32)
				printf("\t\tCaracter \t[%s]\t\t- \tFrecuencia\t[%i] \n ","SPACE",Arreglo[i]);
			else
				printf("\t\tCaracter \t[%c]\t\t- \tFrecuencia\t[%i] \n ",i,Arreglo[i]);
		}
	}
}
//***********************************************************
void InicializaTabla(Tabla *mitabla)
{
	int i;

	for (i=0;i<256;i++)
	{
		mitabla[i].frec = 0;
		strcpy(mitabla[i].codigo,"");
	}
}
//***********************************************************
void ImprimeTabla(Tabla *mitabla)
{
	int i,j,k=0;
	//int nuevoarr[256];
	int aux;

	printf("\n");
	for (i=0 ; i<256 ; i++)
	{
		if( mitabla[i].frec > 0)
		{
			//AgregarNodo(L,i,Arreglo[i]);
			//nuevoarr[k]=Arreglo[i];
			//k++;
			if (i == 10)
				printf("\t\tCaracter \t%s\t\t- \tCod :\t%s \n ","ENTER",mitabla[i].codigo);	
			else if (i==32)
				printf("\t\tCaracter \t%s\t\t- \tCod :\t%s \n ","SPACE",mitabla[i].codigo);
			else
				printf("\t\tCaracter \t[ %c ]\t\t- \tCod :\t%s \n ",i,mitabla[i].codigo);
		}
	}
}
//****************************************************************
void AgregarNodo(Lista *L , int caracter , int frecuencia)
{
	struct nodo *nuevo;

	nuevo = (struct nodo*)malloc(sizeof(struct nodo));

	nuevo->caracter = caracter;
	nuevo->frecuencia= frecuencia;
	strcat(nuevo->cod,"");
	nuevo->hijoI=NULL;
	nuevo->hijoD=NULL;
	nuevo->ant=NULL;
	nuevo->sig=NULL;

	if (L->tam == 0)
	{
		L->inicio = nuevo;
		L->final  = nuevo;
		nuevo -> ant = NULL;
		nuevo -> sig = NULL;
	}
	if (L->tam >0 )
	{
			nuevo->ant = L->final;
			nuevo->sig = NULL;
			L->final->sig = nuevo;
			L->final = nuevo;	
	}
	
	L->tam ++;
}