#include <algorithm>
#include <cmath>
#include <iostream>
#include <ostream>
#include <vector>

int main(){
    std::vector<double> left = {3,4,2,1,3,3};
    std::vector<double> right = {4,3,5,3,9,3};
    // read_left_and_right(left , "./left");
    // read_left_and_right(right, "./right");
    // Since we have both lists sorted we can loop until we find a a number that is bigger than
    // the left side so then we know that there is no number will be similer to it.
    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
    for (int j = 0 ; j < right.size() ;j ++) {
        std::cout << left[j] << ",";
    }
    std::cout << std::endl;
    for (int j = 0 ; j < right.size() ;j ++) {
        std::cout << right[j] << ",";
    }
    std::cout << std::endl;
    int counter = 0 ;
    int left_counter  = 0;
    int right_counter = 0;
    long double total = 0;

    for(int i = 0; i < left.size(); i++){
        for (int j = 0 ; j < left.size(); j++) {
            if (left[i] == right[j]) {
                counter ++;
            }
        }
        std::cout << left[i] << " * " << counter <<std::endl;
        total += left[i] * counter;
        counter = 0;
    }
    printf("%LF\n", total);
}
