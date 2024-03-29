#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>
#include <tuple>
#include <string>
#include <algorithm>
#include <functional>
#include "sorter.h"
bool VectorSorter::sortcheck(const std::vector<long long int> &v)
{
    for(int i = 0; i < v.size()-1; i++)
        if(v[i] > v[i+1])
            return false;
    return true;
}

void VectorSorter::mergesort(std::vector<long long int> &v, int left, int right)
{
    if(left < right)
    {
        int m = left / 2 + right / 2;
        mergesort(v, left, m);
        mergesort(v, m+1, right);
        std::vector<long long int> tmp;
        int i = left, j = m+1;
        if(v[m] > v[m+1])
        {
            while(i <= m && j <= right)
            {
                if(v[i] < v[j])
                    tmp.push_back(v[i++]);
                else
                    tmp.push_back(v[j++]);
            }
            while(i <= m)
                tmp.push_back(v[i++]);
            while(j <= right)
                tmp.push_back(v[j++]);
            for(i = left, j = 0; i <= right; i++, j++)
                v[i] = tmp[j];
        }
    }
}

int VectorSorter::partition(std::vector<long long int> &v, int left, int right)
{
    long long i = left - 1,  j = right + 1, a = v[left], b = v[(left+right)/2], c = v[right], pivot;
    if((a >= b && a <= c) || (a >= c && a <= b)) pivot = a;
    else if((b >= a && b <= c) || (b >= c && b <= a)) pivot = b;
    else if((c >= a && c <= b) || (c >= b && c <= a)) pivot = c;
    while(true)
    {
        do{i++;}while(v[i] < pivot);
        do{j--;}while(v[j] > pivot);
        if(j <= i) return j;
        std::swap(v[i],v[j]);
    }
}

void VectorSorter::quicksort(std::vector<long long int> &v, int left, int right)
{
    if(left >= 0 && right >= 0 && left < right)
    {
        int pi = partition(v, left, right);
        quicksort(v, left, pi);
        quicksort(v, pi+1, right);
    }
}

std::tuple<long long, long long> VectorSorter::getmaxmin(const std::vector<long long int> &v)
{
    long long max = v[0], min = v[0];
    for(int i = 1; i < v.size(); i++)
    {
        if(v[i] > max) max = v[i];
        if(v[i] < min) min = v[i];
    }
    return {max, min};
}


void VectorSorter::countsort(std::vector<long long int> &v)
{
    try{
    long long j = 0;
    auto [max, min] = getmaxmin(v);
    std::vector<long long int> tmp(max-min+1, 0);
    for(int i = 0; i < v.size(); i++)
        tmp[v[i]-min]++;
    for(int i = 0; i <= max-min; i++){
        while(tmp[i] > 0){
            v[j++] = i + min;
            tmp[i]--;
        }
    }}
    catch(...)
    {

    }
}

void VectorSorter::shellsort(std::vector<long long int> &v)
{
    long long j;
    for(long long gap = v.size()/2; gap > 0; gap /= 2)
    {
        for(long long i = gap; i < v.size(); i++)
        {
            long long temp = v[i];
            for(j = i; j >= gap && temp < v[j - gap]; j -= gap)
                v[j] = v[j - gap];
            v[j] = temp;
        }
    }
}

void VectorSorter::radixsort(std::vector<long long int> &v)
{
    auto [greatest, smallest] = getmaxmin(v);
    std::vector<long long int> result(v.size()+1, 0);
    long long digitplace = 1; 
    while(greatest/digitplace > 0)
    {
        int count[10] = {0};
        for(int i = 0; i < v.size(); i++)
        {
            count[(v[i]/digitplace) % 10]++;
        }
        for(int i = 1; i < 10; i++)
        {
            count[i] += count[i-1];
        }
        for(int i = (v.size() - 1); i >= 0; i--)
        {
            result[count[(v[i]/digitplace) % 10]-1] = v[i];
            count[(v[i]/digitplace) % 10]--;
        }
        for(int i = 0; i < v.size(); i++)
            v[i] = result[i];
            digitplace *= 10;
    }
}

