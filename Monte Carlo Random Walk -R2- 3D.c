/* 3D program to calculate means of square distance       */
/*for 10000 runs and steps size 100 to 1000 with step 100 */


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define seed 4375  // numper for seed
#define Nmc 10000
#define steps 100
#define N 10

// 33% probability to move at x axis -> 1/6 right , 1/6 left
// 33% probability to move at y axis -> 1/6 up , 1/6 down
// 33% probability to move at z axis -> 1/6 in , 1/6 left out

#define p1 1.0/6.0 
#define p2 2.0/6.0
#define p3 3.0/6.0
#define p4 4.0/6.0
#define p5 5.0/6.0

int main(){
	int i,j,imc;
	int sumx,sumy,sumz;
	double k,ko;
    double*R2=malloc(N*sizeof(double));  // allocate memory
    double*muR=malloc(N*sizeof(double)); // allocate memory
    srand(seed);
    FILE *randomWalk3d;
    
    randomWalk3d=fopen("randomWalk3d.txt","w");
    
    for(i=0;i<N;i++){
		muR[i]=0; R2[i]=0;     // array R2 for square distance and muR for mean of square distance
	}	
	
	for(imc=0;imc<Nmc;imc++){
		sumx=0.0;  //sum for whole distance on x axis at every run
		sumy=0.0;	//sum for whole distance on y axis at every run
		sumz=0.0;   //sum for whole distance on z axis at every run
		for(i=0;i<N;i++){
			
			for(j=0;j<steps;j++){   //start random walk
				
				 k=(double)rand() / (double)((unsigned)RAND_MAX + 1);	
				 
				if(k<=p1) 		
				  sumx+=1;	
				  
				else if(k<=p2) 	
				  sumx-=1;
				  
				else if(k<=p3)  
				   sumy+=1;
				   
				 else if(k<=p4)
				    sumy-=1;  
				    
				 else if(k<=p5)
				    sumz+=1;      
			    else
				     sumz-=1;
			}
			
			R2[i]=sumx*sumx+sumy*sumy+sumz*sumz;	
			muR[i]+=R2[i]/Nmc;	
		}
	}
	
	for(i=0;i<N;i++){
		
		printf("%d\t%f\n",steps*(i+1),muR[i]);
		fprintf(randomWalk3d,"%d\t%f\n",steps*(i+1),muR[i]);  //write data 
	}
	free(R2);  // free memory
	free(muR); //free memory 
	fclose(randomWalk3d);
	return 0;
}
