#include <iostream>
#include <fstream>
#include <deque>
#include <vector>

int main()
{
    std::ifstream f1("deque.in");
    std::ofstream f2("deque.out");
    int n, k, x, S = 0, cnt = 0, cntStergeri = 0;
    bool turn = false;
    std::vector<int> poz;
    std::deque<int> rez;
    f1 >> n >> k;
    
    // while(f1 >> x)
    //     poz.push_back(x);

    while(f1 >> x)
    {
        if(poz.size() > 0)
            if(rez.size() > k || cnt - (k-1) > poz[0])
            {
                rez.pop_front();
                poz.erase(poz.begin());
            }
        cntStergeri = -1;
        if(rez.size() > 0)
            while(x < rez.back() && rez.size() > 0)
            {
                rez.pop_back();
                cntStergeri++;
            }
        if(cntStergeri >= 0)
        {
            poz.erase(poz.end()-cntStergeri-1, poz.end());
        }
        rez.push_back(x);
        poz.push_back(cnt);
        if(cnt >= k-1)
        {
            S += rez.front();
            // std::cout << "ADAUG: " << rez.front() << std::endl;
        }
        // std::cout << "DEQUE: ";
        // for(auto elem: rez)
        //     std::cout << elem << " ";
        // std::cout << '\n';
        // std::cout << "POZITILE: ";
        // for(auto elem: poz)
        //     std::cout << elem << " ";
        // std::cout << '\n' << '\n';
        cnt++;
    }
    f2 << S;
}