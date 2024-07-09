#include<vector>
#include"histogram.h"
using namespace std;
void find_minmax(vector<int> &numbers, int &max, int &min ){
    min = numbers[0];
    max = numbers[0];
    for (double number : numbers) {
        if (number < min) {
            min = number;
        }
        if (number > max) {
            max = number;
        }
    }
}