#include <omp.h>
#include <stdio.h>
#define N 100000

int main(int argc, char*argv[]){
	double v1[N], v2[N], final;
	long i;
	unsigned seed;
	
	#pragma omp parallel private(seed) 
	{
		seed=time(NULL)*omp_get_thread_num();
		#pragma omp for reduction(+:final)
		for(i=0; i< N; i++){
			v1[i] = rand_r(&seed);
			v2[i] = rand_r(&seed);  
			final+=(v1[i]*v2[i]);
				}
	}
	return 0;
}
