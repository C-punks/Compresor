#include "huffman.h"
#include "estructuras.h"

Lista *CreaLista()
{
	Lista *nueva;
	nueva = (Lista*)malloc(sizeof(Lista));
	nueva -> inicio = NULL;
	nueva -> final  = NULL;
	nueva -> tam =0;

	return nueva;
}
//****************************************************************

//****************************************************************
void ImprimeLista(Lista *L)
{
	struct nodo *aux;

	aux = L->inicio;
	
	printf("\n");
	while (aux != NULL)
	{	
		if (aux->caracter == 10 )
			printf("\t\tcaracter :\t%s\tFrecuencia :\t[%d]\n","[ENTER]",aux->frecuencia);

		else if (aux->caracter == 32 )
			printf("\t\tcaracter :\t%s\tFrecuencia :\t[%d]\n","[SPACE]",aux->frecuencia);
		else
			printf("\t\tcaracter :\t[%c]\tFrecuencia :\t[%d]\n",aux->caracter,aux->frecuencia);
		
		aux = aux->sig;
	}

}
//****************************************************************
void OrdenarLista(Lista *L)
{
	int i;
	struct nodo *aux,*aux2;
	int car , frec;

	for (i=0 ;i < (L->tam) ;i++){

		aux = L->inicio;
		
		while (aux != L->final )
		{
			if((aux->frecuencia) > (aux->sig->frecuencia) )
			{	

				car  = aux->caracter;
				frec = aux ->frecuencia;
				aux->caracter  =aux->sig->caracter ;
				aux->frecuencia=aux->sig->frecuencia;
				aux->sig->caracter = car;
				aux->sig->frecuencia = frec;	 
			}
			aux = aux->sig;
		}
		
	}
}
//****************************************************************
void ArmarArbol(Lista *L)
{
	struct nodo* ultimo;
	ultimo =(struct nodo*)malloc(sizeof(struct nodo));

	int i;
	i=L->tam;
	
	
	while (i>2)
	{
		SumarNodos(L);
		//printf("-%d-",i);
		ImprimeLista(L);
		i--;
	}
	
	//printf("-%d-",i);
	ultimo -> caracter = 92;
	ultimo -> frecuencia = L->inicio->frecuencia + L->final->frecuencia;
	ultimo -> sig = NULL;
	ultimo -> ant = NULL;
	ultimo ->hijoI = L->inicio;
	ultimo ->hijoD = L->final;


	strcat(ultimo->hijoI -> cod,"0");
	strcat(ultimo->hijoD -> cod,"1");

	L->inicio->sig = NULL;
	L->inicio = ultimo;
	L->final ->ant = NULL;
	L->final  = ultimo;
	L->tam --;
	//printf("%d",L->tam);
}
//****************************************************************
void SumarNodos(Lista *L)
{
	struct nodo* aux1,*aux2;
	struct nodo* nuevo;

	nuevo = (struct nodo*)malloc(sizeof(struct nodo));
	aux1 = L->inicio;
	aux2 = aux1->sig;
	
	printf("\n");

	L->inicio = aux2->sig;
	L->inicio->ant = NULL;
	
	aux1->sig = NULL;
	aux1->ant = NULL;
	aux2->ant = NULL;
	aux2->sig = NULL;

	strcat(aux1 -> cod,"0");

	strcat(aux2 -> cod,"1");
	nuevo->caracter = 92;
	nuevo->frecuencia = aux1->frecuencia + aux2->frecuencia;
	nuevo->hijoI = aux1;
	nuevo->hijoD = aux2;
	nuevo->sig =NULL;
	nuevo->ant = NULL;
	
	EnlazaArbol(L,nuevo);
	
	//printf("\n");
	
}
//****************************************************************
void EnlazaArbol(Lista *L,struct nodo* arbol)
{

	struct nodo *aux;

	aux = L->inicio;
	
	printf("\t\tFrecuencia de %d + %d = %d ---- ",arbol->hijoI->frecuencia,arbol->hijoD->frecuencia, arbol->frecuencia);
	
	while (aux->frecuencia < arbol->frecuencia && aux->sig != NULL)
	{
		aux = aux->sig;
	}
	printf("aux->frec => %d  <====> L->tam = %d  \n",aux->frecuencia,L->tam);
	
	if ( aux->ant != NULL && L->tam > 3 && aux->sig != NULL)
	{
			arbol -> sig = aux;
			arbol -> ant = aux->ant;
			aux ->ant->sig = arbol;
			aux ->ant  = arbol;
	}
	
	if ( aux->ant == NULL && L->tam >3)
	{
		arbol->sig = aux;
		arbol->ant =NULL;
		aux->ant = arbol;
		L->inicio = arbol;
	}
	
	if(aux->sig ==  NULL && aux->frecuencia < arbol->frecuencia )
	{
		arbol -> ant = aux;
		arbol->sig = NULL;
		aux -> sig = arbol;
		L->final = arbol;
	}
	if(aux->sig ==  NULL && aux->frecuencia >= arbol->frecuencia )
	{
		arbol -> sig = aux;
		arbol -> ant = aux->ant;
		aux ->ant->sig = arbol;
		aux ->ant  = arbol;
	}

	L->tam--;
}
//****************************************************************
void RecorreArbol(struct nodo *arbol,Tabla *mitabla)
{
	char saux[20];
	
	if (arbol == NULL) return;
	
	
	if(arbol->hijoI !=NULL)
	{
		strcpy(saux,"");
		strcat(saux,arbol->cod);
		strcat(saux,arbol->hijoI->cod);
		strcpy(arbol->hijoI->cod,saux);
	}
	if(arbol->hijoD !=NULL){
		strcpy(saux,"");
		strcat(saux,arbol->cod);
		strcat(saux,arbol->hijoD->cod);
		strcpy(arbol->hijoD->cod,saux);
	}
	
	if(arbol->hijoD == NULL && arbol->hijoI == NULL)
	{
		strcpy(mitabla[arbol->caracter].codigo,arbol->cod);
		mitabla[arbol->caracter].frec = arbol->frecuencia;
	}
	ImprimeCaracter(arbol);
	RecorreArbol(arbol->hijoI,mitabla);
	RecorreArbol(arbol->hijoD,mitabla);

}
//****************************************************************
void ImprimeCaracter(struct nodo* arbol)
{	
	
	if (arbol->caracter == 10)
	printf("\t\tValor [%s]\t-\tFrec [%d]\t\t\tcod :%s  \n","ENTER",arbol->frecuencia,arbol->cod);
	else if (arbol->caracter == 32)
	printf("\t\tValor [%s]\t-\tFrec [%d]\t\t\tcod :%s  \n","SPACE",arbol->frecuencia,arbol->cod);
	else
	printf("\t\tValor [%c]\t-\tFrec [%d]\t\t\tcod :%s  \n",arbol->caracter,arbol->frecuencia,arbol->cod);
}
void EscribeCodificacionCaracter(Tabla *Ascii ,FILE *original,FILE *salida)
{
	int i,largo;
	int pos_bit = 8;
	int byte;
	int doc;
	int c;

	int contador ,inicio;
	
	memset(&byte,0,1);

	
	while (!feof(original))
	{
		doc = fgetc(original);
		largo = strlen(Ascii[doc].codigo);
		
		
		for (i = (largo-1); i >= 0 ;i--)
		{
			pos_bit--;
			if (pos_bit >= 0)
			{
				if(Ascii[doc].codigo[largo-1-i] == '1')
				{
					byte |= 1 << pos_bit;
				}
			}else
			{
				fputc(byte,salida);
				
				//printf("\n--> %d",byte);
				
				pos_bit = 7;

				memset(&byte,0,1);

				if (Ascii[doc].codigo[largo-1-i] == '1')
				{
					byte |= 1 << pos_bit;
				}
			} 

		}
	}
	
}
//****************************************************************
void EscribirArbol(struct nodo * arbol, FILE *Salida)
{
	if (arbol == NULL) return;

	fputc(arbol->caracter,Salida);
	EscribirArbol(arbol->hijoI,Salida);
	EscribirArbol(arbol->hijoD,Salida);
}
