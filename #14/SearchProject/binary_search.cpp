#include <iostream>
using namespace std;

int main()
{
    int num, num_test, test;
    int loc_low, loc_high, loc_mid;
    int i;
    cin >> num >> num_test;
    int *arr = new int[1000000];
    for (i = 0; i < num; i++)
        cin >> arr[i];
    while (num_test--) {
        cin >> test;
        loc_low = 0;
        loc_high = num - 1;
        loc_mid = (num - 1) / 2;
        while (loc_low < loc_high) {
            if (arr[loc_mid] == test)
                break;
            else if (arr[loc_mid] < test)
                loc_low = loc_mid + 1;
            else if (arr[loc_mid] > test)
                loc_high = loc_mid;
            loc_mid = (loc_low + loc_high) / 2;
        }
        cout << arr[loc_mid] << endl;
    }
    delete[] arr;
    return 0;
}