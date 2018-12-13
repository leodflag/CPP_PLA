#include <iostream>
#include <fstream> // file stream
#include <sstream>// string stream 
using namespace std; 
void getDataSize(int size[]){
	ifstream file("data1.csv");  //以默認輸入方式打開文件 
	string line;
	getline(file,line);  //從輸入流讀入字符存到string變量，直到沒有讀入字符、返回false 
	stringstream count(line);  //將一個字符串變量的值傳遞給istringstream對象 count
	for(int i=0;i<2;i++){
		string val;
		getline(count,val,',');  //以","當換行符號 
		stringstream convert(val); //轉字串成數字  
		convert>> size[i];  //輸入到矩陣 		
	}		
}
void readData(int ** data, int r, int c){
	ifstream file("data1.csv");  //以默認輸入方式打開文件 
	string line1;
	getline(file,line1);
	for(int row=0;row<r;++row){
		string line;
		if(!getline(file,line))  //從輸入流讀入一行到string變量，直到沒有0讀入字符、返回false 
			break;
		stringstream iss(line);  //將一個字符串變量的值傳遞給istringstream對象 
		if(!iss.good())  //如果沒錯就回傳True 
			break;
		for(int col=0;col<c;++col){
			string val;
			getline(iss,val,',');  //字串分割 
			stringstream convert(val); //轉字串成數字  
			convert>>data[row][col];  //輸入到矩陣 
		}
	}
}
void PLA(int**data,int row,int col){
	for(int i=0;i<row;i++){ //第i橫列 
		for(int j=0;j<col;j++){ //第j直行 
			cout<<data[i][j]<<" ";
		}
		cout<<"\n";
	}
	int w_len=col-1;
	int c=1;  //每次調整量(學習速率) 
	int w[w_len];
	for(int i=0;i<w_len;i++){
        w[i]= 0;  // 初始化權重 
    }
    int iterTimes=0; //4個一組的輪數
    while(true){
    	int correct=0;  //計算幾個樣本正確 
	    for(int i=0;i<row;i++){ //第i橫列 
	    	int sum=0;
	    	for(int j=0;j<w_len;j++){  //第j直行 
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
		if(correct==row){  //當4個分類樣本都正確分類時 
			break;   //跳離while迴圈 
		}else{
			correct=0; //重新將正確樣本數量歸 0 
		}
		iterTimes++;  //4個一組的輪數 
	}
	for(int k=0 ;k<w_len;k++){
		printf("w[%d] = %d\n",k,w[k]);
	}
	printf("\n訓練輪數 = %d",iterTimes);	
}
int main(int argc, char** argv){ 
	int size[]={}; //檔案size 
	int data_row;  //資料筆數 
	int data_col;  //資料參數 
	getDataSize(size); //取得資料內容大小 
	data_row=size[0];
	data_col=size[1];
	int **data; //宣告矩陣 
	data=new int *[data_row];
	for(int i=0;i<data_col;i++)
		data[i]=new int[data_col]; 
	printf("data_row=%d,data_col=%d\n",data_row,data_col);
	readData(data,data_row,data_col); //讀取資料 
	PLA(data,data_row,data_col); //PLA算法 
  	return 0;
}
