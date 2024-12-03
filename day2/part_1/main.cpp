#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>



using namespace std;
void file_reader_into_vector(const string file_name, vector<vector<int>> &myverctor){

    ifstream myfile(file_name, ios::in);
    int next;
    string line;
    while (getline(myfile,  line)) {
        vector<int> inner_vector;
        // So now the line gonna be stream and we can easily work with it.
        stringstream ss(line);
        while (ss >> next) {
            inner_vector.push_back(next);
        }
        myverctor.push_back(inner_vector);
    }

}



// ! First sloution

/// bool is_safe(vector<int> check){

//     if(check[0] < check[1]){ // for increase
//         int increase = 0;
//         for (size_t i = 0; i < check.size() - 1; i++) {

//             if(check[i] > check[i+1]){
//                 return false;

//             }else if(check[i] == check[i+1]){
//                 return false;
//             }else{
//                 increase = abs(check[i] - check[i + 1] );
//                 if(increase > 3 || increase < 1){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }else if(check[0] > check[1]){ // For decrease
//         int decrease = 0;
//         for (size_t i = 0; i < check.size() - 1; i++) {

//             if(check[i] < check[i+1]){
//                 return false;

//             }else if(check[i] == check[i+1]){
//                 return false;
//             }else{
//                 decrease = abs(check[i] - check[i + 1] );
//                 if( decrease > 3 || decrease < 1){
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }else{
//         return false;
//     }
// }


// After improvment
bool is_safe(vector<int> check){
    bool is_increase = check[0] < check[1];

    for (int i = 0; i < check.size() - 1 ; i++){
        int diff = check[i + 1] - check[i];

        if(is_increase && diff <= 0){
            return false;
        }
        if(!is_increase && diff >= 0){
            return false;
        }
         if(abs(diff) > 3 || abs(diff) < 1){
            return false;
        }
    }
    return true;
}


void print_vec(const vector<vector<int>> myvec ){

    for(auto a:myvec){
        printf("[ ");
        for (auto j : a){
            cout << j<< " ,";
        }
        printf("]\n");
    }
}

int main (int argc, char *argv[]) {
    vector<vector<int>> data;
    file_reader_into_vector("./input", data);
    int counter  = 0;

    for(auto arr : data){
        if(is_safe(arr)){
            counter ++ ;
        }
    }
    
    printf("%i", counter);
    return 0;
}




