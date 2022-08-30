#include <iostream>
#include <vector>
using namespace std;

int Max(std::vector<int> vec) {
    int max = vec[0];
    for (int i = 1; i < vec.size(); i++)
        if (vec[i] > max)
            max = vec[i];
    return max;
}

void radixSort(vector<int>& arr) {
    int max = Max(arr);
    int radix = 1;
    while (max / radix)
    {
        
        vector<vector<int>> sets(10,vector<int>());
        for (int i=0;i<arr.size();i++) {
            int digit = arr[i] / radix % 10;
            sets[digit].push_back(arr[i]);
        }
        int k = 0;
        
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < sets[i].size(); j++)
            {
                arr[k] = sets[i][j];
                k++;
            }
        }
        radix *= 10;
    }
}

int main() {

    vector<int> vector{ 2,3,1,5,10,20,19,1,3,2,11 };
    radixSort(vector);
    for (int i = 0; i < vector.size(); i++)
        cout << vector[i] << endl;
    return 0;
}