#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>


void read_left_and_right(std::vector<double> &direction, const std::string file_name){

    std::ifstream myfile(file_name, std::ios::in);
    double next;

    while (myfile>> next) {
        direction.push_back(next);
    }

    std::sort(direction.begin(), direction.end());
    // for (int i = 0; i < direction.size(); i++) {
    //     std::cout << direction[i] << std::endl;
    // }
    // std::cout << "done the first" << std::endl;
}

int main(){

    std::vector<double> left;
    std::vector<double> right;
    read_left_and_right(left , "./left");
    read_left_and_right(right, "./right");
    int counter = 0 ;
    for(int i = 0; i < left.size() ; i++){
        counter += fabs(left[i] - right[i]);

    }

    printf("%i\n", counter);




    return 0;
}
