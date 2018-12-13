#include <iostream>
int main(){/*
	int s[6]={0,5,4,9,2,-4};
	int Max=s[0];
	for(int i=0;i<6;i++){
		if(s[i]>Max)
		Max=s[i];
	}
	printf("MAX=%d",Max);*/
int w[3][3]={{1,2,3},{4,5,6},{7,8,9}};	
int data[3][3]={{1,2,3},{4,5,6},{7,8,9}};
int sum[3]={0,0,0};	
	for(int i=0;i<3;i++){ //控制第i橫排 
		for(int j=0;j<3;j++){ //控制第j直行 
			sum[j]+=w[i][j]*data[i][j];
			printf("sum+=w*x=:%d+=%d*%d\n",sum[j],w[i][j],data[i][j]);
		}
	}	
}


