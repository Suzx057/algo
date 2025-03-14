#include<iostream>
#include<algorithm>
using namespace std;
#define ITEMS 5
#define MAX_WEIGHT 100
int weight[ITEMS] = {1,2,3,4,5};
int value[ITEMS] = {1,2,3,4,5};

int memo[ITEMS][100];
int init(){
    for(int i = 0 ; i<=5 ; i++){
        for(int j = 0 ; j<=100 ; j++){
            memo[i][j] = -1;
        }
    }
}
int M(int N, int W){
    if(N == 0 || W == 0 ) return 0;
    if(weight[N] > W) return M(N-1,W);
    else{
        return max(M(N-1,W),M(N-1,W-weight[N]) +value[N]);
    }
}

int M_topdown(int N, int W){
    if(memo[N][W] != -1) return memo[N][W];
    if(N == 0 || W == 0 ){
        memo[N][W] = 0;
        return memo[N][W];
    }
    if(weight[N] > W){
        memo[N][W] =  M_topdown(N-1,W);
        return memo[N][W];
    }
    else{
        memo[N][W] =  max(M_topdown(N-1,W),M_topdown(N-1,W-weight[N]) + value[N]);
        return memo[N][W];
    }
}


int M_bottomup(int N, int W){
    for( int j =0;j<=W;j++){
        memo[0][j] = 0;
    }
    for( int i =0;i<=W;i++){
        memo[i][0] = 0;
    }
    for( int i =1;i<=N;i++){
        for(int  j=1;j<=W;j++){
            if(weight[i] > W){
                memo[i][j] = memo[N-1],[W];
            }
            else{
                memo[i][j] = max(memo[N-1][W],memo[N-1][W-weight[i]] + value[i]);
            }
        }
    }
    return memo[N][W];
}



void print_memo(){
    for(int i =0 ; i<=ITEMS ; i++){
        for(int j = 0 ;j<=MAX_WEIGHT;j++){
            cout<< memo[i][j] << " ";
        }
        cout<<endl;
    }
}
int main(){
    init();
    M_topdown();
    print_memo();

    intit();
    M_bottomup();
    printmemo();
    return 0;
}