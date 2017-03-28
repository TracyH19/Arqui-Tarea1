#ifndef numberManager_h
#define numberManager_h

#include<math.h>
#include<vector>
#include<stdlib.h>
#include<time.h>

namespace numberManager
{
	class numberManager
	{
		private:
			bool isPrime(int n);
			
			
		public:
			
			vector<int> product(vector<int>& vec, int multi, int tam);
			int sumVector(vector<int>& vec, int tam);
			int sumVectorProduct(vector<int>& vec, int multi, int tam, int m);
			int columnPrimeNumber(vector<int>& vec, int tam);
			vector<int> getColumn(int min,int max, int tam)
	}
}



#endif // numberManager_h