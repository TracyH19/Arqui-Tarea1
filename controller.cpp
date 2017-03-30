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
		MPI_Bcast (&vectorUnoXN, column, MPI_INT, 0, MPI_COMM_WORLD);
		
		startwtime = MPI_Wtime();
    }
	 /*dividir matriz*/
	 
	MPI_Barrier(MPI_COMM_WORLD);
	
	MPI_Bcast(&column, 1, MPI_INT, 15, MPI_COMM_WORLD); 
	
	numberManager numManager = new numberManager();	 
	 
	 MPI_Barrier(MPI_COMM_WORLD);
	 
	MPI_Reduce(&myPrime, &nPrimes, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	if ( rank == 0 ) {
		//Proceso de pedir como quiere la respuesta.
		
	}
	
	 MPI::Finalize();
} 