#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

const int max_size_column = 76;
const auto IMAGE_WIDTH = 400;
const auto IMAGE_HEIGHT = 300;
const auto TEXT_LEFT = 20;
const auto TEXT_BASELINE = 20;
const auto TEXT_WIDTH = 50;
const auto BIN_HEIGHT = 30;
const auto BLOCK_WIDTH = 10;

void svg_text(double baseline, string text) {
    cout << "<text x='" << TEXT_LEFT << "' y='" <<baseline <<"'>"<<  text<<"</text>";
}

void svg_rect(double y, double width, string color){
    cout << "<rect x='"<< TEXT_WIDTH <<"' y='"<< y <<"' width='"<< width <<"' height='"<< BIN_HEIGHT 
    <<"' stroke='"<< color <<"' fill='"<< color <<"'/>";
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

void show_histogram_svg(const vector<int> &diagram, int BlockWidth) {
    double top = 0;
    double bin_width;
    svg_begin(400, 300);
    for(auto i : diagram){
        bin_width = BlockWidth * i;
        svg_text(top + TEXT_BASELINE, to_string(i));
        svg_rect(top, bin_width, "red");
        top += BIN_HEIGHT;
    }
    svg_end();
}

int BlockWidthRead(){
    int width;
    cerr << "Enter Width:";
    cin >> width;
    if(width > 30){
        cerr << "Error\nWidth > 30px";
        return BlockWidthRead();
    }
    if(width < 3){
        cerr << "Error!!!\nWidth < 3px";
        return BlockWidthRead(); 
    }
    return width;
    
}

template<class T>
void Read(int size, T &mas){
    cerr << "Enter numbers:";
    for(int i = 0; i< size; i++){ //read array 
        cin >> mas[i];
    }
    return;
}

void Scaling (vector<int> &mas){
    double min_del = *max_element(mas.begin(), mas.end())*1.0/max_size_column;
    for(auto i : mas){
        i = i/min_del;
    }
}
int main(){
    int len, count_pos; 
    double size_inter;
    int BlockWidth;

    cerr << "Enter number count:";
    cin >> len;
    vector<double> mas(len);
    Read<vector<double>>(len , mas);

    cerr << "Enter bin count:";
    cin >> count_pos;
    vector<int> diagram(count_pos, 0);

    sort(mas.begin(), mas.end());
    size_inter =  (mas.back() - mas.front())*1.0/count_pos;
    double tek_inter = mas.at(0)+size_inter; 
    int pos =0; 
    for(auto i: mas){
        if(i < (pos)*size_inter+tek_inter || pos == count_pos-1){
            diagram.at(pos)++;
        }else{
            pos++;
            diagram.at(pos)++;
        }
    }
    for(auto i: diagram){
        if(i >max_size_column){
            Scaling(diagram);
            break;
        }
        
    }
    BlockWidth = BlockWidthRead();
    show_histogram_svg(diagram, BlockWidth);
}