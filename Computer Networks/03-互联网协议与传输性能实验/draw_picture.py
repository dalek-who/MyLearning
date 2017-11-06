#!/usr/bin/python

import matplotlib.pyplot as plt
import numpy as np

from timeit import *

#################################
def plot_time():
    bw = [1, 5, 10, 50, 100]
    time1 = [0.9, 0.2, 0.2, 0.1, 0.1]
    time10 = [8.8, 1.8, 1, 0.4, 0.3]
    time100 = [88, 18, 9.4, 2.1, 1.2]
    for x in [4, 3, 2, 1, 0]:
        time1[x] = 1. * time1[0] / time1[x]
        time10[x] = 1. * time10[0] / time10[x]
        time100[x] = 1. * time100[0] / time100[x]
    plt.plot(bw, bw, 'r', label='equal improvement in FCT and bandwidth')
    plt.plot(bw, time1, 'k-s', label='1MB')
    plt.plot(bw, time10, 'b-^', label='10MB')
    plt.plot(bw, time100, 'g-o', label='100MB')
    plt.legend(loc='best')
    plt.xlabel('Relative bandwidth improvement')
    plt.ylabel('Relative FCT improvement')
    plt.xlim([1, 100])
    plt.ylim([1, 100])
    plt.xscale('log')
    plt.yscale('log')
    #plt.show()
    plt.savefig('pic1.png')

def plot_cdf(fname):
    dns = list()
    conn = list()
    curl = list()
    for line in open(fname, 'r'):
        t1 = float(line.strip().split()[1])
        t2 = float(line.strip().split()[2])
        t3 = float(line.strip().split()[3])
        dns.append(t1)
        conn.append(t2)
        curl.append(t3)
    dns.sort()
    conn.sort()
    curl.sort()
    p = 1. * np.arange(len(dns))/(len(dns) - 1)
    plt.plot(dns, p, color='black', label='dns')
    p = 1. * np.arange(len(conn))/(len(conn) - 1)
    plt.plot(conn, p, color='brown', label='conn')
    p = 1. * np.arange(len(curl))/(len(curl) - 1)
    plt.plot(curl, p, color='blue', label='curl')
    plt.xscale('log')
    plt.legend(loc='best')
    plt.xlabel('time (s)')
    plt.ylabel('CDF')
    #plt.show()
    plt.savefig('pic2.png')

if __name__ == '__main__':
    plt.figure(1)
    plot_time()
    plt.figure(2)
    ofile = 'ping_results.txt'
    plot_cdf(ofile)
