# -*- coding: utf-8 -*-
"""
Created on Wed Dec  7 21:02:28 2022

@author: winner
"""

import numpy as np
names=np.array(['王薇','肖良英','方绮雯','刘旭阳','钱易铭'])
subjects=np.array(['Math','English','Python','Chonese','Art','Database','Physics'])
scores=np.array([[70,85,77,90,82,84,89],
                 [60,64,80,75,80,92,90],
                 [90,93,88,87,86,90,91],
                 [80,82,91,88,83,86,80],
                 [88,72,78,90,91,73,80]])
a=scores[:,subjects=='English']-3
print(a)
b=scores.mean(axis=1)
print(b)
c=np.random.uniform(-1,1,size=(3,4))
print(c)
d=c.sum()
print(d)
