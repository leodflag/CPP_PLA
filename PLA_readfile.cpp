#include <iostream>
#include <fstream> // file stream
#include <sstream>// string stream 
using namespace std; 
void getDataSize(int size[]){
	ifstream file("data1.csv");  //�H�q�{��J�覡���}��� 
	string line;
	getline(file,line);  //�q��J�yŪ�J�r�Ŧs��string�ܶq�A����S��Ū�J�r�šB��^false 
	stringstream count(line);  //�N�@�Ӧr�Ŧ��ܶq���ȶǻ���istringstream��H count
	for(int i=0;i<2;i++){
		string val;
		getline(count,val,',');  //�H","����Ÿ� 
		stringstream convert(val); //��r�ꦨ�Ʀr  
		convert>> size[i];  //��J��x�} 		
	}		
}
void readData(int ** data, int r, int c){
	ifstream file("data1.csv");  //�H�q�{��J�覡���}��� 
	string line1;
	getline(file,line1);
	for(int row=0;row<r;++row){
		string line;
		if(!getline(file,line))  //�q��J�yŪ�J�@���string�ܶq�A����S��0Ū�J�r�šB��^false 
			break;
		stringstream iss(line);  //�N�@�Ӧr�Ŧ��ܶq���ȶǻ���istringstream��H 
		if(!iss.good())  //�p�G�S���N�^��True 
			break;
		for(int col=0;col<c;++col){
			string val;
			getline(iss,val,',');  //�r����� 
			stringstream convert(val); //��r�ꦨ�Ʀr  
			convert>>data[row][col];  //��J��x�} 
		}
	}
}
void PLA(int**data,int row,int col){
	for(int i=0;i<row;i++){ //��i��C 
		for(int j=0;j<col;j++){ //��j���� 
			cout<<data[i][j]<<" ";
		}
		cout<<"\n";
	}
	int w_len=col-1;
	int c=1;  //�C���վ�q(�ǲ߳t�v) 
	int w[w_len];
	for(int i=0;i<w_len;i++){
        w[i]= 0;  // ��l���v�� 
    }
    int iterTimes=0; //4�Ӥ@�ժ�����
    while(true){
    	int correct=0;  //�p��X�Ӽ˥����T 
	    for(int i=0;i<row;i++){ //��i��C 
	    	int sum=0;
	    	for(int j=0;j<w_len;j++){  //��j���� 
	    		sum+=w[j]*data[i][j];	
			}
			int output=0;  // omega1��omega2���������G�H�Ʀr�N�� 
			if(sum>0){
				output=+1; // omega1  (>0) 
			}else{
				output=-1; // omega2  (<0)	
			}
			if(output>0&&data[i][3]==-1){	//�������G�O>0�B�������O�O omega2 (<0) 
				for(int j=0;j<3;j++){   
					w[j]=w[j]-c*data[i][j];  //�Ӥj�ҥH� 
				}
			}
			else if(output<0&&data[i][3]==1){	//�����O<0�B�������O�O omega1 (>0)
				for(int j=0;j<3;j++){
					w[j]=w[j]+c*data[i][j];  //�Ӥp�ҥH�[�^�� 
				}
			}
			else if(sum==0&&data[i][3]==1){  //sum=0�ɥB�������O�O omega1 (>0)
				for(int j=0;j<3;j++){
					w[j]=w[j]+c*data[i][j];  //�Ӥp�ҥH�[�^�� 
				}
			}
			else if(sum==0&&data[i][3]==-1){ //sum=0�ɥB�������O�O omega2 (<0) 
				for(int j=0;j<3;j++){
					w[j]=w[j]-c*data[i][j];   //�Ӥj�ҥH�  
				}
			}
			else if(output==data[i][3]){   //�p�G�������T 
				correct++;    //�������T���˥�+1 
			}
		}
		if(correct==row){  //��4�Ӥ����˥������T������ 
			break;   //����while�j�� 
		}else{
			correct=0; //���s�N���T�˥��ƶq�k 0 
		}
		iterTimes++;  //4�Ӥ@�ժ����� 
	}
	for(int k=0 ;k<w_len;k++){
		printf("w[%d] = %d\n",k,w[k]);
	}
	printf("\n�V�m���� = %d",iterTimes);	
}
int main(int argc, char** argv){ 
	int size[]={}; //�ɮ�size 
	int data_row;  //��Ƶ��� 
	int data_col;  //��ưѼ� 
	getDataSize(size); //���o��Ƥ��e�j�p 
	data_row=size[0];
	data_col=size[1];
	int **data; //�ŧi�x�} 
	data=new int *[data_row];
	for(int i=0;i<data_col;i++)
		data[i]=new int[data_col]; 
	printf("data_row=%d,data_col=%d\n",data_row,data_col);
	readData(data,data_row,data_col); //Ū����� 
	PLA(data,data_row,data_col); //PLA��k 
  	return 0;
}
