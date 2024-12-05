#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>


// Test
void read_left_and_right(std::vector<double> &direction, const std::string file_name){

    std::ifstream myfile(file_name, std::ios::in);
    double next;

    while (myfile>> next) {
        direction.push_back(next);
    }

    std::sort(direction.begin(), direction.end());
    for (int i = 0; i < 5; i++) {
        std::cout << direction[i] << std::endl;
    }
    std::cout << "done the first" << std::endl;
}

int main(){

    std::vector<double> left;
    std::vector<double> right;
    read_left_and_right(left , "./left");
    read_left_and_right(right, "./right");
    int counter = 0 ;
    long double total = 0;
    for (size_t i = 0; i < left.size(); i++) {
        for (int j = 0 ; j < left.size(); j++) {
            if (left[i] == right[j]) {
                counter ++;
                // A bit of optimization 
            }else if(left[i] < right[j]){
                break;
            }
        }
        std::cout << left[i] << " * " << counter <<std::endl;
        total += left[i] * counter;
        counter = 0;
    }
    printf("%LF\n", total);




    return 0;
}
