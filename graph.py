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
                    # if length not in time[sortname]:
                    #     time[sortname][length] = []
                    # time[sortname][length].append(tuple([maxValue,seconds]))
                    if maxValue not in time[sortname]:
                        time[sortname][maxValue] = []
                    time[sortname][maxValue].append(tuple([length, seconds]))
    return time

def drawGraph():
    time = readFiles()
    for (k,v) in time.items():
        sns.set_style("whitegrid")
        plt.xscale('log')
        plt.yscale('linear')

        # for length, stats in v.items():
        #     seconds = [v[1] for v in stats]
        #     maxValue = [v[0] for v in stats]
        #     plt.plot(np.array(maxValue), np.array(seconds), label = "size: " + str(length))
            
        for maxValue, stats in v.items():
            seconds = [v[1] for v in stats]
            length = [v[0] for v in stats]
            plt.plot(np.array(length), np.array(seconds), label = str(k))

        # plt.xlabel('vector size')
        # plt.ylabel('microseconds')
        # plt.title(str(k))
        # plt.legend()
        # plt.savefig("stats/" + k + ".png", dpi=1200)
        # plt.close()
   
    plt.xlabel('vector size')
    plt.ylabel('microseconds')
    plt.title("Sortari")
    plt.legend()
    plt.savefig("stats/" + "Sortari" + ".png", dpi=1200)
    plt.close()


def combinedGraph():
    time = readFiles()
    for i in range(8):
        for (k,v) in time.items():
            sns.set_style("whitegrid")
            plt.xscale('log')
            plt.yscale('linear')

            seconds =[v[1] for v in time[k][10**(i+2)]]
            length = [v[0] for v in time[k][10**(i+2)]]
            plt.plot(np.array(length), np.array(seconds), label = str(k))

        # for maxValue, stats in v.items():
        #     seconds = [v[1] for v in stats]
        #     length = [v[0] for v in stats]
        #     print(stats)
                # if v[0] == 10**(i+2):
                #     plt.plot(np.array(length), np.array(seconds), label = str(k))

            # plt.xlabel('vector size')
            # plt.ylabel('microseconds')
            # plt.title(str(k))
            # plt.legend()
            # plt.savefig("stats/" + k + ".png", dpi=1200)
            # plt.close()
    
        plt.xlabel('vector size')
        plt.ylabel('microseconds')
        plt.title("max value = " + str(10**(i+2)))
        plt.legend()
        plt.savefig("stats/" + "Sortari" + str(i) + ".png", dpi=1200)
        plt.close()

combinedGraph()