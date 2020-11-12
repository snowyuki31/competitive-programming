#include <iostream>
#include <string>
#include <map>
using namespace std;

string barcode_to_itemcode(const string& barcode){
    if(barcode.substr(0, 2) != "02") return barcode.substr(0, 12);
    return barcode.substr(2, 5);
}


struct Item{
    double atr1, atr2, error;
    //Normal : Price, Standard Weight, Error
    //Sell by Weight : Weight per 100yen, Package Weight, Error
    //culculate weight from barcode
    pair<double, double> culc_weight(const string& barcode) const{
        string itemcode = barcode_to_itemcode(barcode);

        if(itemcode.size() == 12) return {atr2, error};
        double price = stoi(barcode.substr(7, 5));
        double weight = atr1 * price / 100 + atr2;

        return {weight, error};
    }

    //culculate price from barcode
    double culc_price(const string& barcode) const{
        string itemcode = barcode_to_itemcode(barcode);

        if(itemcode.size() == 12) return atr1;

        return stod(barcode.substr(7, 5));
    }
};

bool isChecksumOKay(const string& barcode){
    int check = barcode.back() - '0';
    int sum = 0;
    for (int i = 0; i < 12; ++i) sum += barcode[i] - '0';
    sum %= 10;
    return sum == check;
}

bool isItemExist(const string& barcode, const map<string, Item>& Items){
    string itemcode = barcode_to_itemcode(barcode);
    return Items.count(itemcode);
}

bool judge_case1(const string& barcode, const Item& item, const double& weightdif, bool& case1){
    double sd_weight, error;
    tie(sd_weight, error) = item.culc_weight(barcode);

    if((weightdif < sd_weight - error) | (weightdif > sd_weight + error)){
        case1 = true;
        return true;
    }

    return false;
}

bool judge_case2(const string& barcode, const map<string, Item>& Items, bool& case2){
    //チェックサムに誤り
    if(!isChecksumOKay(barcode)) case2 = true;
    //存在しない商品
    else if(!isItemExist(barcode, Items)) case2 = true;
    else return false;

    return true;
}

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

        //1回目
        string prevcode;
        double prevweight;
        cin >> prevcode >> prevweight;

        bool case1 = false, case2 = false;
        int totalprice = 0;

        while(1){
            string barcode;
            double totalweight;
            cin >> barcode;
            cin >> totalweight;

            string itemcode = barcode_to_itemcode(prevcode);
            Item prevItem = Items[itemcode];

            //価格計算
            totalprice += prevItem.culc_price(prevcode);

            //ケース1判定
            //直前がケース2でない場合
            if(!judge_case2(prevcode, Items, case2)) judge_case1(prevcode, prevItem, totalweight - prevweight, case1);
            
            if(barcode == "end") break;

            prevcode = barcode;
            prevweight = totalweight;
        }

        if(case1 & case2) cout << "staff call: 1 2" << endl;
        else if(case1) cout << "staff call: 1" << endl;
        else if(case2) cout << "staff call: 2" << endl;
        else cout << totalprice << endl;
    }

    return 0;
}
