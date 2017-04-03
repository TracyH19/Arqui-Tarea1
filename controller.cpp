#include <iostream>

#include "mpi.h"
#include "numberManager.h"
#include "structuresManager.h"
#include "funcionMatrix.h"
#include "filesManager.h"

int main(int argc, char *argv[])
{
    double startFullTime;
	double endFullTime;
	double startPartTime;
	double endPartTime;

	vector<int>* matrix;
	vector<int>* vec;
	vector<int>* P;
	vector<int>* Q;

	MPI_Status status;

    char processorName[MPI_MAX_PROCESSOR_NAME];
    int myMPI;
    int myID;
    int namelen;
    int numprocs = 10;

    int n;
    int m;
    int PM;

    structuresManager sm;
    filesManager fm;
    numberManager nm;
    funcionMatrix funcM;


    /**
	int row = 0;
	int column = 0;
	int myRowInit;
	int myRowFinish;
	int myPrime = 0;
	int nPrimes = 0;
	int rowMyPrime = 0;
	int columnPrime = -1;
	*/

	myMPI = MPI_Init(&argc, &argv);

    myMPI = MPI_Comm_rank(MPI_COMM_WORLD, &myID);

    myMPI = MPI_Comm_size(MPI_COMM_WORLD, &numprocs);

    myMPI = MPI_Get_processor_name(processorName,&namelen);

    cout << "El proceso " << myID << " se encuentra en " << processorName << endl;

    myMPI = MPI_Barrier(MPI_COMM_WORLD);

	if (myID == 0){
		cout << "Se tienen " << numprocs << " procesos." << endl;

        while (!n || 1 > n ||((n) % numprocs) != 0 ){
			cout << "Digite el numero de entradas para el vector" << endl;
			cout << "Debe ser multiplo de: " << numprocs << endl;
			cin >> n;
		}

		while (!m){
            cout << "Digite la cantidad de columnas para la matriz:" << endl;
			cin >> m;
		}

		/*hacer vector*/
		vec = sm.createVector(n);

		/*hacer matriz*/
		matrix = sm.createMatrix(n, m);


		myMPI = MPI_Bcast(&vec, 1, MPI_INT, 0, MPI_COMM_WORLD);

		int inicio = 0;

		for(int i = 0; i < numprocs; i++){

            MPI_Send(matrix->at(inicio), m, MPI_INT, i, 1, MPI_COMM_WORLD);
            inicio = inicio + m;
		}

        myMPI = MPI_Barrier(MPI_COMM_WORLD);

		for(int j = 0; j < numprocs; j++){
            myMPI = MPI_Recv(&resp, m, MPI_INT, j, 2, MPI_COMM_WORLD, &status);

            Q->at(j) = resp->at(0);
		}

		int num;

		while(num != 1 || num != 2){
            cout << "Si desea almacenar los resultados en archivos, digite 1 " << endl;
            cout << "Si desea que los resultados se muestren en pantalla, digite 2 " << endl;
            cin >> num;
        }

		if(num == 1){
            char* vect = "vector.txt";
	    int col = 0;
            fm.createFile(vect, *vec, n, col);

            char* mat = "matriz.txt";
            fm.createFile(mat, *matrix, n, m);

            char* nom_P = "vector_P.bin";
            fm.createBinFile(nom_P, *P, n, col);

            char* nom_Q = "vector_Q.bin";
            fm.createBinFile(nom_Q, *Q, n, col);

		}else{
		    cout << "El vector original es: " << endl;
		    sm.printVector(vec);

		    cout << "La matriz original es " << endl;
            sm.printMatrix(matrix, m);

            cout << "El vector Q es: " << endl;
            sm.printVector(Q);

            cout << "El vector P es: " << endl;;
            sm.printVector(P);

            cout << "La cantidad de primos en la matriz es: ";
            cout << PM << endl;
		}


	}

	if(myID > 0){
        myMPI = MPI_Recv(&matrix, m, MPI_INT, 0, 1, MPI_COMM_WORLD);

        for(vector<int>::const_iterator i = matrix->begin(); i != matrix->end(); i++){

            vector<int>* resp = new (nothrow) vector<int>;
            resp = nm.product(*matrix, vec->at(myID));

            int n = matrix->at(i);
            if(nm.isPrime(n)){
                PM++;
                int a = P->at(myID);
                a++;
                P->at(myID) = a;
            }
        }

        myMPI = MPI_Send(&resp, m, MPI_INT, 0, 2, MPI_COMM_WORLD);
	}

	MPI_Finalize();

	return 0;
}
