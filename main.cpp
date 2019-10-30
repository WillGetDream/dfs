#include <iostream>
#include "Card.h"
#include "Card.cpp"
#include "DeckOfCards.h"
#include "DeckOfCards.cpp"
#include <vector>

using namespace std;

vector<vector<Card>> vv;

void dfs(int pos, int cnt, int n, int k, Card a[],bool visited[]) {
    //已标记了k个数，输出结果
    if (cnt == k) {
        vector<Card> v;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                v.push_back(a[i]);
                cout << a[i].print() << ' ';

            }
        }
        vv.push_back(v);
        cout << endl;
        return;
    }

    //处理到最后一个数，直接返回
    if (pos == n) return;

    //如果a[pos]没有被选中
    if (!visited[pos]) {
        //选中a[pos]
        visited[pos] = true;
        //处理在子串a[pos+1, n-1]中取出k-1个数的子问题
        dfs(pos + 1, cnt + 1, n, k, a,visited);
        //回溯
        visited[pos] = false;
    }
    //处理在子串a[pos+1, n-1]中取出k个数的问题
    dfs(pos + 1, cnt, n, k, a, visited);
}
int main() {
    int i, n=7, k=5;

        Card a[n];
        DeckOfCards deck;
        bool *visited = new bool[n];
        for (i = 0; i < n; i++)
        {
           a[i] = deck.dealCard();
            visited[i] = false;
        }
        dfs(0, 0, n, k,a , visited);
        for(int i=0;i<vv.size();i++){
            cout<<vv.at(i).at(i).print()<<endl;
        }

        delete[] visited;



    getchar();
    return 0;
}
