#include <mpi.h> 
#include <cmath> 
#include <stdlib.h> 

using namespace std; 

#define N 128

int main(int argc, char ** argv)
{
	MPI_Init(&argc, &argv);

	int i, j, k, 
		procCount, rank, rootProc, blockSize; 
	double startTime, endTime, tempSum = 0; 
	MPI_Comm c = MPI_COMM_WORLD;

	MPI_Comm_size(c, &procCount);
	MPI_Comm_rank(c, &rank);
	rootProc = sqrt(procCount); 
	blockSize = (N / rootProc); 

	double A[N][N];
	double B[N][N];
	double C[N][N];

	if (rank == 0)
	{
		for (i = 0; i < N; i++) 
        	for (j = 0; j < N; j++) 
            	A[i][j] = ((double) (rand()) / double(RAND_MAX)) * (1 + 1) - 1;

		for (i = 0; i < N; i++) 
        	for (j = 0; j < N; j++) 
            	B[i][j] = ((double) (rand()) / double(RAND_MAX)) * (1 + 1) - 1;
    	
		for (i = 0; i < N; i++)
        	for (j = 0; j < N; j++) 
            	C[i][j] = 0;

		if (procCount == 1)
		{
			startTime = MPI_Wtime(); 
			for (i = 0; i < N; i++)
			{
				for (j = 0; j < N; j++)
				{
					for (k = 0; k < N; k++)
					{
						tempSum += (A[i][k] * B[k][j]); 
					}
					C[i][j] = tempSum; 
				}
			}
			endTime = MPI_Wtime();

			printf("Elapsed Time (On Single Processor): %f\n", endTime - startTime); 
		}
	}

	MPI_Finalize(); 

	return 0;
}
