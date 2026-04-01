#include <iostream>
#include <string>
using namespace std;

struct Student { // 建立一個名為Student的結構型態，裡面包含int、string等不同類型的資料型態
    int id;
    string name;
    int chinese;
    int english;
    int math;
    int social;
    int science;
};

void updateMath(Student* s) { // 函式參數要改成指標(Student*)
    s->math = 100; // 使用傳進來的地址(&one)讓函式找到main 裡的math 並修改(call by address)
}

void printStudent(Student* s) { // 函式參數要改成指標(Student*)
    // 使用傳進來的地址(&one)讓函式找到學生的資料並輸出
    cout << "學生編號: " << s->id << endl;
    cout << "姓名: " << s->name << endl; 
    cout << "數學成績: " << s->math << endl;
}


int main() {
    Student one; // 創造一個同學
    Student* ptr = &one; // 用pointer 取得第一個同學的記憶體地址

    // 用「->變數名稱」的方式寫入同學的資料
    ptr->id = 1;
    ptr->name = "張小美";
    ptr->chinese = 77;
    ptr->english = 83;
    ptr->math = 86;
    ptr->social = 68;
    ptr->science = 91;

    // &one 代表傳入第一個同學的記憶體地址
    updateMath(&one);
    printStudent(&one);

    return 0;
}