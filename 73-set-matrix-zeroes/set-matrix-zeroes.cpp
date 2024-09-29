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
        vector<int>row(m,0);
       vector<int>col(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                   row[i]=1;
                   col[j]=1;
                   
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i]||col[j]){
                    matrix[i][j]=0;
        
    }}}
}};