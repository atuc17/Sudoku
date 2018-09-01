#ifndef _sodoku_
#define _sodoku_
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int a[9][9];
ifstream in;
ofstream out;
int dem = 0;
void nhap(int a[9][9]){
    in.open("input.txt", ios::in);
    int i, j;
    if(in.is_open()){
        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++)
                in >> a[i][j];
        }
    }
    in.close();
}
void xuat(int a[9][9]){
    out.open("output.txt", ios::out);
    int i, j;
    if(out.is_open()){
        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++)
                out << a[i][j] << " ";
            out << endl;
        }
    }
    out.close();
}
bool row_col_safe(int x, int y, int k){
    int i;
    for(i = 0; i < 9; i++)
        if(a[x][i] == k) return false;
    for(i = 0; i < 9; i++)
        if(a[i][y] == k) return false;
    return true;
}
bool check_area(int row_above, int row_below, int col_left, int col_right, int k){
    int i, j;
    for(i = row_above; i <= row_below; i++){
        for(j = col_left; j <= col_right; j++){
            if(k == a[i][j]) return false;
            else continue;
        }
    }
    return true;
}
bool area_safe(int x, int y, int k){
    // if(a[x][y] != 0) return false;
    if(x >= 0 && x <= 2){
        if(y >= 0 && y <= 2) return check_area(0, 2, 0, 2, k);
        else if(y >= 3 && y <= 5) return check_area(0, 2, 3, 5, k);
        else if(y >= 6 && y <= 8) return check_area(0, 2, 6, 8, k);
    }
    else if(x >= 3 && x <= 5){
        if(y >= 0 && y <= 2) return check_area(3, 5, 0, 2, k);
        else if(y >= 3 && y <= 5) return check_area(3, 5, 3, 5, k);
        else if(y >= 6 && y <= 8) return check_area(3, 5, 6, 8, k);
    }
    else if(x >= 6 && x <= 8){
        if(y >= 0 && y <= 2) return check_area(6, 8, 0, 2, k);
        else if(y >= 3 && y <= 5) return check_area(6, 8, 3, 5, k);
        else if(y >= 6 && y <= 8) return check_area(6, 8, 6, 8, k);
    }
    else return false;
}
void check(int x, int y){
    if(y == 9){
        // end line
        if(x == 8){
            xuat(a);
            exit(0);
                }
        else {
            check(x+1, 0);
        }
    }
    else if(a[x][y] == 0){
        int i;
        for(i = 1; i <= 9; i++){
            if(row_col_safe(x, y, i) && area_safe(x, y, i)){
                a[x][y] = i;
                check(x, y+1);
                a[x][y] = 0;
            }
        }
    }
    else{
        check(x, y+1);
    }
}
void solve(){
    nhap(a);
    check(0, 0);
}
#endif // _sodoku_
