#include "filesManager.h"

filesManager::filesManager()
{
    //ctor
}

filesManager::~filesManager()
{
    //dtor
}

/**
 *  Método encargado de crear un archivo de texto (.txt) y almacenar un vector o una matriz en el mismo.
 *  Recibe el nombre del archivo a crear, el vector a guardar, y la cantidad de filas y columnas.
 *  Para almacenar un vector, el valor m que corresponde a las columnas se pasa como 0
 *  No retorna valores.
 */

void filesManager::createFile(char* name, vector<int>& vec, int& n, int& m){
    fstream archivo;
    archivo.open(name, ios::out);

    if(archivo.is_open()){

        if(m == 0){

            for(vector<int>::const_iterator i = vec.begin(); i != vec.end(); i++){
                archivo << *i << " ";
            }

        }else{
            int cont = 0;

            for(vector<int>::const_iterator i = vec.begin(); i != vec.end(); i++){
                archivo << *i << " ";
                cont ++;

                if(cont == m){
                    archivo << "\n";
                    cont = 0;
                }
            }
        }
        archivo.close();
    }
}

/**
 *  Método encargado de crear un archivo binario(.bin) y almacenar un vector o una matriz en el mismo.
 *  Recibe el nombre del archivo a crear, el vector a guardar, y la cantidad de filas y columnas.
 *  Para almacenar un vector, el valor m que corresponde a las columnas se pasa como 0
 *  No retorna valores.
 */

void filesManager::createBinFile(char* name, vector<int>& vec, int& n, int& m){
    fstream archivo;
    archivo.open(name,ios::binary|ios::out);

    if(archivo.is_open()){
        if(m == 0){

            for(vector<int>::const_iterator i = vec.begin(); i != vec.end(); i++){
                archivo << *i << " ";
            }

        }else{
            int cont = 0;

            for(vector<int>::const_iterator i = vec.begin(); i != vec.end(); i++){
                archivo << *i << " ";
                cont ++;

                if(cont == m){
                    archivo << "\n";
                    cont = 0;
                }
            }
        }
        archivo.close();
    }
}

