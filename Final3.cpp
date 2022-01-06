#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void IngresarDatos(int, int,float, float,int*,int*,float*,float*);
void MostrarDatos(int*,int*,float*,float*);
int Menu();

int main(){
	int NumeroDepto,VecinosProblematicos,NumeroDeptoV[50],VecinosProblematicosV[50];
	float Expensa,Multa,MontoExpensaAdeudadaV[50],MontoMultasAdeudadasV[50];
	int Opciones,i=0;
	
	Opciones=Menu();
	
	while(Opciones!=3){
		switch(Opciones){
			case 1:
				printf("Numero de Departamento \n");
				scanf("%i", &NumeroDepto);
				printf("Cantidad de Vecinos con el que el Propietario tiene problemas. \n");
				scanf("%i", &VecinosProblematicos);
				printf("Monto de Multas adeudadas. \n");
				scanf("%f", &Multa);
				printf("Monto de Expensa adeudada. \n");
				scanf("%f", &Expensa);
				IngresarDatos(NumeroDepto,VecinosProblematicos,Multa,Expensa,NumeroDeptoV,VecinosProblematicosV,MontoExpensaAdeudadaV, MontoMultasAdeudadasV);	
				break;
				
			case 2:
				MostrarDatos(NumeroDeptoV,VecinosProblematicosV,MontoExpensaAdeudadaV, MontoMultasAdeudadasV);
				break;
			case 3:
				printf("Usted se ha salido del programa.");
				break;
		}
		Opciones=Menu();
	}
	
}

int Menu(){
	int Opcion;
	printf(" 1-Ingreso de datos de cada departamento.\n 2-Evaluacion de los departamentos del edificio.\n 3-Salir. \n");
	scanf("%i", &Opcion);
	system("cls");
	fflush(stdin);
	return Opcion;
}
void IngresarDatos(int NumeroDepto,int VecinosProblematicos,float Multa,float Expensa,int *NumeroDeptoV,int *VecinosProblematicosV,float *MontoExpensaAdeudadaV,float *MontoMultasAdeudadasV){
      int i=0;
    for(i;i<50;i++){
	*(NumeroDeptoV+i)=NumeroDepto;
	*(VecinosProblematicosV+i)=VecinosProblematicos;
	*(MontoMultasAdeudadasV+i)=Multa;
	*(MontoExpensaAdeudadaV+i)=Expensa;
	}
}

void MostrarDatos(int *NumeroDeptoV, int *VecinosProblematicosV, float *MontoExpensaAdeudadaV , float *MontoMultasAdeudadasV){
	int j=0,flag=0;
	float AcumMultas=0,MultaMayor=0,Promedio=0;
	int MayorCantVecinos=0,CountDepto=0,MayorDepto=0;
	AcumMultas+=*(MontoMultasAdeudadasV+j);
	for(j;j<50;j++){
		if(flag==0){
			MultaMayor=*(MontoMultasAdeudadasV+j);
			MayorCantVecinos=*(VecinosProblematicosV+j);
			MayorDepto=*(NumeroDeptoV+j);
			flag=1;
		}
		else if( *(MontoMultasAdeudadasV+j)>MultaMayor && *(VecinosProblematicosV+j) > MayorCantVecinos){
			MultaMayor= *(MontoMultasAdeudadasV+j);
			MayorCantVecinos= *(VecinosProblematicosV+j);
			MayorDepto=*(NumeroDeptoV+j);
		}
			
	}
	CountDepto++;
	Promedio= *(MontoExpensaAdeudadaV+j) / CountDepto;
	

	printf("El total de Monto de Multas Acumuladas es %2.f \n", AcumMultas);
	printf("Promedio de Expensa es  %2.f \n", Promedio);
	printf("El departamento mas problematico es %i \n", MayorDepto);
	
}
