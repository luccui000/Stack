// Author : Luc Cui
// Date : 01/10/2019

#include <iostream>
using namespace std;


// template <typename T>
/************************************************************************************************
 * Class : Stack (Ngan Xep <=> Last In First Out)
 * Ham : push, pop , top, getSize
 * Mo ta : Day cac Gia tri vao Stack theo quy tac cai nao vao truoc se ra sao va nguoc lai
 *     - pushElem : Them gia tri vao Stack
 *     - pop : Xoa Gia tri Cuoi cung cua Stack
 *     - top : Tra ve gia tri Cuoi cung cua Stack
 *     - isEmpty : Kiem Tra Stack co rong hay khong neu rong thi thong bao
 *     - isFull : Kiem tra Stack da day chua neu da day thi thong bao
 ***********************************************************************************************/

class Stack{
    private:
        int capacity  = 100;
        int arr[100];
        int topofStack = -1;
    public:
        // Stack();
        // ~Stack();
        // Kiem Tra Stack rong hay khong
        bool isEmpty();
        // Kiem tra Stack day chua
        bool isFull();
        // Them phan tu vao Stack
        void pushElem(int elem);
        // Loai bo Phan Tu cuoi cung ra khoi Stack
        void pop();
        // Tra ve Gia tri tren cung cua Stack
        int top();
        int getSize();
        // Xuat Gia tri ra man hinh
        void printScreen();
};
bool Stack::isEmpty(){
    // Neu Stack rong thi gia tri topofStack la -1
    if(topofStack == -1)      
        return true;
    else
        return false;
}

bool Stack::isFull(){
    if(capacity - 1 < topofStack)
        return true;
    return false; 
}
void Stack::pushElem(int elem){
    if(!isFull()){
        topofStack++;
        arr[topofStack] = elem;      // Chen gia tri elem vao mang
    }else
        cout << "\nSTACK::FULL\n";
}
void Stack::pop(){
    if(!isEmpty())
        topofStack--;                 // Giam kich thuoc cua Stack hien tai di
    else 
        cout << "\nSTACK::NOTHINGS\n"; // Truong hop Stack rong
} 
int Stack::top(){
    if(!isEmpty())                     // Kiem tra Stack co rong hay ko neu rong thi return 0;
        return arr[topofStack];
    return 0;
}
void Stack::printScreen(){
    if(!isEmpty()){
        for(int i = topofStack; i >= 0;i--){  // Duyet Tu Dinh xuong toi goc 
            cout << arr[i] << "\t";
        }
    }else
        cout << "STACK::NOHAVEELEMENTS";      // Stack Rong thi Thong Bao 
}
int Stack::getSize(){
    return topofStack + 1;                   // Tra ve kich thuoc phan phan chua trong Stack
}
int main(){
    Stack stk;
    stk.pushElem(12);
    stk.pushElem(1);
    stk.pushElem(-1);
    stk.pushElem(2);
    stk.pushElem(7);
    stk.pushElem(-3);
    stk.pushElem(9);
    stk.printScreen();
    stk.pop();
    cout << "\nAfter Pop 9 : \n";
    stk.printScreen();
    cout << "\nTop : " << stk.top();
    cout << endl;
    return 0;
}