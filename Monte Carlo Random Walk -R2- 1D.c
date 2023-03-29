/* 1D program to calculate means of square distance       */
/*for 10000 runs and steps size 100 to 1000 with step 100 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define seed 4375  // numper for seed
#define Nmc 10000  //number of runs
#define steps 100
#define N 10
#define p1 0.5 // probability to move right
#define p2 0.5 // probability to move left


int main(){
	int i,j,imc;
	int sumx;
	double k,ko;
    double*R2=malloc(N*sizeof(double));  //allocate memory
    double*muR=malloc(N*sizeof(double)); //allocate memory 
    srand(seed);
    FILE *randomWalk1d;
    
    randomWalk1d=fopen("randomWalk1d.txt","w");  // open data file
    
    for(i=0;i<N;i++){
		muR[i]=0; R2[i]=0;      // array R2 for square distance and muR for mean of square distance
	}	
	
	for(imc=0;imc<Nmc;imc++){    
		sumx=0;                //sum for whole distance at every run
			
		for(i=0;i<N;i++){
			
			for(j=0;j<steps;j++){
				
				 k=(double)rand() / (double)((unsigned)RAND_MAX + 1);	
				if(k<=p1) 		
				  sumx+=1;	
				else if(k>p2)	
				  sumx-=1;
			
			}
			R2[i]=sumx*sumx;	
			muR[i]+=(double)R2[i]/Nmc;	
	     } 
	}
	
	for(i=0;i<N;i++){
		
		printf("%d\t%f\n",steps*(i+1),muR[i]);
		fprintf(randomWalk1d,"%d\t%f\n",steps*(i+1),muR[i]);  //write data 
	}
	free(R2);  //free memory 
	free(muR); //free memory
	fclose(randomWalk1d);
	return 0;
}
