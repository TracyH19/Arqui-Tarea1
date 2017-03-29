#ifndef STRUCTURESMANAGER_H
#define STRUCTURESMANAGER_H

#include <iostream>
#include <new>  //Para memoria dinamica
#include <stdlib.h>
#include <vector>
#include <time.h>

using namespace std;

class structuresManager
{
    public:
        structuresManager();
        virtual ~structuresManager();

        vector<int>* createVector(int n);
        vector<int>* createMatrix(int n, int m);
        void printVector(vector<int>* vec);
        void printMatrix(vector<int>* matrix, int m);

    protected:
    private:
};

#endif // STRUCTURESMANAGER_H
