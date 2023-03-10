import matplotlib as plt
import numpy as np
import pandas as pd
import seaborn as sb
from os import listdir
from os.path import isfile, join

mypath = "stats/"
countsort, mergesort, quicksort, shellsort, radixsort, radixsort256, sort = list(), list(), list(), list(), list(), list(), list() 

onlyfiles = [mypath + f for f in listdir(mypath) if isfile(join(mypath, f))]

time = dict()

for file in onlyfiles:
    with open(file) as f:
        add = str(file[6:-4])
        time[add] = dict()
        for line in f:
            s = line.split()
            length = int(s[0])
            maxValue = int(s[1])
            run = s[2]
            seconds = int(s[3])
            if run != "Ok":
                pass
            else:
                if maxValue not in time[add]:
                    time[add][maxValue] = []
                time[add][maxValue].append(tuple([length, seconds]))

print(time)

# for file in onlyfiles:
#     with open(file) as f:
