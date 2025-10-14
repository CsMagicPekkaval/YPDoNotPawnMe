#include <iostream>
#include <stdexcept>
using namespace std;

class CppArray {
private:
    int size;
    float* value;

public:
    CppArray (int s = 8,float num = 0) {
        size = s;
        value = new float[size];
        for (int i = 0; i < size; i++)
            value[i] = num;
    }

    ~CppArray() {
        delete[] value;
    }

    // 拷貝建構子
    CppArray(const CppArray& other) {
        size = other.size;
        value = new float[size];
        for (int i = 0; i < size; i++)
            value[i] = other.value[i];
    }


    // 取得大小
    int getSize() {
        return size;
    }

    // index check
    float& operator[](int index) {
        if (index < 0 || index >= size)
            throw out_of_range("out of range ERROR");
        //cout<<value[index];
        return value[index];
    }

    // cout
    friend ostream& operator<<(ostream& out, const CppArray& arr) {
        out << "{";
        for (int i = 0; i < arr.size; i++) {
            out << arr.value[i];
            if (i != arr.size - 1)
                out << ", ";
        }
        out << "}";
        return out;
    }

    // cin
    friend istream& operator>>(istream& in, CppArray& arr) {
        for (int i = 0; i < arr.size; i++) {
            in >> arr.value[i];
        }
        return in;
    }
    //copy
    CppArray& operator=(const CppArray& other) {
    delete[] value;
    size = other.size;
    value = new float[size];

    for (int i = 0; i < size; i++)
        value[i] = other.value[i];
    return *this;
    }
};

int main() {
    /*
    CppArray arr(3);
    cin >> arr;            
    cout << arr << endl;
    //cout << arr.getSize() << endl;
    CppArray copyy(13);
    copyy = arr;
    cout << copyy << endl;;
    cout << copyy[2];
    CppArray a(3,4.5);
    cout << a;
*/
    CppArray arr(3);
    cin >> arr; 
    CppArray a = arr;
    cout << a;
    return 0;
}
