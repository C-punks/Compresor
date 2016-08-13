#include "huffman.h"
#include "lector.h"

int main(int argc , char *argv[])
{
	FILE *archivo,*salida;
	int i;
	int doc;
	Lista *Lfrecuecnia;
	Tabla Ascii[256];
	ArrFrec frec[256];

	Lfrecuecnia = CreaLista();

	InicializaArreglo(frec);
	InicializaTabla(Ascii);

	if (argc != 3 )
	{
		printf("use : %s  <archivo_entrada.txt> <archivo_salida.txt> \n",argv[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		archivo = fopen (argv[1],"r");
		printf("\n\n\t\t");
		if (archivo == NULL ) 
		{
			printf("\n El documento no existe !!");
		}
		else
		{
			while (!feof(archivo))
			{
				doc = fgetc(archivo);
				AnalizaFrecuencias(frec,doc);
				if (!feof(archivo))
				{
				printf("%c",doc);
				}
			}
		
		}
		printf("\n\t\t***************Lista desordenada*****************\n");
		ImprimeFrecuencias(frec,Lfrecuecnia);
		
		
		OrdenarLista(Lfrecuecnia);
		printf("\n\t\t***************Lista ordenada -[Frecuencia]******************\n");
		ImprimeLista(Lfrecuecnia);
		
		ArmarArbol(Lfrecuecnia);
		printf("\n\t\t----- tam de lista = %d y frec = %d \n",Lfrecuecnia->tam,Lfrecuecnia->inicio->frecuencia);

		printf("\n\t\t -_-_-_-_-_-_-   Arbol recorrido  -_-_-_-_-_-_- \n\n\n");
		RecorreArbol(Lfrecuecnia->inicio,Ascii);

		printf("\n\t\t -_-_-_-_-_-_-   Tabla de codigos  -_-_-_-_-_-_- \n\n\n");
		ImprimeTabla(Ascii);
		
		salida = fopen(argv[2],"wb");
		
		fseek(archivo,0,SEEK_SET);
		EscribirArbol(Lfrecuecnia->inicio,salida);
		fseek(salida,0,SEEK_END);
		fputc(' ',salida);
		
		EscribeCodificacionCaracter(Ascii, archivo,salida);

		fclose(archivo);
		fclose(salida);
		return 0;
		}
}
