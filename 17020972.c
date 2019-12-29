
#include <stdio.h>
#include<stdlib.h>
#include<time.h>


int linear();
int binary();
int jump();
int interpolation();

int arr[10000], x,i,j;
int flag=0;

int main(){
	
    
    for(i=0;i<=10000;i++){
    	arr[i]=  rand()% 10000;
    //	printf("%d /n",arr[i]);
    }
    printf("the values to search are\n");
	for(i=0;i<10000;i++){
		printf("%d\t",arr[i]);
	}
  
    printf("Enter the value to search:");
    scanf("%d", &x);
    linear();
    binary();
    jump();
    interpolation();
    

}
    
    //linear searching
int linear(){
	
	struct timespec tstart={0,0}, tend={0,0};
	clock_gettime(CLOCK_MONOTONIC, &tstart);
    
    for( i=0; i<10000; i++){
    	if(arr[i]== x){
			printf("The value %d is in the array from linear search\n" ,x);
			flag=1;
			break;
		}
	}
	if(flag==0)
			printf("The value %d is not in the array from linear search\n",x);
	
	printf("linear search took about %.5f seconds\n",
          ((double)tend.tv_sec + 1.0e-8*tend.tv_nsec) - 
          ((double)tstart.tv_sec + 1.0e-8*tstart.tv_nsec));
	
}
	
	//binary searching
int binary (){
	
int y;
	
	
	int first= 0;
	int last=10000-1;
	int middle=(first+last)/2;
	
	for(i=0; i<10000; i++){
		for(j=i+1; j<10000; j++){
			if(arr[i]>arr[j]){
				y=arr[i];
				arr[i]=arr[j];
				arr[j]=y;	
			}	
		}
	}
	
	struct timespec tstart={0,0}, tend={0,0};
	clock_gettime(CLOCK_MONOTONIC, &tstart);
	
	for(i=0; i<10000; i++){
		if(arr[middle]<x){
			first=middle+1;
		}
		else if(arr[middle]==x){
			printf("The value %d is in the array from binary search\n",x);
			flag =1;
			break;
		}
		else{
			last=middle-1;
		}
		middle=(first+last)/2;	
	}
	if(flag==0)
		printf("The value %d is not in the array from binary search\n",x);
		
	printf("binary search took about %.5f seconds\n",
          ((double)tend.tv_sec + 1.0e-8*tend.tv_nsec) - 
          ((double)tstart.tv_sec + 1.0e-8*tstart.tv_nsec));

}
	//jump search
int jump(){
	int c=100;
	int y,high,low;
	
	for(i=0; i<10000; i++){
		for(j=i+1; j<10000; j++){
			if(arr[i]>arr[j]){
				y=arr[i];
				arr[i]=arr[j]; 
				arr[j]=y;	
			}	
		}
	}
	
	struct timespec tstart={0,0}, tend={0,0};
	clock_gettime(CLOCK_MONOTONIC, &tstart);
	
		for(i=0; i<100; i++ ){
			if(x<arr[c]){
			high=c-1;	
			}
			else{
			low=c+1;
			}
		}
	
		for(i=low; i<=high; i++){
			if(arr[i]==x){
				printf("The value %d is in the array from jump search\n",x);
				flag==1;
				break;
			}
		}
		if(flag==0)
				printf("The value %d is not in the array from binary search\n",x);
	
	printf("jump search took about %.5f seconds\n",
           ((double)tend.tv_sec + 1.0e-8*tend.tv_nsec) - 
           ((double)tstart.tv_sec + 1.0e-8*tstart.tv_nsec));
	
	
}

	
	//interpolation search
int interpolation(){
	
int y;
	int low=0, high=9999;
	
	for(i=0; i<10000;i++){
		for(j=i+1; j<10000;j++){

			if(arr[i]>arr[j]){
				y=arr[i];
				arr[i]=arr[j]; 
				arr[j]=y;	
			}	
		}
	}
	
	struct timespec tstart={0,0}, tend={0,0};
	clock_gettime(CLOCK_MONOTONIC, &tstart);
	
	while(low<=high && x >=arr[low] && x<= arr[high]){
	int probe;
		probe = low + (((double)(high - low) / 	(arr[high] - arr[low])) * (x - arr[low]));
			
			if (arr[probe]<x){
				low=probe+1;
			}
			else if(arr[probe]==x){
				printf("The value %d is in the array from interpolation search",x);
				flag = 1;	
				break;
			}
			else{
				high=probe-1;
			}
	}
		if(flag==0){
		printf("The value %d is not in the array from interpolation search",x);
	}
	
	printf("interpolation search took about %.5f seconds\n",
           ((double)tend.tv_sec + 1.0e-8*tend.tv_nsec) - 
           ((double)tstart.tv_sec + 1.0e-8*tstart.tv_nsec));
}
	
	
	
	
	
	
    

