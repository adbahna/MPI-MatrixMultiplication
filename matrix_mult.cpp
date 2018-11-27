#include <mpi.h> 
#include <cmath> 
#include <stdlib.h> 

using namespace std; 

#define N 128

int main(int argc, char ** argv)
{
	MPI_Init(&argc, &argv);

	int i, j, procCount, rank, rootProc, blockSize; 
	double start_time, end_time;
	MPI_Comm c = MPI_COMM_WORLD;

	MPI_Comm_size(c, &pCount);
	MPI_Comm_rank(c, &rank);
	rootProc = sqrt(procCount); 
	blockSize = (128 / rootProc); 

	double A[128][128];
	double B[128][128];
	double C[128][128];
	
	if (rank == 0)
	{
		for (i = 0; i < N; i++) {
        	for (j = 0; j < N; j++) {
            	A[i][j] = ((double) (rand()) / double(RAND_MAX)) * (1 + 1) - 1;
        	}
    	}

		for (i = 0; i < N; i++) {
        	for (j = 0; j < N; j++) {
            	B[i][j] = ((double) (rand()) / double(RAND_MAX)) * (1 + 1) - 1;
        	}
    	}
    	
		for (i = 0; i < N; i++) {
        	for (j = 0; j < N; j++) {
            	C[i][j] = 0;
			}
    	}

	}

	MPI_Finalize(); 

	return 0;
}