void VectorSorter::radixsort256(std::vector<long long int> &v)
{
    auto [greatest, smallest] = getmaxmin(v);
    std::vector<long long int> result(v.size()+1, 0); 
    long long digitplace = 1; 
    while(greatest/digitplace > 0)
    {
        int count[256] = {0};
        for(int i = 0; i < v.size(); i++)
        {
            count[(v[i]/digitplace) % 256]++;
        }
        for(int i = 1; i < 256; i++)
        {
            count[i] += count[i-1];
        }
        for(int i = (v.size() - 1); i >= 0; i--)
        {
            result[count[(v[i]/digitplace) % 256]-1] = v[i];
            count[(v[i]/digitplace) % 256]--;
        }
        for(int i = 0; i < v.size(); i++)
            v[i] = result[i];
        digitplace = digitplace << 8;
    }
}

void VectorSorter::numberGenerator(std::vector<long long int> &v, const long long &length, const long long &maxValue) {
    std::random_device rd;     
    std::mt19937_64 eng(rd()); 
    std::uniform_int_distribution<unsigned long long> distr;
    v.clear();
    for(int i = 0;  i < length; i ++) {
        v.push_back(distr(eng) % (maxValue)); 
    }
}

void VectorSorter::copyVector(const std::vector<long long int> &v, std::vector<long long int> &k)
{
    k.clear();
    for(int i = 0; i < v.size(); ++i)
        k.push_back(v[i]);
}

void VectorSorter::templateOut(std::vector <long long int> &v, void (*_sorting)(std::vector <long long int>&), std::ofstream &f, const long long &length, const long long &maxValue)
{
    auto start = std::chrono::high_resolution_clock::now();
    _sorting(v);
    auto stop = std::chrono::high_resolution_clock::now();
    bool isSorted = VectorSorter::sortcheck(v);
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    f << length << ' ' << maxValue << ' ' << (isSorted ? "Ok" : "Failed") << ' ' << duration.count() << '\n';
}

void VectorSorter::templateOutQuickAndMerge(std::vector <long long int> &v, void (*_sorting)(std::vector <long long int>&, int, int), std::ofstream &f, const long long &length, const long long &maxValue)
{
    auto start = std::chrono::high_resolution_clock::now();
    _sorting(v, 0, v.size());
    auto stop = std::chrono::high_resolution_clock::now();
    bool isSorted = VectorSorter::sortcheck(v);
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    f << length << ' ' << maxValue << ' ' << (isSorted ? "Ok" : "Failed") << ' ' << duration.count() << '\n';
}

int main(){

    std::vector<long long int> v;  
    std::vector<long long int> k;

    std::ofstream f2("stats/quicksort.txt");
    std::ofstream f3("stats/mergesort.txt");
    std::ofstream f4("stats/countsort.txt");
    std::ofstream f5("stats/shellsort.txt");
    std::ofstream f6("stats/radixsort.txt");
    std::ofstream f7("stats/radixsort256.txt");
    std::ofstream f8("stats/introsort.txt");
    for(long long length = 100; length <= 100000000; length *= 10)
    {
        std::cout << "\nlength: " << length << "\nmaxValue: ";
        for(long long maxValue = 100; maxValue <= 10000000000 ; maxValue *= 10)
        {    
            std::cout << maxValue << ' ';
            VectorSorter::numberGenerator(v, length, maxValue);
            VectorSorter::copyVector(v, k);
            VectorSorter::templateOutQuickAndMerge(k, VectorSorter::quicksort, f2, length, maxValue); 
            VectorSorter::copyVector(v, k);
            VectorSorter::templateOutQuickAndMerge(k, VectorSorter::mergesort, f3, length, maxValue); 
            VectorSorter::copyVector(v, k);
            VectorSorter::templateOut(k, VectorSorter::countsort, f4, length, maxValue);
            VectorSorter::copyVector(v, k);
            VectorSorter::templateOut(k, VectorSorter::shellsort, f5, length, maxValue); 
            VectorSorter::copyVector(v, k);
            VectorSorter::templateOut(k, VectorSorter::radixsort, f6, length, maxValue); 
            VectorSorter::copyVector(v, k);
            VectorSorter::templateOut(k, VectorSorter::radixsort256, f7, length, maxValue); 
            auto start = std::chrono::high_resolution_clock::now();
            std::sort(v.begin(), v.end());
            auto stop = std::chrono::high_resolution_clock::now();
            bool isSorted = VectorSorter::sortcheck(v);
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
            f8 << length << ' ' << maxValue << ' ' << (isSorted ? "Ok" : "Failed") << ' ' << duration.count() << '\n';
        }
    }
}
