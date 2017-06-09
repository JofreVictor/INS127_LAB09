/**************************************************
NOMBRE:Victor Jofre Miranda
ASIGNATURA:Estructura de Datos
PROFESOR:Tomas Lara
*************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/***FUNCIONES CONJUNTO***/

/***Recibe el conjunto a transformar.Si el valor decimal existe en el conjunto, lo reemplaza por un "1".Sino, por un "0"***/
void MostrarEnBinario(int conjunto){
	int cont;
	for (cont= pow(2,8);cont >0;cont >>=1){
		if (cont&conjunto){
			printf ("1");
		}else{
			printf ("0");
		}
	}
}

/***Inserta un valor a cualquier conjunto dado.En caso que ya exista ese valor dentro, lo mantiene***/
int InsertarNum(int conjunto, int num){
	printf ("Se insertara el numero: %i\n",num);
	if (((conjunto>>num)%2)==0){
		conjunto=+1<<num;
		return conjunto;
	}
	else{
		return conjunto;
	}
}

/***MENU***/

void main(){
    /***Insertando valores del conjunto en su tabla correspondiente.1=ESTA---0=NO ESTA***/

	int tablaA=(1<<4)+(1<<5)+(1<<2)+(1<<8)+(1<<7);
	int tablaB=(1<<0)+(1<<1)+(1<<3)+(1<<4)+(1<<5);

	/***INVOCANDO FUNCIONES***/

	/***Imprime Conjunto A con decimal y binario***/
	printf("Conjunto A = {4,5,2,8,7}\n");
	printf("Conjunto A en binario: ");
	MostrarEnBinario(tablaA);

	/***Imprime Conjunto B con decimal y binario***/
	printf("\n\nConjunto B = {0,1,3,4,5}\n");
	printf("Conjunto B en binario: ");
	MostrarEnBinario(tablaB);

	/***Interseccion entre Conjunto A y B***/
	printf("\n\nConjunto A and B: ");
	int AandB = tablaA & tablaB;
	MostrarEnBinario(AandB);

	/***Union entre Conjunto A y B***/
	int AorB = tablaA | tablaB;
	printf("\n\nConjunto A or B: ");
	MostrarEnBinario(AorB);

	/***Diferencia simetrica MODIFICADA del Conjunto A y B***/
	printf("\n\nConjunto (A - B)U(B + A): ");
	int tablaC = ((tablaA & (~tablaB)) | (tablaA & tablaB));
	MostrarEnBinario(tablaC);
	printf("\n\n");

	/***Insertando valores en el Conjunto A***/
	tablaA=InsertarNum(tablaA,1);
    printf("En el conjunto A\n");
	tablaA=InsertarNum(tablaA,2);
	printf("En el conjunto A\n");
	printf("El conjunto A, con sus nuevos valores es: ");
	MostrarEnBinario(tablaA);
	printf("\n\n");

	/***Insertando valores en el Conjunto B***/
	tablaB=InsertarNum(tablaB,4);
	printf ("En el conjunto B\n");
	tablaB=InsertarNum(tablaB,5);
	printf("En el conjunto B\n");
	printf("El conjunto B, con sus nuevos valores es: ");
	MostrarEnBinario(tablaB);
	printf("\n\n");

	/***Nueva Interseccion entre Conjunto A y B***/
	int InterNueva = tablaA & tablaB;
	printf("La interseccion de los nuevos conjuntos A-B es: ");
	MostrarEnBinario(InterNueva);
	printf("\n");

	/***Nueva Union entre Conjunto A y B***/
	int UnionNueva = tablaA | tablaB;
	printf("La union de los nuevos conjuntos A-B es: ");
	MostrarEnBinario(UnionNueva);
	printf("\n\n");
}
