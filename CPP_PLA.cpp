#include <iostream>
#include <cstdlib> 
int main(int argc, char** argv) {
    int w[3];              //omega1           omega2   
	int data[4][4]={{3,5,1,1},{6,4,1,1},{1,0,1,-1},{1,1,1,-1}};	
	int c=1;  //每次調整量(學習速率) 
	for(int i=0;i<3;i++){
        w[i]= 0;  // 初始化權重 
    }
    int iterTimes=0; //4個一組的輪數
    while(true){
    	int correct=0;  //計算幾個樣本正確 
	    for(int i=0;i<4;i++){ //第i橫列 
	    	int sum=0;
	    	for(int j=0;j<3;j++){  //第j直行 
	    		sum+=w[j]*data[i][j];	
			}
			int output=0;  // omega1或omega2的分類結果以數字代替 
			if(sum>0){
				output=+1; // omega1  (>0) 
			}else{
				output=-1; // omega2  (<0)	
			}
			if(output>0&&data[i][3]==-1){	//分類結果是>0且期望類別是 omega2 (<0) 
				for(int j=0;j<3;j++){   
					w[j]=w[j]-c*data[i][j];  //太大所以減掉 
				}
			}
			else if(output<0&&data[i][3]==1){	//分類是<0且期望類別是 omega1 (>0)
				for(int j=0;j<3;j++){
					w[j]=w[j]+c*data[i][j];  //太小所以加回來 
				}
			}
			else if(sum==0&&data[i][3]==1){  //sum=0時且期望類別是 omega1 (>0)
				for(int j=0;j<3;j++){
					w[j]=w[j]+c*data[i][j];  //太小所以加回來 
				}
			}
			else if(sum==0&&data[i][3]==-1){ //sum=0時且期望類別是 omega2 (<0) 
				for(int j=0;j<3;j++){
					w[j]=w[j]-c*data[i][j];   //太大所以減掉  
				}
			}
			else if(output==data[i][3]){   //如果分類正確 
				correct++;    //分類正確的樣本+1 
			}
		}
		if(correct==4){  //當4個分類樣本都正確分類時 
			break;   //跳離while迴圈 
		}else{
			correct=0; //重新將正確樣本數量歸 0 
		}
		iterTimes++;  //4個一組的輪數 
	}
	for(int k=0 ;k<3;k++){
		printf("w[%d] = %d\n",k,w[k]);
	}
	printf("\n訓練輪數 = %d",iterTimes);
	return 0;
}

