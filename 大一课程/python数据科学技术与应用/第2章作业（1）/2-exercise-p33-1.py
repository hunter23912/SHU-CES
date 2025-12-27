# -*- coding: utf-8 -*-
"""
Created on Sat Dec  3 21:11:59 2022

@author: winner
"""
import numpy as np
chaoshi=np.array(['大润发','沃尔玛','好德','农工商'])
shuiguo=np.array(['苹果','梨','香蕉','橘子','芒果'])
jiage=np.random.randint(4,11,size=(4,5))
print(jiage)
#2
jiage[(chaoshi=='大润发')|(chaoshi=='好德'),(shuiguo=='苹果')|(shuiguo=='香蕉')]+=1
a=jiage[(chaoshi=='大润发')|(chaoshi=='好德'),(shuiguo=='苹果')|(shuiguo=='香蕉')]
print(a)
#3
jiage[chaoshi=='农工商']+=-2
b=jiage[chaoshi=='农工商']
print(b)
#4
c=jiage[:,(shuiguo=='苹果')].mean()
print(c)
d=jiage[:,(shuiguo=='芒果')].mean()
print(d)
#5
e=jiage[:,(shuiguo=='橘子')].max()
for i in range(0,4):
    if jiage[i,-2]==e:
        t=i
print(chaoshi[t])
#6