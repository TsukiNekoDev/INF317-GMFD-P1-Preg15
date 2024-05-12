#include "stdio.h"
#include "omp.h"

void main(){
	int id, nthreads;		
	#pragma omp parallel shared(id)
	{
			id = omp_get_thread_num();
			printf("Hola Mundo desde el procesador %d\n", id);
			#pragma omp barrier
			
			if(id == 0){
				nthreads = omp_get_num_threads();
				printf("Hay %d procesos\n", nthreads);
			}
	}
}
