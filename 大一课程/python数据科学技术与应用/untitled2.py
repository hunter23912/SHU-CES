# -*- coding: utf-8 -*-
"""
Created on Mon Dec 19 17:48:30 2022

@author: winner
"""
import pandas as pd
import numpy as np
from pandas import Series,DataFrame
data=DataFrame(np.arange(1,10).reshape(3,3),index=['a','b','c'],columns=['one','two','three'])
print(data)
print(data[['two','three']])
print(data.iloc[[0,2],[0,2]])
data1=data.loc[data['two']>2]
print(data1)
data1.loc[:,'four']=10
print(data1)
data1.loc[:,'four']=8
print(data1)
print(data1.drop(data1.index[0:2],axis=0))