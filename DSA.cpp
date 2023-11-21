#include <iostream>
#include<sstream>
using namespace std;

// Rewrite class Stack by array
template <typename T>
struct Stack
{
    int indexTop;
    T* arr;
    Stack()
    {
        indexTop = -1;
        arr = NULL;
    }
    void resize(int newSize)
    {
        T* newArr = new T[newSize];
        int size = min(newSize, indexTop + 1);
        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }
        if (arr != NULL)
            delete[] arr;
        arr = newArr;
    }
    void push(T val)
    {
        resize(indexTop + 2);
        arr[++indexTop] = val;
    }
    void pop()
    {
        resize(indexTop);
        indexTop--;
    }
    T top()
    {
        return arr[indexTop];
    }
    bool empty()
    {
        return indexTop == -1;
    }
    void reverse() {
        for (int i = 0; i < (indexTop + 1) / 2; i++) {
            swap(arr[i], arr[indexTop - i]);
        }
    }
};

string convert(string exp) {
    stringstream ss(exp);
    string tmp;
    while (getline(ss, tmp, '&'));
    Stack<char> s;

    for (int i = 0; i < tmp.length(); i++) {
        if (isalpha(tmp[i])) s.push(tmp[i]);
    }
    s.reverse();

    string res;
    while (!s.empty()) {
        res += "( a & ";
        res += s.top();
        res += " ) | ";
        s.pop();
    }
    res.pop_back();
    res.pop_back();
    return res;
}
int main()
{
    string s = "a & ( b | c|d|e | f | g | h)";
    cout << convert(s) << endl;
    return 0;
}