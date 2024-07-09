#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#include<vector>
#include<string>
using namespace std;
void find_minmax(vector<int> &numbers, int &max, int &min );
void svg_rect(double y, double width, string color);
void svg_text(double baseline, string text);
void svg_begin(double width, double height);
void svg_end();

#endif // HISTOGRAM_H_INCLUDED