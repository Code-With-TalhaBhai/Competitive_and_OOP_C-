#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int LargestRectangularArea1(vector<int> heights){
    int size = heights.size();
    int area,max_area = 0;

    if(size == 1){
        return heights[0];
    }

    for (int i = 0; i < size-1; i++)
    {
        int width = 1;
        int left = i-1;
        int right = i+1;

        while(left>=0 && heights[left]>=heights[i]){
            width++;
            left--;
        }

        while(right<size && heights[right]>=heights[i]){
            width++;
            right++;
        }

        area = heights[i] * width;
        if(max_area <= area){

            max_area = area;
        }
    }
    return max_area;
}

void print_vect(vector<int> v){
    for(int i:v){
        cout << i << " ";
    }
    cout << endl;
}

vector<int> prev_smaller(vector<int> arr){
    int size = arr.size();
    vector<int> ans(size);
    stack<int> S;
    S.push(-1);

    for (int i = 0; i < size; i++)
    {
        int curr = arr[i];
        while(S.top() != -1 && arr[S.top()] >= curr){
            S.pop();
        }

        ans[i] = S.top();
        S.push(i);
    }
    // print_vect(ans);
return ans;
}


vector<int> next_smaller(vector<int> arr){
    int size = arr.size();
    vector<int> ans(size);
    stack<int> S;
    S.push(-1);
    for(int i=size-1; i>=0; i--){
        int curr = arr[i];
        while(S.top() != -1 && arr[S.top()] >= curr){
            S.pop();
        }

        ans[i] = S.top();
        S.push(i);
    }
    // print_vect(ans);
    return ans;
}


int LargestRectangularArea2(vector<int> heights){
    
    int max_area = INT16_MIN;
    int area,width,length;
    int size = heights.size();
    for (int i = 0; i < size; i++)
    {
        int p_smaller = prev_smaller(heights)[i];
        int n_smaller = next_smaller(heights)[i];
        if (next_smaller(heights)[i] == -1){
            n_smaller = size;
        }

        length = heights[i];
        width = n_smaller - p_smaller - 1;
        area = length * width;
        if(max_area<area){
            max_area = area;
        }
    }
    return max_area;
}



int main(){

    // vector<int> heights = {2,1,5,6,2,3};
    // vector<int> heights = {6,2,5,4,1,5,6};
    // vector<int> heights = {5,8,9,10,1,5,6};
    vector<int> heights = {3, 5, 1, 7, 5, 9};
    // vector<int> heights = {2,0,2};
    // vector<int> heights = {2,4};
    // vector<int> heights = {4,2};
    // vector<int> heights = {0};
    // vector<int> heights = {1};
    // vector<int> heights = {1,1};
    // vector<int> heights = {0,9};

    // vector<int> heights(300,1);

    // Without Optimization (O(n*2)) Not always gives correct area but mostly does
    cout << "The largest rectangular area is: " << LargestRectangularArea1(heights) << endl;

    // With Stack(Optimized(O(n)))
    cout << "The largest rectangular area with stack is: " << LargestRectangularArea2(heights) << endl;

    // prev_smaller(heights);
    // next_smaller(heights);

    return 0;
}