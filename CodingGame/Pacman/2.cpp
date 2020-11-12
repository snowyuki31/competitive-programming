#include <bits/stdc++.h>
#include <random>
const int INF = 1e9;
const long long MOD = 1000000007;
const double PI = acos(-1.0);
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (n); ++i)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; --i)
#define perm(c) sort(ALL(c));for(bool c##p=1;c##p;c##p=next_permutation(ALL(c)))
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define pb push_back
#define to_s to_string
#define len(v) (ll)v.size()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
#define print(x) cout << (x) << '\n'
#define drop(x) cout << (x) << '\n', exit(0)
#define debug(x) cout << #x << ": " << (x) << '\n'
using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
typedef vector<ll> vec;
typedef vector<vector<ll>> vec2;
typedef vector<vector<vector<ll>>> vec3;
template<class S, class T> inline bool chmax(S &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class S, class T> inline bool chmin(S &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
inline ll msb(ll v) { return 1 << (31 - __builtin_clzll(v)); }
inline ll devc(ll x, ll y) { return (x + y - 1) / y; }
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
vector<int> dy{0, -1, 0, 1}, dx{-1, 0, 1, 0};

struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
    }
} iosetup;

const int c_pellet = 1000;
const int c_super_pellet = 5000 * 1000 * 1000;
const int uc_pellet = 1000;


/**
 * Grab the pellets as fast as you can!
 **/

int width, height;

struct pacman {
    int id;          
    int x;              
    int y;              
    string type;     
    int speed; 
    int ability;

    int prevx;
    int prevy;
    bool isRandom;
    int movingx;
    int movingy;

    bool moved;

    int reg_at;

    pacman() : id(0), x(0), y(0), type(""), speed(0), ability(0), prevx(-1), prevy(-1), isRandom(false), movingx(-1), movingy(-1), moved(false), reg_at(0) {}

    pacman(int id, int x, int y, string type, int speed, int ability, int prevx, int prevy, bool isRandom) 
        : id(id), x(x), y(y), type(type), speed(speed), ability(ability), prevx(prevx), prevy(prevy), isRandom(isRandom) {}
};


//commands
bool move(pacman& m, int y, int x){
    if(x == -1 or y == -1) return false;
    if(m.moved) return false;

    m.prevy = m.y, m.prevx = m.x;
    cout << "MOVE " << m.id << " " << x << " " << y << " (" << x << "," << y << ")" << "|";
    m.moved = true;
    return true;
}

bool speed(pacman& m){
    if(m.moved) return false;
    cout << "SPEED " << m.id << "|";
    m.moved = true;
    return true;
}

bool change_type(pacman& me, pacman& enemy){
    if(me.moved) return false;
    if(enemy.type == "DEAD") return false;
    string type;
    if(enemy.type == "ROCK") type = "PAPER";
    if(enemy.type == "PAPER") type = "SCISSORS";
    if(enemy.type == "SCISSORS") type = "ROCK";
    if(me.type == type) return false;
    cout << "SWITCH " << me.id << " " << type << "|";
    me.moved = true;
    return true;
}

bool change_type(pacman& me, string type){
    if(me.moved) return false;
    cout << "SWITCH " << me.id << " " << type << "|";
    me.moved = true;
    return true;
}

//Tools
template< typename T >
T sample(vector<T>& in){
    random_device rnd;                        
    mt19937 mt(rnd());                       
    uniform_int_distribution<> randp(0, in.size());
    return in[randp(mt)];
}

bool isOkay(vector<string>& grid, int& y, int& x){
    int height = grid.size(), width = grid.front().size();
    y = (y + height) % height;
    x = (x + width) % width;

    if (grid[y][x] == '#') return false;
    return true;
}

bool isMoved(pacman& m){
    return !(m.prevy == m.y and m.prevx == m.x);
}

