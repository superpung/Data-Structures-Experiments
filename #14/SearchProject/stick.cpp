#include <iostream>
using namespace std;

int main()
{
    int num, i;
    int count = 0;
    cin >> num;
    unsigned int* lenList = new unsigned int[1000];
    for (i = 0; i < num; i++)
        cin >> lenList[i];
    sort(lenList, lenList + num);
    for (int i = num - 1; i > 1; i--) {
        int loc_low = 0, loc_high = i - 1;
        while(loc_low < loc_high) {
            if (lenList[loc_low] + lenList[loc_high] > lenList[i]) {
                count += (loc_high - loc_low);
                loc_high--;
            }
            else
                loc_low++;
        }
    }
    cout << count << endl;
    delete[] lenList;
    return 0;
}