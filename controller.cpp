#include <iostream.h>
#include "mpi.h"
#include "numberManager.h"
#include "structuresManager.h"

int main(int argc, char *argv[])
{
	int myPrime = 0;
	int nPrimes = 0;
	int numprocs;
	int myid;
	int row = 0;
	int column = 0;
	MPI_Status recv_status;
	vector<int>* myMatrix;
	
	vector<int>* matrix;
	vector<int>* vectorUnoXN;
	vector<int>* myMatrixResp;
	int myRowInit;
	int myRowFinish;
	
	double startTime, endTime;
    int  namelen;
    char processorName[MPI_MAX_PROCESSOR_NAME];
	
	 MPI::Init(argc, argv);

	 MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
	 MPI_Comm_rank(MPI_COMM_WORLD,&myid);
	 MPI_Get_processor_name(processorName,&namelen);
	 
	 if (myid == 0){
		cout << "Cuenta con " << numprocs << " procesos.\n";
        while (!row || 1 > row ||((row) % n) != 0 ){
			printf("Por favor, digite el numero de filas par:  ");
			fflush(stdout);
			scanf("%d",&row);
		}
		while (!column || 1 > column || ((column) % n) != 0 ){
			printf("Ahora digite el numero de columnas:  ");
			fflush(stdout);
			scanf("%d",&column);
		}
		structuresManager structManager = new structuresManager();
		
		/*hacer vector*/
		vectorUnoXN = structManager.createVector(column);
		
		/*hacer matriz*/
		matrix = structManager.createMatrix(row, column);
		
		/*Enviar matriz*/
		structManager.sendMatrix(matrix, column, numprocs);
		
		/*Enviar vector */
		MPI_Bcast(&vectorUnoXN, column, MPI_INT, 0, MPI_COMM_WORLD);
		
		startwtime = MPI_Wtime();
    }
	 /*dividir matriz*/
	 
	MPI_Barrier(MPI_COMM_WORLD);
	
	//Se enviar el numero de columnas.
	MPI_Bcast(&column, 1, MPI_INT, 160, MPI_COMM_WORLD);
	//Creo que no es necesario.
	// MPI_Recv (&vectorUnoXN, column, MPI_INT, 0, 160, MPI_COMM_WORLD, &recv_status);
	
	//recibe la fila donde comienza
	MPI_Recv(&myRowInit, 1, MPI_INT, 0, 156, MPI_COMM_WORLD, &recv_status);
	
	//recibe la fila donde termina
	MPI_Recv(&myRowFinish, 1, MPI_INT, 0, 199, MPI_COMM_WORLD, &recv_status);	
	
	//recibe la columa del vector que le toca
	MPI_Recv(&rowMulti, 1, MPI_INT, 0, 171, MPI_COMM_WORLD, &recv_status);	
	
	
	numberManager numManager = new numberManager();	 
	
	for(int auxInit = myRowInit,int auxFinish = myRowFinish; auxInit < auxFinish; auxInit++){
		myPrime = myPrime + columnPrimeNumber(&myMatrix.at(myRowInit));//TODO: verificar esto.
	}
	
	
	
	 
	MPI_Barrier(MPI_COMM_WORLD);
	 
	MPI_Reduce(&myPrime, &nPrimes, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if ( rank == 0 ) {
		//Proceso de pedir como quiere la respuesta.
		
	}
	
	 MPI::Finalize();
} 