int isClose(pacman& a, pacman& b, vector<string>& grid, int dist){
    //cerr << a.id << " and " << b.id << " are close?" << endl;
    //cerr << "distance : " << abs(a.x - b.x) + abs(a.y - b.y) << endl;
    queue<pair<P, int>> que;
    set<P> visit;

    if(b.type == "DEAD") return false;

    que.push({{a.y, a.x}, 0});
    visit.insert({a.y, a.x});
    while(!que.empty()){
        auto [now, d] = que.front();
        auto [y, x] = now;
        que.pop();

        if(y == b.y and x == b.x) return d;
        if(d > dist) continue;

        rep(i, 4){
            int nexty = y + dy[i], nextx = x + dx[i];
            if(visit.count({nexty, nextx})) continue;
            if(!isOkay(grid, nexty, nextx)) continue;

            que.push({{nexty, nextx}, d + 1});
            visit.insert({nexty, nextx});
        }
    }

    return false;
}

bool isWin(pacman& a, pacman& b){
    if(b.ability == 0) return false;
    if(b.type == "DEAD") return true;
    if(a.type == "ROCK" and b.type == "SCISSORS") return true;
    if(a.type == "SCISSORS" and b.type == "PAPER") return true;  
    if(a.type == "PAPER" and b.type == "ROCK") return true;
    return false;
}

bool isEven(pacman& a, pacman& b){
    if(a.type == b.type) return true;
    return false;
}

vector<P> get_safezone(set<P> &safe){
    vector<P> cand;
    for(auto& s : safe) cand.pb(s);
    return cand;
}
int culc_dist(pacman& a, pacman &b){
    return (abs(a.x - b.x) + abs(a.y - b.y));
}

P sample_optimized(pacman& m, vector<P>& cand){
    P res;
    int score = INF;
    for(auto& c : cand){
        int nd = abs(m.y - c.first) + abs(m.x - c.second);
        if(chmin(score, nd)) res = c;
    }
    return res;
}


bool move_randomly(pacman& m, vector<P>& cand, set<P>& ls, bool exploring = false){
    if(m.moved) return false;

    if(!ls.count({m.movingy, m.movingx})) m.isRandom = false;
    if(m.x == m.movingx and m.y == m.movingy) m.isRandom = false;
    if(!isMoved(m)) m.isRandom = false;
    if(m.isRandom) return move(m, m.movingy, m.movingx);

    if(cand.empty()) return false;

    int y, x;
    if(exploring) tie(y, x) = sample_optimized(m, cand);
    else{
        // random_device rnd;
        // mt19937 mt(rnd());
        // uniform_int_distribution<> randp(0, 100);
        // if(randp(mt) % 2 == 0){
        //     y = m.y;
        //     x = m.x;
        // }else{
        //     tie(y, x) = sample(cand);
        // }
        tie(y, x) = sample(cand);
    }

    m.isRandom = true;
    m.movingy = y, m.movingx = x;
    return move(m, y, x);
}

bool escape(pacman& m, vector<pacman>& enemy, vector<string>& grid){
    if(m.moved) return false;
    //逃げれるターン数で評価したい
    int y = m.y, x = m.x;
    int dist = 0;
    for(auto& e : enemy) dist += isClose(m, e, grid, 6);
    rep(i, 4){
        int nexty = y + dy[i], nextx = x + dx[i];
        if(isOkay(grid, nexty, nextx)){
            m.y = nexty, m.x = nextx;
            int nextd = 0;
            for(auto& e : enemy) nextd += isClose(m, e, grid, 8);
            if(nextd > dist){
                return move(m, nexty, nextx);
            }
        }
    }
    return false;
}

