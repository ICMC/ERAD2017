#include <stdio.h>
#include <stdlib.h>

#define nmax 32000
//32000
 
void show_usage();
unsigned long *create_sieve_to_number(unsigned long number);
 
int main () {
 
  unsigned long number;     

  unsigned long *sieve;

  int *qtty;
  qtty = (int *) malloc(nmax*sizeof(int));

  sieve = create_sieve_to_number(nmax);

  for (number=2; number<nmax; number+=2) {

    for (unsigned long i = 2; i < number; i++) {
      if (sieve[i] == 1) {
	for (unsigned long j = i; j < number; j++) {
	  if (sieve[j] == 1) {
	    if (i + j == number) {
	      qtty[number]++;
	      //printf("Solution found: %ld + %ld = %ld\n", i, j, number);
	      break;
	    }
	  }
	}
	if (qtty[number]>0) break;
      }
    }
  }
     
  //printf("no solution found!  pick up your Fields Medal!\n");
     
         
  return 0;
     
}
 
void show_usage(void) {
    printf("usage: goldbach [even number]\n");
}
 
unsigned long *create_sieve_to_number(unsigned long number) {
    unsigned long *sieve;
     
    sieve = (unsigned long *)malloc(sizeof(unsigned long) * (number + 1));
     
    for (int i = 0; i < number; i++) {
      sieve[i] = 1;
    }
     
    for (unsigned long i = 2; i < number; i++) {
        if (sieve[i] == 1) {
            for (unsigned long j = i * i; j < number; j = j + i) {
	      sieve[j] = 0;
            }
        }
    }
     
    return sieve;
}
