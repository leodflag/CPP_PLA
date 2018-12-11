#include <iostream>
#include <cstdlib> 
int main(int argc, char** argv) {
    int w[3];              //omega1           omega2   
	int data[4][4]={{3,5,1,1},{6,4,1,1},{1,0,1,-1},{1,1,1,-1}};	
	int c=1;  //�C���վ�q(�ǲ߳t�v) 
	for(int i=0;i<3;i++){
        w[i]= 0;  // ��l���v�� 
    }
    int iterTimes=0; //4�Ӥ@�ժ�����
    while(true){
    	int correct=0;  //�p��X�Ӽ˥����T 
	    for(int i=0;i<4;i++){ //��i��C 
	    	int sum=0;
	    	for(int j=0;j<3;j++){  //��j���� 
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
		if(correct==4){  //��4�Ӥ����˥������T������ 
			break;   //����while�j�� 
		}else{
			correct=0; //���s�N���T�˥��ƶq�k 0 
		}
		iterTimes++;  //4�Ӥ@�ժ����� 
	}
	for(int k=0 ;k<3;k++){
		printf("w[%d] = %d\n",k,w[k]);
	}
	printf("\n�V�m���� = %d",iterTimes);
	return 0;
}

