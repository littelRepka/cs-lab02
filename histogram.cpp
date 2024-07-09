#include<vector>
#include"histogram.h"
#include<string>
#include<iostream>
using namespace std;

const auto IMAGE_WIDTH = 400;
const auto IMAGE_HEIGHT = 300;
const auto TEXT_LEFT = 20;
const auto TEXT_BASELINE = 20;
const auto TEXT_WIDTH = 50;
const auto BIN_HEIGHT = 30;
const auto BLOCK_WIDTH = 10;

void find_minmax(const vector<int> &numbers, int &max, int &min ){
    if(numbers.size() == 0){
        min = NULL;
        max = NULL;
        return;
    }
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
void svg_text(double baseline, string text) {
    cout << "<text x='" << TEXT_LEFT << "' y='" <<baseline <<"'>"<<  text<<"</text>";
}

void svg_rect(double y, double width, string color){
    cout << "<rect x='"<< TEXT_WIDTH <<"' y='"<< y <<"' width='"<< width <<"' height='"<< BIN_HEIGHT 
    <<"' stroke='"<< color <<"' fill='"<< color <<"'/>";
    //cout << "<line x1='"<< width <<"' x2='"<< width <<"' y1='"<< y <<"' y2='"<<y + BIN_HEIGHT<<"' stroke='black' stroke-width='1'/>";
}


void svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end() {
    cout << "</svg>\n";
}