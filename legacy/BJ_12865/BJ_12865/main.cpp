//
//  main.cpp
//  BJ_12865
//
//  Created by LeeMinkyo on 2021/02/19.
//  배열 초기화는 앵간하면 fill쓰던가 직접 for문돌면서 하자... 휴...
//  오늘은 그냥 dp로했지만 백트래킹으로도 할수있다. 알고리즘때 했었던듯
// 암튼 오늘은 여기까지? 알고리즘 문제해결전략책이 은근 괜찮다리.

#include <iostream>
using namespace std;

struct thing {
    int profit;
    int weight;
};

thing t[100];
int cache[100][100001] = {-1,};
int numberOfThings;
int maxWeight;

int calcEntry(int curThing, int curWeight) {
    if (curThing == numberOfThings) {
        return 0;
    }
    if (cache[curThing][curWeight] != -1) {
        return cache[curThing][curWeight];
    }
    
    cache[curThing][curWeight] = calcEntry(curThing + 1, curWeight);
    if (curWeight >= t[curThing].weight) {
        cache[curThing][curWeight] = max(cache[curThing][curWeight], calcEntry(curThing + 1, curWeight - t[curThing].weight)+ t[curThing].profit);
    }
    return cache[curThing][curWeight];
    
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(&cache[0][0], &cache[99][100000], -1);
    
    cin >> numberOfThings >> maxWeight;
    for (int i = 0; i < numberOfThings; i++) {
        cin >> t[i].weight >> t[i].profit;
    }
    cout << calcEntry(0, maxWeight) << "\n";

    
    return 0;
}