bool buttle(pacman& m, vector<pacman>& enemy, vector<string>& grid, int turn){
    if(m.moved) return false;
    int ct = 0;
    for(auto& e : enemy) if(turn - e.reg_at <= 3) ct += !!isClose(m, e, grid, 4);

    for(auto& e : enemy){
        if(turn - e.reg_at > 3) continue;
        int dist = 1;
        // if(m.speed != 0 and e.speed != 0) dist = 4;
        // else if(m.speed != 0) dist = 2; //自分がスピード
        // else if(e.speed != 0) dist = 2; //相手がスピード
        // else dist = 1;

        if(isClose(m, e, grid, 4) and ct >= 2) return false; 

        if(isClose(m, e, grid, dist)) cerr << "enemy " << e.id << " is now at " << isClose(m, e, grid, dist) << "from " << m.id << endl;

        if(isClose(m, e, grid, dist)){
            //両方スピード使ってる場合、4マス以内だと危ない
            //片方だと3マス以内で危ない
            //どちらも使っていない場合、2マス以内で危ない

            //到達範囲内にいる場合
            //勝てる -> 倒す
            if(isWin(m, e)) if(m.speed != 0 and e.speed == 0) {
                //if(turn < 30) return escape(m, enemy, grid);
                cerr << "pacman " << m.id << " fighted!" << endl;
                return move(m, e.y, e.x);
            }

            //自分が能力使える場合
            if(m.ability == 0){
                //じゃんけんの読みは有効ではない？
                // //相手が能力使える場合
                // //相手が自分に勝つように変化するのに合わせる
                // if(e.ability == 0){
                //     if(m.type == "PAPER") return change_type(m, "ROCK");
                //     if(m.type == "ROCK") return change_type(m, "SCISSORS");
                //     if(m.type == "SCISSORS") return change_type(m, "PAPER");
                // }

                //相手が能力使えない場合
                //相手に勝てるように変化する
                if(turn < 30 and !isWin(e, m)) return speed(m);
                return change_type(m, e);
            }
            //自分が能力使えない場合、必ず逃げる
            cerr << "pacman " << m.id << " escaped!" << endl;
            return false;
        }

        // if(isClose(m, e, grid, e.ability)){
        //     //相手のabilityクールダウンターン数よりも近くにいる場合 
        //     //勝てる -> 倒しに行く
        //     if(isWin(m, e)) move(m, e.y, e.x);

        //     // //能力使える & 勝てない -> 変化
        //     // if(!m.ability) if(!isWin(m, e)) change_type(m, e);

        //     //すぐ勝てない->一旦スルー
        //     return false;
        // }
    }

    return false;
}

P beamsearch(pacman& m, vector<vector<P>>& pellet, set<P>& pacpos, vector<string>& grid, int depth, int turn, int totpellet, int remain){
    //BFSでpelletを評価していく
    //探索して、最良のルートを取る
    priority_queue<pair<double, P>> pq;
    set<P> visit;
    bool okay = true;
    auto dfs = [&](auto&& self, P now, double val, int d)->void {
        if(d > depth) return;
        if(!okay) return;

        rep(i, 4){
            int nexty = now.first + dy[i], nextx = now.second + dx[i];
            if (!isOkay(grid, nexty, nextx)) continue;
            if (visit.count({nexty, nextx})) continue;

            auto [eval, decay] = pellet[nexty][nextx];
            double score = double(eval) / pow(double(turn - decay + 1), 2);

            visit.insert({nexty, nextx});
            if(pacpos.count({nexty, nextx})) okay = false;
            self(self, {nexty, nextx}, val + score, d + 1);
            visit.erase({nexty, nextx});
        }


        //if(d == 1 and val < 1500 and remain > totpellet / 2) return;
        if(!okay) pq.push({val / pow((d + 1), 2), now});
        else pq.push({val / (d + 1), now});
        okay = true;
    };

    visit.insert({m.y, m.x});
    dfs(dfs, {m.y, m.x}, 0, 0);

    cerr << "score : " << pq.top().first << endl;

    if(pq.top().first <= 50){
        cerr << "too low score ";
        return {-1, -1};
    }

    return pq.top().second;
}

