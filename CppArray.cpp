#include <iostream>
#include <stdexcept>
using namespace std;

class CppArray {
private:
    int size;
    float* data;

public:
    CppArray (int s = 8) {
        size = s;
        data = new float[size];
        for (int i = 0; i < size; i++)
            data[i] = 0;
    }

    ~CppArray() {
        delete[] data;
    }

    // 取得大小
    int getSize() {
        return size;
    }

    // index check
    float& operator[](int index) {
        if (index < 0 || index >= size)
            throw out_of_range("out of range ERROR");
        return data[index];
    }

    // cout
    friend ostream& operator<<(ostream& out, const CppArray& arr) {
        out << "{";
        for (int i = 0; i < arr.size; i++) {
            out << arr.data[i];
            if (i != arr.size - 1)
                out << ", ";
        }
        out << "}";
        return out;
    }

    // cin
    friend istream& operator>>(istream& in, CppArray& arr) {
        for (int i = 0; i < arr.size; i++) {
            in >> arr.data[i];
        }
        return in;
    }

    CppArray& operator=(const CppArray& other) {
    delete[] data;
    size = other.size;
    data = new float[size];

    for (int i = 0; i < size; i++)
        data[i] = other.data[i];
    return *this;
    }
};

int main() {
    CppArray arr(3);
    cin >> arr;            // 輸入
    cout << arr << endl;   // 輸出
    CppArray copyy(3);
    copyy = arr;
    cout << copyy << endl;;
    return 0;
}
