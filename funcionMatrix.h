#ifndef funcionMatrix_h
#define funcionMatrix_h

#include<math.h>
#include<vector>
#include<stdlib.h>
#include<time.h>

namespace funcionMatrix
{
	class funcionMatrix
	{
		public:
			funcionMatrix();
			virtual ~funcionMatrix();
			
			void matrixAddMatrix(vector<int>* matrix, vector<int>* tmpMatrix);
			
		
		protected:
		
		private:
		
	}
}



#endif // funcionMatrix_h