#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
const long long MOD = 1000000007;
typedef long long ll;
typedef pair<ll, ll> P;

struct Edge {
    ll from, to, weight;
    Edge() : from(0), to(0), weight(0) {}
    Edge(ll f, ll t, ll w) : from(f), to(t), weight(w) {}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;

void add_edge(Graph &g, ll a, ll b, ll w = 1){
    g[a].emplace_back(a, b, w);
    g[b].emplace_back(b, a, w);
}

void add_arrow(Graph &g, ll a, ll b, ll w = 1){
    g[a].emplace_back(a, b, w);
}

//ダイクストラ法
//グラフgの1点sからの最短距離をO((E + V) log V)で構築
vector<ll> dijkstra(Graph &g, ll s){
    vector<ll> dist(g.size(), INF);
    priority_queue<P, vector<P>, greater<P>> que;
    dist[s] = 0;
    que.emplace(dist[s], s);
    
    while(!que.empty()){
        ll cost, idx;
        tie(cost, idx) = que.top();
        que.pop();
        if(dist[idx] < cost) continue;
        for(auto &e : g[idx]){
            auto next_cost = cost + e.weight;
            if(dist[e.to] <= next_cost) continue;
            dist[e.to] = next_cost;
            que.emplace(dist[e.to], e.to);
        }
    }
    return dist;
}