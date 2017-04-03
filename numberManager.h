#ifndef numberManager_h
#define numberManager_h

#include <math.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

class numberManager
{
    public:
        numberManager();
        virtual ~numberManager();

        vector<int>* product(vector<int>* vec&, int multi);
        int sumVector(vector<int>* vec, int columns, int init);
        int columnPrimeNumber(vector<int>* vec,  int columns, int init);

        int especificColumnPrimeNumber(vector<int>* vec, int column);
		bool isPrime(int n);	
    protected:

    private:
        

};

#endif // numberManager_h
