#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
	
	//Se declaran las variables
	int numtrab, sexo, contmenvc = 0, contfem = 0, contmascent = 0, edad;
	double pormenvc, porfem, pormascent;

	//Limpiamos pantalla
	system("cls");

	cout<<"**Estadisticas de Trabajadores**\n"<<endl;

	//Pedimos la cantidad de trabajadores
	cout<<"Cuantos trabajadores hay? ";
	cin>>numtrab;

	//Declaramos el arreglo
	int trabajador[numtrab][2];

	//Leemos los datos que necesitamos
	for(int i = 0;i < numtrab;i++){
		for (int x = 0;x < 2;x++){
			if(x==0){
				cout<<"Cual es la edad del trabajador #"<<i+1<<endl;
				cin>>trabajador[i][x];
			}else if(x==1){
				cout<<"Cual es el sexo del trabajador #"<<i+1<<"Masculino = 1 Femenino = 2"<<endl;
				cin>>sexo;
				if(sexo==1||sexo==2){
					trabajador[i][x] = sexo;
				}else{
					cout<<"ERROR\n"<<endl;
					break;
				}
			}
		}
	}

	//Hacemos el analisis de datos
	for(int i = 0;i < numtrab;i++){
		for (int x = 0;x < 2;x++){
			if(x==0){
				if(trabajador[i][x] < 25){
					contmenvc++;
					edad = trabajador[i][x];
				}
			}else if(x == 1){
				if(trabajador[i][x] == 2){
					contfem++;
					sexo = trabajador[i][x];
				}
			}

			if((edad>18 && edad<25) && sexo==1){
				contmascent++;
			}
		}
	}

	//Calculamos porcentajes con regla de 3
	pormenvc = (contmenvc * 100) / numtrab;
	porfem = (contfem * 100) / numtrab;
	pormascent = (contmascent * 100) / numtrab;

	//E imprimimos
	cout<<"Porcentaje de conductores menores a 25 anios:                 "<<pormenvc<<"%"<<endl;
	cout<<"Porcentaje de conductores del genero femenino:                "<<porfem<<"%"<<endl;
	cout<<"Porcentaje de conductores masculinos entre los 18 y 25 anios: "<<pormenvc<<"%"<<endl;

	return 0;
}