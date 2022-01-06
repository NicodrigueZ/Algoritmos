#include <stdio.h>
#include <stdlib.h>
#define tam 12

void IngresarDatos(float,int,float*);
void MostrarDatos(float*);

int Menu();

int main() {
	
	int Opcion;
	float Monto,MontoV[tam];
	int Cuotas;
	
	Opcion=Menu();
	
	while(Opcion!=3){
		switch(Opcion){
			case 1:
				printf("Ingrese Monto \n");
				scanf("%f", &Monto);
				fflush(stdin);
				printf("Ingrese Cantidad de Cuotas \n");
				scanf("%i", &Cuotas);
				fflush(stdin);
				IngresarDatos(Monto,Cuotas,MontoV);
				
				break;
			case 2:
				MostrarDatos(MontoV);
				break;
		}
	
	Opcion=Menu();
	
	}
	
	
	
}

int Menu(){
	
	int Opcion;
	printf("1-Ingresar Monto de ventas y Registrar Cuotas. \n 2-Mostrar Cobranza en Cuotas. \n 3-Salir. \n");
	scanf("%i", &Opcion);
	fflush(stdin);
	return Opcion;	
}

void IngresarDatos(float Monto,int Cuotas, float *MontoV){
	float Total=0;
	int i=0;
	Total=Monto/Cuotas;
	for(i;i<Cuotas;i++){
		*(MontoV+i)+=Total;
		printf("Total a Pagar es: %f mes: %i \n", *(MontoV+i),i);
	
	}
	
}

void MostrarDatos(float *MontoV){
	int k=0;
	int mesMenorCobranza=0;
	float montoMinimo=0;
	int flag=0;
	for(k;k<12;k++){
		if(flag==0){
			mesMenorCobranza=k;
			montoMinimo=*(MontoV+k);
			flag=1;
		}
		else if(*(MontoV+k)<montoMinimo){
			mesMenorCobranza= k;
			montoMinimo= *(MontoV+k);	
		}	
	}
	printf("El mes de menor cobranza fue %i \n", mesMenorCobranza);
	printf("Con un monto de %f \n", montoMinimo);
}
