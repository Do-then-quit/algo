#include <iostream>
#include <map>

using namespace std;

long long fib(long long N);

map<long long, int> visited;

int main(void) {
    long long n;
    cin >> n;
    
    cout << fib(n) << endl;
    return 0;
    
}

//d'Ocagne's identity 
long long fib(long long N) 
{
    if (N == 0)
    {
        return 0;
    } else if (N == 1) {
        return 1;
    } else if (N == 2) {
        return 1;
    } else if (N == 3) {
        return 2;
    }

    if(N % 2 == 0) {
        long long m, n, o;
        map<long long, int>::iterator item = visited.find(N / 2);
        if (item != visited.end())
        {
            m = item->second;
        } else {
            m = fib(N / 2);
            visited.insert(pair<long long, int>(N / 2, m));
        }

        item = visited.find(N / 2 + 1);
        if (item != visited.end())
        {
            n = item->second;
        } else {
            n = fib(N / 2 + 1);
            visited.insert(pair<long long, int>(N / 2 + 1, n));
        }

        item = visited.find(N / 2 - 1);
        if (item != visited.end())
        {
            o = item->second;
        } else {
            o = fib(N / 2 - 1);
            visited.insert(pair<long long, int>(N / 2 - 1, o));
        }
        return (m * (n + o)) % 1000000007;
        
    } else {
        long long m, n;
        map<long long, int>::iterator item = visited.find(N / 2);
        if (item != visited.end())
        {
            m = item->second;
        } else {
            m = fib(N / 2);
            visited.insert(pair<long long, int>(N / 2, m));
        }

        item = visited.find(N / 2 + 1);
        if (item != visited.end())
        {
            n = item->second;
        } else {
            n = fib(N / 2 + 1);
            visited.insert(pair<long long, int>(N / 2 + 1, n));
        }
        return (m * m + n * n) % 1000000007;
    }
    
}