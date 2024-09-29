// #include <bits/stdc++.h>;
// using namespace std;
class Solution {
public:
// void markRow(vector<vector<int>>& matrix,int m,int n,int i){
//     for(int j=0;j<n;j++){
//         if(matrix[i][j]!=0){
//             matrix[i][j]=-1;
//         }
//     }}
// void markCol(vector<vector<int>>& matrix,int m ,int n,int j){
//        for(int i=0;i<m;i++){
//         if(matrix[i][j]!=0){
//             matrix[i][j]=-1;
//         }
//     }
// }
//    
 void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
       int col0=1;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                   matrix[i][0]=0;
                   if(j!=0)
                   matrix[0][j]=0;
                   else
                   col0=0;}

                   
                }
            }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]!=0){
                   if(matrix[i][0]==0 ||matrix[0][j]==0){
                    matrix[i][j]=0;
                   }
        
    }}}
    
    if(matrix[0][0]==0){
        for(int j=0;j<n;j++){
        matrix[0][j]=0;
    }}
    if(col0==0){
        for(int i=0;i<m;i++){
        matrix[i][0]=0;
    }
    
    }
}};