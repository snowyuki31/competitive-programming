template< typename T >
class BinaryIndexedTree{
    private:
        vector<T> array;

    public:
        // Constructer
        BinaryIndexedTree(long long sz){
            array.assign(++sz, 0LL);
        }

        // Culuclate sum in the inclusive range [0,k]
        T sum(long long k) {
            T ret = 0;
            for (++k; k > 0; k -= k & -k) ret += array[k];
            return (ret);
        }

        // Add x to k th element
        void add(long long k, T x){
            for (++k; k < array.size(); k += k & -k) array[k] += x;
        }
};