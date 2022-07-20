#include <iostream>
using namespace std;

int main()
{
    int array[] = {22, 12, 35};
    int len = 3;
    for (int i = 0; i < len; i++)
        cout << array[i] << endl;
    for (int i = 0; i < len - 1; i++) {
        int k = 0;
        for (int j = 0; j < len - 1; j++) {
            k++;
            if (array[k - 1] > array[k]) {
                int temp = array[k - 1];
                array[k - 1] = array[k];
                array[k] = temp;
            }
        }
    }
    for (int i = 0; i < len; i++)
        cout << array[i] << endl;
}
