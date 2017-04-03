#include <iostream.h>
#include "mpi.h"
#include "numberManager.h"
#include "structuresManager.h"

int main(int argc, char *argv[])
{
	int numprocs;
	int myid;
	vector<int>* matrix;
	vector<int>* vectorUnoXN;
	MPI_Status recv_status;
	double InitilStart, TimestartTime, FinishEndTime, endTime;
    int  namelen;
    char processorName[MPI_MAX_PROCESSOR_NAME];
	
	int row = 0;
	int column = 0;
	
	
	vector<int>* myMatrix;
	vector<int>* myMatrixResp;
	int myRowInit;
	int myRowFinish;
	
	int myPrime = 0;
	int nPrimes = 0;
	int rowMyPrime = 0;
	int columnPrime = -1;
	
	 MPI::Init(argc, argv);

	 MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
	 MPI_Comm_rank(MPI_COMM_WORLD,&myid);
	 MPI_Get_processor_name(processorName,&namelen);
	 
	if (myid == 0){
		cout << "Cuenta con " << numprocs << " procesos.\n";
		
        while (!row || 1 > row ||((row) % n) != 0 ){
			printf("Por favor, digite el numero de filas multiplo del numero de procesos:  ");
			fflush(stdout);
			scanf("%d",&row);
		}
		
		while (!column || 1 > column){
			printf("Ahora digite el numero de columnas:  ");
			fflush(stdout);
			scanf("%d",&column);
		}
		
		while (0 > columnPrime){
			printf("Ahora digite la columna especifica de la que quiere saber el numero de primos:  ");
			fflush(stdout);
			scanf("%d",&columnPrime);
		}
		
		structuresManager structManager = new structuresManager();
		
		/*hacer vector*/
		vectorUnoXN = structManager.createVector(column);
		
		/*hacer matriz*/
		matrix = structManager.createMatrix(row, column);
		
		/*Enviar matriz*/
		structManager.sendMatrix(matrix, column, numprocs);
		
		//Enviar el numero de columnas.
		MPI_Bcast(&column, 1, MPI_INT, 160, MPI_COMM_WORLD);
		
		/*Enviar vector */
		MPI_Bcast(&vectorUnoXN, column, MPI_INT, 140, MPI_COMM_WORLD);
		
		/*Enviar Fila para numero primo */
		MPI_Bcast(&columnPrime, 1, MPI_INT, 130, MPI_COMM_WORLD);
		
		startwtime = MPI_Wtime();
    }
	 /*dividir matriz*/
	 
	MPI_Barrier(MPI_COMM_WORLD);
	
	
	//Creo que no es necesario.
	MPI_Recv(&column, 1, MPI_INT, 0, 160, MPI_COMM_WORLD, &recv_status);
	
	//Creo que no es necesario.
	MPI_Recv(&vectorUnoXN, column, MPI_INT, 0, 140, MPI_COMM_WORLD, &recv_status);
	
	//Creo que no es necesario.
	MPI_Recv(&columnPrime, 1, MPI_INT, 0, 130, MPI_COMM_WORLD, &recv_status);
	
	//recibe la fila donde comienza
	MPI_Recv(&myRowInit, 1, MPI_INT, 0, 156, MPI_COMM_WORLD, &recv_status);
	
	//recibe la fila donde termina
	MPI_Recv(&myRowFinish, 1, MPI_INT, 0, 199, MPI_COMM_WORLD, &recv_status);	
	
	//recibe la columa del vector que le toca
	MPI_Recv(&rowMulti, 1, MPI_INT, 0, 171, MPI_COMM_WORLD, &recv_status);

	MPI_Recv(&myMatrix, 1, MPI_INT, 0, 150, MPI_COMM_WORLD, &recv_status);
	
	numberManager numManager = new numberManager();	 
	
	funcionMatrix funMatrix = new funcionMatrix();	
	
	myMatrixResp = new (nothrow) vector<int>;
    if(myMatrixResp == NULL){
		cout << "No fue posible reservar la memoria para el vector";
		//TODO: Cancelar el proceso.
	}
	
	for(int auxInit = myRowInit,int auxFinish = myRowFinish; auxInit < auxFinish; auxInit++){
		vector<int>* tmpMatrix;
		myPrime = myPrime + columnPrimeNumber(&myMatrix.at(myRowInit));//Funcion Prime
		rowMyPrime = rowMyPrime + especificColumnPrimeNumber(&myMatrix.at(myRowInit),columnPrime);//Funcion Prime[colum].
		tmpMatrix = product(myMatrix, int multi, int columns, int init)//Funcion product matrix[1][n] X matrix[n][m]
		matrixAddMatrix(myMatrixResp, tmpMatrix);
	}
	
	//Enviar myMatrixResp al 0 para que comience a hacer merge de resultados.
	
	 
	MPI_Barrier(MPI_COMM_WORLD);
	 
	MPI_Reduce(&myPrime, &nPrimes, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if ( rank == 0 ) {
		// Respuestas
	}
	
	
	 MPI::Finalize();
} 