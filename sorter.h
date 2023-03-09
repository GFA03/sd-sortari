#include <iostream>
#include <vector>
#include <chrono>
#include <tuple>

class vectorSorter
{
    static int partition(std::vector<long long int> &v, int left, int right);
    static std::tuple<long long, long long> getmaxmin(const std::vector<long long int> &v);
    public:
    static void mergesort(std::vector<long long int>& v, int left, int right);
    
    static void quicksort(std::vector<long long int>& v, int left, int right);
    
    static void shellsort(std::vector<long long int>& v);
    
    static void countsort(std::vector<long long int>& v);

    static void radixsort(std::vector<long long int>& v);
    
    static void radixsort256(std::vector<long long int>& v);

    static bool sortcheck(const std::vector<long long int>& v);

    static void copyVector(const std::vector<long long int> &v, std::vector<long long int> &k);

    static void templateOut(std::vector <long long int> &v, void (*_sorting)(std::vector <long long int>&), const std::string filename, const long long &length, const long long &maxValue);

    static void numberGenerator(std::vector<long long int> &v, const long long &length, const long long &maxValue);
};