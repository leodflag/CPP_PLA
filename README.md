# PLA
This is a Perceptron Learning Algorithm project written in C++.
## 目標(CPP_PLA.cpp)
 	// 4筆資料分成2類
    int data[4][4] = {{3, 5, 1, 1}, {6, 4, 1, 1}, {1, 0, 1, -1}, {1, 1, 1, -1}};
[公式](https://github.com/leodflag/Python_PLA)
## 結果
![image](https://github.com/leodflag/CPP_PLA/blob/master/img/data_result.png)

## 目標(PLA_readfile.cpp)
    讀取csv檔內的資料，用PLA分成2類
## 函式虛擬碼
    void getDataSize(int size[])
        讀取檔案file
        創造字串line
        用getline從file中讀取到line中
        將line字串變量傳給stringstream 的count 

            建立字串val
            用getline 從count 中，以","當換行符號，傳到val
            用stringstream的convert將val轉成數字後存入
            將convert 輸入到矩陣
            
## 函式
	int **data; //宣告矩陣
	data = new int *[data_row];
	for (int i = 0; i < data_col; i++)
	data[i] = new int[data_col];
    
## 結果
### data1
![image](https://github.com/leodflag/CPP_PLA/blob/master/img/data1_result.png)
### data2
![image](https://github.com/leodflag/CPP_PLA/blob/master/img/data2_result.png)

## PLA講義
![image](https://github.com/leodflag/CPP_PLA/blob/master/img/PLA1.jpg)
![image](https://github.com/leodflag/CPP_PLA/blob/master/img/PLA2.jpg)
