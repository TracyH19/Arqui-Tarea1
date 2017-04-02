#include "structuresManager.h"

structuresManager::structuresManager()
{
    //ctor
}

structuresManager::~structuresManager()
{
    //dtor
}

/**
 *  Metodo para crear un vector con valores elegidos aleatoriamente entre 0 - 9.
 *  Recibe un n para determinar su largo.
 *  Retorna el vector creado
 */

vector<int>* structuresManager::createVector(int n){
    vector<int>* vec = new (nothrow) vector<int>;
    if(vec == NULL){
        cout << "No fue posible reservar la memoria para el vector";
    }else{
			//srand(time(NULL));
			/*
			 *  Le quite la raiz porque si se deja, cada vez que se crea
			 *  un vector y una matriz nuevos, los primeros n valores de
			 *  la matriz me salieron iguales a los del vector.
			 */

        for(int i = 0; i < n; i++){
            vec->push_back(rand() % 10);
        }
    }

    return vec;
}

/**
 *  Metodo para crear una matriz con valores elegidos aleatoriamente entre 0 - 9.
 *  Recibe un n para determinar su cantidad de filas.
 *  Recibe un m para determinar su cantidad de columnas.
 *  Retorna la matriz creada
 */

vector<int>* structuresManager::createMatrix(int n, int m){
    vector<int>* matrix = new (nothrow) vector<int>;

    if(matrix == NULL){
        cout << "No fue posible reservar la memoria para la matriz";
    }else{
        srand(time(NULL));
        int a = n * m;

        for(int i = 0; i < a; i++){
            matrix->push_back(rand() % 10);
        }
    }

    return matrix;
}

/**
 *  Metodo para imprimir en consola un vector
 *  Recibe el vector a imprimir por parametro
 *  No realiza modificaciones.
 *  No retorna datos.
 */

void structuresManager::printVector(vector<int>* vec){

    for(vector<int>::const_iterator i = vec->begin(); i != vec->end(); i++){
        cout << *i << " ";
    }
    cout << "\n" << "\n";
}

/**
 *  Metodo para imprimir en consola una matriz
 *  Recibe la matriz a imprimir por parametro
 *  No realiza modificaciones.
 *  No retorna datos.
 */

void structuresManager::printMatrix(vector<int>* matrix, int m){
    int cont = 0;

    for(vector<int>::const_iterator i = matrix->begin(); i != matrix->end(); i++){
        cout << *i << " ";
        cont ++;

        if(cont == m){
            cout << "\n";
            cont = 0;
        }
    }
}


/*
	rows: numero de filas
	columns: numero de columnas
*/
void structuresManager::sendMatrix(vector<int>* matrix, int columns, int rows, int proc){
	int i = 0;
	int j = 0;
	int space = rows / proc;
	
	while(i<columns){
		vector<int>* vec = new (nothrow) vector<int>;
		sendVector(matrix, space, place, proc );
	}
}

/*
	matrix:matriz de vectores
	space: numero de filas que le tocaron
	place:fila donde comienza.
	proc:numero de proceso
*/
void structuresManager::sendVector(vector<int>* matrix, int space, int place, int proc){
	int finish = place+space;
	MPI_Send(&place, 1, MPI_INT, proc, 156, MPI_COMM_WORLD);
	MPI_Send(&finish, 1, MPI_INT, proc, 199, MPI_COMM_WORLD);	
	MPI_Send(&space, 1, MPI_INT, proc, 171, MPI_COMM_WORLD);	
	MPI_Send(matrix + place, space, MPI_INT, proc, 0, MPI_COMM_WORLD);	
}

