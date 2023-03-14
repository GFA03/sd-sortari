import matplotlib.pyplot as plt
import matplotlib as mpl
import numpy as np
import seaborn as sns
from os import listdir
from os.path import isfile, join

def readFiles():
    mypath = "stats/"
    onlyfiles = [mypath + f for f in listdir(mypath) if isfile(join(mypath, f)) and f.endswith(".txt")]

    time = dict()

    for file in onlyfiles:
        with open(file) as f:
            sortname = str(file[6:-4])
            time[sortname] = dict()
            for line in f:
                s = line.split()
                length = int(s[0])
                maxValue = int(s[1])
                run = s[2]
                seconds = int(s[3])
                if run != "Ok":
                    pass
                else:
                    if length not in time[sortname]:
                        time[sortname][length] = []
                    time[sortname][length].append(tuple([maxValue,seconds]))
    return time

def drawGraph():
    time = readFiles()   
    for (k,v) in time.items():
        sns.set_style("whitegrid")
        plt.xscale('log')
        plt.yscale('linear')

        for length, stats in v.items():
            seconds = [v[1] for v in stats if v[0] > 1e5]
            maxValue = [v[0] for v in stats if v[0] > 1e5]
            plt.plot(np.array(maxValue), np.array(seconds), label = "size: " + str(length))
            
        plt.xlabel('max value')
        plt.ylabel('microseconds')
        plt.title(str(k))
        plt.legend()
        plt.savefig("stats/" + k + ".png", dpi=1200)
        plt.close()

    
drawGraph()
# countsort = [x for x in [v for k,v in time["countsort"].items()]]           
# length = [10**x for x in range(2, 10)]
# plt.xscale('log')
# plt.yscale('linear')
# print(countsort)
# # plt.plot(np.array(length),np.array([item for sublist in countsort for item in sublist]))
# plt.plot(length, countsort[2])
# plt.xlabel('length')
# plt.ylabel('microseconds')
# plt.show()