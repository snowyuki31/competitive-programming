//Def of Monoid
//Suppose that S is a set and ● is some binary opeartion S x S -> S
//then S with ● is a monoid if it satisfies the following two:
// Associativity(結合則)
//  For all a,b and c in S, the equation (a ● b) ● c = a ● (b ● c) holds
// Identitiy element(単位元の存在)
//  There exisits an element e in S such that for every element a in S,
//  the equations e ● a = a ● e = a holds

//Eample of Monoid
//+, *, and, or, xor, min, max

//Build O(N)
//Query O(log N)
//- query(a,b) : applay operation to the range [a, b)
//- update(k,x) : change k-th element to x
//- operator[k] : return k-th element

template< typename Monoid >
class SegmentTree{
    private:
        using F = function<Monoid(Monoid, Monoid)>;
        
        long long sz;
        vector<Monoid> seg;
        const F f;
        const Monoid e;

    public:
        SegmentTree(long long n, const F f, const Monoid &e) : f(f), e(e){
            sz = 1;
            while(sz < n) sz <<= 1;
            seg.assign(2 * sz, e);
        }

        void set(long long k, const Monoid &x){
            seg[k + sz] = x;
        }

        void build() {
            for (long long k = sz - 1; k > 0; --k){
                seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
            }
        }

        void update(long long k, const Monoid &x) {
            k += sz;
            seg[k] = x;
            while(k >>= 1) seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
        }

        Monoid query(long long a, long long b){
            Monoid L = e, R = e;
            for (a += sz, b += sz; a < b; a >>= 1, b >>= 1){
                if(a & 1) L = f(L, seg[a++]);
                if(b & 1) R = f(seg[--b],R);
            }
            return f(L, R);
        }

        Monoid operator[](const int &k) const {
            return seg[k + sz];
        }
};