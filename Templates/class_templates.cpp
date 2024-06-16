// template is for class is same as class is for object
// template helps to reduce making different classes for different data_types and can be accomodate with one

#include <iostream>
using namespace std;

template <class T1, class T2 = int> // instead of T1, T2 we can place any data_type while calling in main
// T2=int   means we create a default data_type of T2 which invoke when we not provide any, but have to provide angular brackets in main
class vector
{
public:
    T1 *arr;
    T2 data;
    int size;
    vector(int m, T2 data)
    {
        size = m;
        this->data = data;
        arr = new T1[size];
    }
    T1 dotProduct(vector &v)
    {
        T1 d = 0;
        for (int i = 0; i < size; i++)
        {
            d += this->arr[i] * v.arr[i];
        }
        return d;
    }

    void showData();
};

template <class T1, class T2>
void vector<T1, T2>::showData()
{
    cout << data << endl;
}

int main()
{
    vector<float, int> v1(3, 40);
    v1.arr[0] = 1.4;
    v1.arr[1] = 3.3;
    v1.arr[2] = 0.1;
    vector<float> v2(3, 52);
    v2.arr[0] = 0.1;
    v2.arr[1] = 1.90;
    v2.arr[2] = 4.1;
    float a = v1.dotProduct(v2);
    cout << a << endl;
    v2.showData();

    return 0;
}