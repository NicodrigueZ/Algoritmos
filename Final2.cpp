#include <stdio.h>
#include <stdlib.h>
#define tam 2

int Menu();
void IngresarDatos(int,float,char,int*,float*,char*);
void MostrarDatos(int*,float*,char*);

int main(){
	int opcion;
	int CodigoArticulo,CodigoArticuloV[tam], i=0;
	float PrecioArticulo,PrecioArticuloV[tam];
	char TipoArticulo,TipoArticuloV[tam];
	
	opcion=Menu();
	
	while(opcion!=3){
		switch(opcion){
			case 1:
				printf("Codigo Articulo\n");
				scanf("%i", &CodigoArticulo);
				printf("Tipo Articulo A-Algodon C-Curitas\n");
				scanf(" %c", &TipoArticulo);
				printf("Importe de la Compra \n");
				scanf("%f", &PrecioArticulo);
				 IngresarDatos(CodigoArticulo, PrecioArticulo,TipoArticulo,CodigoArticuloV ,PrecioArticuloV,TipoArticuloV);
				i++;
				break;
			case 2:
				MostrarDatos(CodigoArticuloV,PrecioArticuloV,TipoArticuloV);
				break;
		}

	opcion=Menu();

	}
	
	
}

int Menu(){
	int Opcion;
	printf("\n 1 - Ingresar Datos de la venta.\n 2 - Generar informes del día.\n 3 - Salir.\n");
	scanf("%i", &Opcion);
	fflush(stdin);
	return Opcion;
}
void IngresarDatos(int CodigoArticulo,float PrecioArticulo,char TipoArticulo,int *CodigoArticuloV ,float *PrecioArticuloV,char *TipoArticuloV){
	*(CodigoArticuloV+i)=CodigoArticulo;
	*(PrecioArticuloV+i)=PrecioArticulo;
	*(TipoArticuloV+i)=TipoArticulo;

}
void MostrarDatos(int *CodigoArticuloV,float *PrecioArticuloV,char *TipoArticuloV){
	int i=0,ContC=0,ContA=0;
	float AcumTotal,AcumC=0;
	
	for(i;i<tam;i++){
		if( *(TipoArticuloV+i)='A' ){
			ContA++;
		}
		else if(*(TipoArticuloV+i)='C'){
			ContC++;
			AcumC= AcumC + *(PrecioArticuloV+i);
		}
		AcumTotal+= *(PrecioArticuloV+i);
	}


	printf("La Cantidad de Clientes en A es %i\n", ContA);
	printf("La Cantidad de Clientes en C es %i\n",ContC);
	printf("Total Facturado en Curitas es %f\n", AcumC);
	printf("Total Facturado es %f\n", AcumTotal);
}