#include <bits/stdc++.h>
using namespace std;

int find(int c, vector<int>&parent){
    if(c==parent[c]) return c;
    return parent[c] = find(parent[c],parents)
}
void union(int a, int b, vector<int>&parent, vector<int> &rank){
    int p_a = find(a,parent);
    int p_b = find(b,parent);
    if(p_a==p_b) return;
    
}