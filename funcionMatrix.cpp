#include "funcionMatrix.h"

using namespace funcionMatrix;
using namespace std;



funcionMatrix()
{
    //ctor
}

~funcionMatrix()
{
    //dtor
}

void matrixAddMatrix(vector<int>* matrix, vector<int>* tmpMatrix){
	for(vector<int>::const_iterator i = tmpMatrix->begin(); i != tmpMatrix->end(); i++){
		matrix->push_back( *i );
	}
}

