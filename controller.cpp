#include <iostream.h>
#include "mpi.h"
#include "numberManager.h"
#include "structuresManager.h"

int main(int argc, char *argv[])
{
	int primos = 0;
	int numprocs;
	
	double startTime, endTime;
    char processorName[MPI_MAX_PROCESSOR_NAME];
	
 MPI::Init(argc, argv);

 MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
 
 int rank = MPI::COMM_WORLD.Get_rank();
 int npes = MPI::COMM_WORLD.Get_size();
 if ( rank == 0 ) {
 cout << "Running on "<< npes << " Processes "<< endl;
 }
 cout << "Greetings from process " << rank << endl;

 MPI::Finalize();
} 