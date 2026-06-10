#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

// 商品結構
struct Product {
    string name;       // 商品名稱 
    int expiry_days;   // 有效期限 
    int popularity;    // 熱銷程度 

    // 自訂比較規則（小頂堆）
    bool operator<(const Product& other) const {
        if (expiry_days != other.expiry_days)
            return expiry_days < other.expiry_days; // 有效期限越小越優先
        return popularity > other.popularity; // 熱銷程度越高越優先
    }
};

// bubble sort
void bubble_sort(vector<Product>& products) {
    int n = products.size(); // 取得總數
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (products[j + 1] < products[j]) {  // 使用operator< 規則
                swap(products[j], products[j + 1]); // 交換
            }
        }
    }
}


int main() {
    // 開啟檔案
    ifstream inFile("d:/code/C++/Lab12/data/input2.txt");

    if (!inFile) {
        cerr << "錯誤：無法開啟檔案！請檢查檔名與路徑是否正確。" << endl;
        return 1;
    }

    int N;
    if (!(inFile >> N)) return 0; // 1. 讀取第一行的商品數量 N

    vector<Product> products(N);

    // 2. 讀取每一筆商品資料
    for (int i = 0; i < N; i++) {
        string line;
        getline(inFile >> ws, line);  // 讀取整行

        // 找最後一個空格，並指定下一格為popularity
        size_t lastSpace = line.rfind(' ');
        products[i].popularity = stoi(line.substr(lastSpace + 1));

        // 找倒數第二個空格，並指定下一格為expiry_days
        size_t secondLastSpace = line.rfind(' ', lastSpace - 1);
        products[i].expiry_days = stoi(line.substr(secondLastSpace + 1, lastSpace - secondLastSpace - 1));

        // 剩下是商品名稱
        products[i].name = line.substr(0, secondLastSpace);
    }

    inFile.close(); // 讀取完畢，關閉檔案

    bubble_sort(products);

    // 輸出排序後的商品名字
    cout << "商品排序：\n";
    for (const auto& prod : products) {
        cout <<  prod.name << "\n";
    }

    return 0;
}