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
		public:
			numberManager();
			virtual ~numberManager();
			
			vector<int>* product(vector<int>* vec, int multi, int tam);
			int sumVector(vector<int>* vec, int tam);
			int columnPrimeNumber(vector<int>* vec);
		
		protected:
		
		private:
			bool isPrime(int n);
		
	}
}



#endif // numberManager_h