#include <iostream>
#include <string>
#include <map>
using namespace std;

class Barcode{
    private:
        const string barcode;

    public:
        Barcode() : barcode(""){}
        Barcode(string barcode) : barcode(barcode){}
        Barcode& operator = (const Barcode& obj){
            return *this;
        }

        bool isEmpty(){
            return barcode == "";
        }

        bool isEnd(){
            return barcode == "end";
        }

        string get_itemcode(){
            if(barcode.substr(0, 2) != "02") return barcode.substr(0, 12);
            return barcode.substr(2, 5);
        }

        double get_price(){
            return stoi(barcode.substr(7, 5));
        }

        bool isChecksumOkay(){
            int check = barcode.back() - '0';
            int sum = 0;
            for (int i = 0; i < 12; ++i) sum += barcode[i] - '0';
            sum %= 10;
            return sum == check;
        }
};

class Item{
    private:
        double atr1, atr2, error;
        //Normal : Price, Standard Weight, Error
        //Sell by Weight : Weight per 100yen, Package Weight, Error
        //culculate weight from barcode

    public:
        Item() : atr1(0), atr2(0), error(0){}
        Item(double atr1, double atr2, double error) : atr1(atr1), atr2(atr2), error(error){}

        pair<double, double> culc_weight(Barcode barcode) const{
            string itemcode = barcode.get_itemcode();

            if(itemcode.size() == 12) return {atr2, error};

            double price = barcode.get_price();
            double weight = atr1 * price / 100 + atr2;

            return {weight, error};
        }

        //culculate price from barcode
        double culc_price(Barcode barcode) const{
            string itemcode = barcode.get_itemcode();

            if(itemcode.size() == 12) return atr1;

            return barcode.get_price();
        }
};

class BarcodeReader{
    private:
        map<string, Item> Items;

        Barcode prevcode;
        Item prevItem;
        bool case1;
        bool case2;
        double prevweight;
        double totalprice;

    public:
        BarcodeReader() : Items{}, prevcode(""), prevItem(), case1(false), case2(false), prevweight(0), totalprice(0){}
        BarcodeReader(map<string, Item> item) : Items(item), prevcode(""), prevItem(), case1(false), case2(false), prevweight(0), totalprice(0){}

        void read_barcode(Barcode barcode, double totalweight){
            if(!prevcode.isEmpty()){
                add_price();
                if(!judge_case2(prevcode)) judge_case1(prevcode, totalweight - prevweight);
            }
            
            prevcode = barcode;
            prevweight = totalweight;
        }

        void add_price(){
            totalprice += prevItem.culc_price(prevcode);
        }

        Item get_item(Barcode &barcode)
        {
            return Items.at(barcode.get_itemcode());
        }

        //商品が存在するか確認
        bool isItemExist(Barcode& barcode){
            string itemcode = barcode.get_itemcode();
            return Items.count(itemcode);
        }

        //読み取ったバーコードが大丈夫か？(Case 1)
        bool judge_case1(Barcode& barcode, const double& weightdif){
            Item item = get_item(barcode);
            double sd_weight, error;
            tie(sd_weight, error) = item.culc_weight(barcode);

            if((weightdif < sd_weight - error) | (weightdif > sd_weight + error)){
                case1 = true;
                return true;
            }

            return false;
        }

        //読み取ったバーコードが大丈夫か？(Case 2)
        bool judge_case2(Barcode& barcode){
            if(!barcode.isChecksumOkay()) case2 = true;
            else if(!isItemExist(barcode)) case2 = true;
            else return false;
            return true;
        }

        void print_status(){
            if(case1 & case2) cout << "staff call: 1 2" << endl;
            else if(case1) cout << "staff call: 1" << endl;
            else if(case2) cout << "staff call: 2" << endl;
            else cout << totalprice << endl;
        }
};


int main(int argc, char *argv[]){
    int n;
    cin >> n;

    map<string, Item> Items; //(itemcode, Item)
    for (int i = 0; i < n; ++i){
        string itemcode;
        cin >> itemcode;
        double atr1, atr2, atr3;
        cin >> atr1 >> atr2 >> atr3;
        Items[itemcode] = {atr1, atr2, atr3};
    }

    while(1){
        string startflag;
        cin >> startflag;
        if(startflag.empty()) break;

        BarcodeReader reader(Items);

        while(1){
            string code;
            double weight;
            cin >> code >> weight;

            Barcode barcode(code);

            reader.read_barcode(barcode, weight);

            if(barcode.isEnd()) break;
        }
        reader.print_status();
    }

    return 0;
}
