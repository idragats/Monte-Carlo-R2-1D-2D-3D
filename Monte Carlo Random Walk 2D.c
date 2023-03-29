/* 2D program to calculate means of square distance       */
/*for 10000 runs and steps size 100 to 1000 with step 100 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define seed 4375  // numper for seed
#define Nmc 10000
#define steps 100
#define N 10
#define p1 0.25  // 50% probability to move at x axis -> 25% right , 25% left
#define p2 0.5   // 50% probability to move at x axis -> 25% up , 25% down
#define p3 0.75  

int main(){
	int i,j,imc;
	int sumx,sumy;
	double k;
    double*R2=malloc(N*sizeof(double));  // allocate memory
    double*muR=malloc(N*sizeof(double)); //allocate memory
    srand(seed);
    FILE *randomWalk2d;
    
    randomWalk2d=fopen("randomWalk2d.txt","w");
    
    for(i=0;i<N;i++){
		muR[i]=0; R2[i]=0;   // array R2 for square distance and muR for mean of square distance
	}	
	
	for(imc=0;imc<Nmc;imc++){
		sumx=0.0;  //sum for whole distance on x axis at every run
		sumy=0.0;	//sum for whole distance on y axis at every run
		for(i=0;i<N;i++){
			
			for(j=0;j<steps;j++){
				
				 k=(double)rand() / (double)((unsigned)RAND_MAX + 1);	
				if(k<=p1) 		
				  sumx+=1;	
				  
				else if(k<=p2) 	
				  sumx-=1;
				  
				else if(k<=p3)  
				   sumy+=1;
				   
				 else
				    sumy-=1;  
				
			}
			R2[i]=sumx*sumx+sumy*sumy;	
			muR[i]+=R2[i]/Nmc;	
		}
	}
	
	for(i=0;i<N;i++){
		
		printf("%d\t%f\n",steps*(i+1),muR[i]);
		fprintf(randomWalk2d,"%d\t%f\n",steps*(i+1),muR[i]);  //write data
	}
	free(R2);  // free memory 
	free(muR); //free memory
	fclose(randomWalk2d);
	return 0;
}
