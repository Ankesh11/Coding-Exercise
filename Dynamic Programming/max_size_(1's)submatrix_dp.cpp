#include <bits/stdc++.h>
using namespace std;
int largest_rectangle_in_histogram(int hist[], int n){
    stack<int> stk;
    int top, max_area = 0, area_with_top;
    int i=0;
    while(i<n){
        if(stk.empty() || hist[stk.top()]<=hist[i])
            stk.push(i++);
        else{
            top = stk.top();
            stk.pop();
            if(stk.empty())
                area_with_top = hist[top]*i;
            else
                area_with_top = hist[top]*(i-stk.top()-1);
            
            max_area = max(max_area, area_with_top);
        }
    }
    while(!stk.empty()){
        top = stk.top();
        stk.pop();
        if(stk.empty())
            area_with_top = hist[top]*i;
        else
            area_with_top = hist[top]*(i-stk.top()-1);
        
        max_area = max(max_area, area_with_top);
    }
    return max_area;
}
int largest_rectangle(int mat[100][100], int m, int n){
    int level[100];
    int level_area;
    int max_area = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0)
                level[j] = mat[i][j];
            else{
                if(mat[i][j]==1)
                    level[j] = level[j]+mat[i][j];
                else
                    level[j] = 0;
            }
        }
        level_area = largest_rectangle_in_histogram(level, n);
        max_area = max(max_area, level_area);
    }
    return max_area;
}
int main() {
	int arr[100][100] = {{1,1,0,0,1,0},
	                     {0,1,1,1,1,1},
	                     {1,1,1,1,1,0},
	                     {0,0,1,1,0,0}};
	int m = 4;
	int n = 6;
	int res = largest_rectangle(arr, m, n);
	cout<<res<<endl;
	return 0;
}
//Time Complexity: O(ROW*COL)
//Space Complexity: O(COL)