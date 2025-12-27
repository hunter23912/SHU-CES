# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""
import numpy as np
names=np.array(['王微','肖良英','方绮雯','刘旭阳','钱易铭'])
subjects=np.array(['Math','English','Python','Chinese','Art','Database','Physics'])
scores=np.array([[70,85,77,90,82,84,89],[60,64,80,75,80,92,90],[90,93,88,87,86,90,91],[80,82,91,88,83,86,80],[88,72,78,90,91,73,80]])
print(subjects[[1,2,4]])
print(names[-3])
print(names[2:])
print(subjects[2:5])
mask=(subjects=='English')|(subjects=='Physics')
print(subjects[mask])
#1
print(scores[[0,3]])
print(scores[[2,4]][:,[0,2]])
print(scores[:,[0,4]])
print(scores[(names=='王微')|(names=='刘旭阳')][:,[1,4]])
#2
a=np.arange(10,20).reshape(2,5)
print(a)
#3