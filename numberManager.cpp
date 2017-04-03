#include "numberManager.h"

numberManager::numberManager()
{
    //ctor
}

numberManager::~numberManager()
{
    //dtor
}


/**
 *  Metodo que recive como parametro un numero y determina si es primo o no.
 *  Retorna true si es primo, caso contrario, false.
 */
bool numberManager::isPrime(int n){
	bool resp = false;
	if(n>2){
		int tam = static_cast<int>(floor(sqrt(n))+1);
		for(int div = 3; div <= tam; div++){
			if(n % div == 0){
				resp = true;
				break;
			}
		}
	}
	else{
		if(n > 0){
			resp = true;
		}
	}
	return resp;
}


/**
 *  Metodo que multiplica una fila por un valor.
 *  Recibe un tam para determinar su largo, la columna(de la matriz) vec a multiplicar y el valor multi(del vector).
 *  Retorna el vector creado de dicho producto
 */
vector<int>* numberManager::product(vector<int>* vec, int multi&){
    vector<int>* resp = new (nothrow) vector<int>;
    if(resp == NULL){
        cout << "No fue posible reservar la memoria para el vector" << endl;
    }else{

        for(vector<int>::const_iterator i = vec.begin(); i != vec.end(); i ++){
			resp->push_back(*i * multi);
		}
	}
    return resp;
}


/**
 *  Metodo que suma los valores de un vector.
 *  Recibe un vector vec y y su tamaño.
 *  Retorna la sumatoria del vector
 * 	No estoy seguro de que sea necesario
 */
int numberManager::sumVector(vector<int>* vec, int columns, int init){
	int resp = 0;

    vector<int>::const_iterator i = vec->begin();
    advance(i, init);

    vector<int>::const_iterator j = vec->begin();
    advance(j, columns);

    while(i != j){
        i++;
        resp = resp + *i;
    }

	//for(vector<int>::const_iterator i = vec->at(init); i != vec->end() && i < columns ; i++){
	//	resp = resp + *i;
	//}
	return resp;
}


/**
 *  Metodo que suma los valores de un vector.
 *  Recibe un vector vec y y su tamaño.
 *  Retorna la sumatoria del vector
 */
int numberManager::columnPrimeNumber(vector<int>* vec,  int columns, int init){
	int resp = 0;

	vector<int>::const_iterator i = vec->begin();
    advance(i, init);

    vector<int>::const_iterator j = vec->begin();
    advance(j, columns);

    while(i != j){
        i++;

        if(isPrime(*i)){
            resp++;
        }
    }

	//for(vector<int>::const_iterator i = vec.at(init); i != vec->end() && i < columns ; i++){
	//	if(isPrime(  *i )){
	//		resp = resp + 1;
	//	}
	//}
	return resp;
}

int numberManager::especificColumnPrimeNumber(vector<int>* vec, int column){
	int resp = 0;
	if(isPrime(vec->at(column))){
		resp = 1;
	}
	return resp;
}


