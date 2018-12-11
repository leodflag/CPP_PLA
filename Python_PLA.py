# -*- coding: utf-8 -*-
"""
Created on Sun Dec  9 23:10:12 2018

@author: leodflag
"""
import numpy
import numpy as np
import matplotlib.pyplot as plt
dataset = numpy.loadtxt("data1.csv", delimiter=",")
data = dataset[:]
data_len=len(data)
omega1_x,omega1_y,omega2_x,omega2_y=[],[],[],[] # 繪圖用
w_length=3
w=[0]*w_length  # 初始化權重
#data=[[0,0,1,1],[0,1,1,1],[1,0,1,-1],[1,1,1,-1]]
c=1 # 每次調整量(學習速率) 
iterTimes=0 # 4個一組的輪數
while(True):
    correct=0 # 計算幾個樣本正確 
    for i in range(data_len): # 第i橫列
        Sum=0 
        for j in range(w_length): #第j直行 w權重位置
            Sum+=w[j]*data[i][j]
        output=0  # omega1或omega2的分類結果以數字代替
        if(Sum>0):
            output=1  # omega1  (>0)
        else:
            output=-1  # omega2  (<0)
        if(output>0 and data[i][3]==-1):    # 分類結果是>0且期望類別是 omega2 (<0)
            for j in range(w_length):
                w[j]=w[j]-c*data[i][j]  # 太大所以減掉
        elif(output<0 and data[i][3]==1):   # 分類是<0且期望類別是 omega1 (>0)
            for j in range(w_length):
                w[j]=w[j]+c*data[i][j]  # 太小所以加回來
        elif(Sum==0 and data[i][3]==1):     # sum=0時且期望類別是 omega1 (>0) 
            for j in range(w_length):
                w[j]=w[j]+c*data[i][j]  # 太小所以加回來
        elif(Sum==0 and data[i][3]==-1):    # sum=0時且期望類別是 omega2 (<0)
            for j in range(w_length):
                w[j]=w[j]-c*data[i][j]  #  太大所以減掉
        elif(output==data[i][3]):  #  如果分類正確
            correct+=1  # 分類正確的樣本+1 
    if(correct==data_len):  # 當4個分類樣本都正確分類時
        break  # 跳離while迴圈
    else:
        correct=0  #  重新將正確樣本數量歸 0 
    iterTimes+=1  #  4個一組的輪數
for k in range(w_length):
    print("w[",k,"]=",w[k],"\n")
print("\n訓練輪數=",iterTimes)
x=np.arange(-data_len,data_len)
y=w[0]*x+w[1]*x+w[2]
plt.plot(x,y)
# 繪圖函數
for i in range(data_len):
	if(data[i][3]==1):
		omega1_x.append(data[i][0])
		omega1_y.append(data[i][1])
	else:	
		omega2_x.append(data[i][0])
		omega2_y.append(data[i][1])
plt.scatter(omega1_x, omega1_y, alpha=0.6 ,c='red')
plt.scatter(omega2_x, omega2_y, alpha=0.6)  
plt.show()