bool search_move(pacman& m, vector<vector<P>>& pellet, set<P>& pacpos, vector<string>& grid, int depth, int turn, int totpellet, int remain){
    if(m.moved) return false;
    auto [y, x] = beamsearch(m, pellet, pacpos, grid, depth, turn, totpellet, remain);
    if(x == -1 or y == -1) return false;
    return move(m, y, x);
}

int main(){
    // Get Grid//
    cin >> width >> height;
    cin.ignore();
    vector<string> grid(height);
    for (int i = 0; i < height; i++){
        string row;
        getline(cin, row); // one line of the grid: space " " is floor, pound "#" is wall
        grid[i] = row;
    }

    auto plot = [&](int y, int x) {
        return y * width + x;
    };

    set<P> unchecked;
    set<P> unvisited;
    int totpellet = 0;

    vector<vector<P>> pellet(height, vector<P>(width, {-INF, 0}));

    for(int y = 0; y < height; ++y) for(int x = 0; x < width; ++x) if (isOkay(grid, y, x)){
        ++totpellet;
        unchecked.insert({y, x});
        unvisited.insert({y, x});
        pellet[y][x] = {uc_pellet, 0}; //最初は1あるとして初期化 //見てない部分は高めのスコアにしておく
    }


    //game loop
    int turn = 0;
    vector<pacman> me(5);
    vector<pacman> enemy(5);
    while (1){
        ++turn;
        int myScore;
        int opponentScore;
        cin >> myScore >> opponentScore;
        cin.ignore();
        int visiblePacCount; // all your pacs and enemy pacs in sight
        cin >> visiblePacCount;
        cin.ignore();

        cerr << "turn  : " <<  turn << endl;

        vector<pacman> survive;
        vector<pacman> survive_enemy;
        set<P> pacpos;
        set<P> ally;
        set<P> vis_enemy;

        for (int i = 0; i < visiblePacCount; i++){
            int pacId;          
            bool mine;          
            int x;              
            int y;               
            string typeId;       
            int speedTurnsLeft;  
            int abilityCooldown; 
            cin >> pacId >> mine >> x >> y >> typeId >> speedTurnsLeft >> abilityCooldown;
            cin.ignore();

            pacman& now = (mine ? me : enemy)[pacId];

            now.id = pacId, now.x = x, now.y = y, now.type = typeId, now.speed = speedTurnsLeft, now.ability = abilityCooldown;

            now.moved = false, now.reg_at = turn;

            (mine ? survive : survive_enemy).pb((mine ? me : enemy)[pacId]);
            unchecked.erase({y, x});
            unvisited.erase({y, x});
            pacpos.insert({y, x});

            if(mine) ally.insert({y, x});
            else vis_enemy.insert({y, x});

            pellet[y][x] = {0, turn}; //Pacmanのいる位置の評価値は下げる
        }

        int visiblePelletCount; // all pellets in sight
        cin >> visiblePelletCount;
        cin.ignore();

        set<P> visible_pellet;
        set<P> visible_super_pellet;
        for (int i = 0; i < visiblePelletCount; i++){
            int x;
            int y;
            int value; // amount of points this pellet is worth
            cin >> x >> y >> value;

            cin.ignore();
            visible_pellet.insert({y, x});
            if(turn == 1 and value != 1) visible_super_pellet.insert({y, x});

            //見た情報は高い確信度
            if(value == 1) pellet[y][x] = {c_pellet, turn}, cerr << y << " " << x << ":" << pellet[y][x].second << endl;
            else pellet[y][x] = {c_super_pellet, turn}; //5マス先までは10倍以上の価値を持たせる
        }
        if(turn == 1) totpellet += len(visible_super_pellet) * 9;

        /* TODO: 
            - 敵位置スコアの管理
            - 評価関数の最適化
            - 初期のマップ探索(1000 ms)の有効活用
        */

        //パックマンの視点管理
        //現在位置の上下左右を見て、pelletが無ければデータを消していく
        //unchecked候補からも消す
        for(auto & m : survive){
            int nowy = m.y, nowx = m.x;
            while(isOkay(grid, nowy, nowx)){
                if(!visible_pellet.count({nowy, nowx})) pellet[nowy][nowx] = {0, turn};
                unchecked.erase({nowy, nowx});
                ++nowy;
            }
            nowy = m.y;
            while(isOkay(grid, nowy, nowx)){
                if(!visible_pellet.count({nowy, nowx})) pellet[nowy][nowx] = {0, turn};
                unchecked.erase({nowy, nowx});
                --nowy;
            }
            nowy = m.y;
            while(isOkay(grid, nowy, nowx)){
                if(!visible_pellet.count({nowy, nowx})) pellet[nowy][nowx] = {0, turn};
                unchecked.erase({nowy, nowx});
                ++nowx;
            }
            nowx = m.x;
            while(isOkay(grid, nowy, nowx)){
                if(!visible_pellet.count({nowy, nowx})) pellet[nowy][nowx] = {0, turn};
                unchecked.erase({nowy, nowx});
                --nowx;
            }
        }
        //視点管理
        set<P> sight;
        for(auto& m : survive){
            int nowy = m.y, nowx = m.x;
            while(isOkay(grid, nowy, nowx)) sight.insert({nowy, nowx}), ++nowy;
            nowy = m.y;
            while(isOkay(grid, nowy, nowx)) sight.insert({nowy, nowx}), --nowy;
            nowy = m.y;
            while(isOkay(grid, nowy, nowx)) sight.insert({nowy, nowx}), ++nowx;
            nowx = m.x;
            while(isOkay(grid, nowy, nowx)) sight.insert({nowy, nowx}), --nowx;
        }
        //enemyの情報修正
        for(auto& e : enemy){
            //視野にいるのに、目撃されていない  :: どこかに逃げていった場合
            if(sight.count({e.y, e.x}) and !vis_enemy.count({e.y, e.x})) e.y = -1000, e.x = -1000;
        }
        //super pelletの情報修正
        for(auto& s : visible_super_pellet){
            //super pelletとして記録されているのに、目撃されていない
            if(!visible_pellet.count(s)){
                pellet[s.first][s.second] = {0, turn};
            }
        }

        //debug
        // rep(i, height){
        //     rep(j, width){
        //         if(grid[i][j] == '#') cerr << '#';
        //         else cerr << unchecked.count({i, j});
        //     }
        //     cerr << endl;
        // }
        cerr << "Moves" << endl;
        vector<P> cand = get_safezone(unchecked);
        vector<P> unvis = get_safezone(unvisited);
        //move
        for(auto& m : survive){
            //敵が近くにいれば戦うか考える
            if(buttle(m, enemy, grid, turn)) cerr << "pacman " << m.id << " buttled!" << endl;

            //能力が使えれば、スピードする
            if(m.ability == 0) if(speed(m)) cerr << "pacman " << m.id << " speed!" << endl;

            //前回から動いていない場合
            if(!isMoved(m)) if(move_randomly(m, cand, unchecked)) m.isRandom = false, cerr << "Pacman " << m.id << " because of no change in pos" << endl;

            //それ以外は探索
            if(search_move(m, pellet, pacpos, grid, 15, turn, totpellet, totpellet - myScore - opponentScore)) cerr << "pacman " << m.id << " move with search" << endl;

            //残りの探索
            if(move_randomly(m, cand, unchecked, true)) cerr << "Pacman " << m.id << " searching unchecked zone" << endl;

            //候補がない場合
            if(move_randomly(m, unvis, unvisited, true)) cerr << "Pacman " << m.id << " searching unvisited zone" << endl;
        }
        cerr << endl;
        cout << endl;

        for(auto& m : survive) me[m.id] = m;
    }
}