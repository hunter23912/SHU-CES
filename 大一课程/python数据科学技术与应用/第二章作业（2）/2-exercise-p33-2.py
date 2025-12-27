# -*- coding: utf-8 -*-
"""
Created on Wed Dec  7 21:18:00 2022

@author: winner
"""

import numpy as np
a=np.random.normal(0,1,size=(3,10))
print(a)
print()
position=a.cumsum(axis=1)
print(position)
print()
r=np.sqrt(position[0]**2+position[1]**2)
np.set_printoptions(precision=2)
print(r)
print()
dis=np.abs(position[2])
print(dis)
zuida=dis.max()
print(zuida)
zuixiao=r.min()
print(zuixiao)