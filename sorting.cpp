#include <bits/stdc++.h>
using namespace std;
/* *************SORTING ALGORITHMS************* */

//////////////////////////////////////////////////////
vector<int>selectionSort(vector<int>&nums){
    int n=nums.size();
    for(int i=0;i<n-1;i++){
        int mini =i;
        for(int j=i+1;j<n;j++){
            if(nums[j]<nums[mini]){
                mini=j;
            }
        }
      swap(nums[i],nums[mini]);
    }
    return nums;
}    //
vector<int>bubble_sort(vector<int>&nums){
    int n=nums.size();
    for(int i=1;i<n;i++){
        bool isSwap=false;
        for(int j=1;j<n-i;j++){
            if(nums[j]<nums[j-1]){
                swap(nums[j],nums[j-1]);
                isSwap=true;
                
            }
        }
          if(isSwap==false)break;
    }
    return nums;
}     //
vector<int>insertion_sort(vector<int>&nums){
    int n=nums.size();
    for(int i=0;i<n;i++){
        int j =i;
        while(j>0 &&nums[j-1]>nums[j]){
            swap(nums[j-1],nums[j]);
            j--;
            
        }
    }
    return nums;
} //
//////////////////////////////////////////////////
// =============MERGESORT================== //
void merge(vector<int>&nums,int low,int mid,int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;
    while(left<=mid &&right<=high){
        if(nums[left]<=nums[right]){
        temp.push_back(nums[left]);
        left++;
        
        }else{
            temp.push_back(nums[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(nums[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(nums[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        nums[i]=temp[i-low];
    }
}
vector<int> merge_sort(vector<int>&nums,int low,int high){
if(low>=high)return nums;
int mid=(low+high)/2;
merge_sort(nums,low,mid);
merge_sort(nums,mid+1,high);
merge(nums,low,mid,high);
return nums;

}
// ==============QUICK SORT=============== //
int partition(vector<int>&nums, int low, int high){
    int pivot=nums[low];
    int i=low; int j=high;
    while(i<j){
        while(nums[i]<=pivot&&i<high){
            i++;
        }
        while(nums[j]>=pivot && j>low){
            j--;
        }
     if(i<j)swap(nums[i],nums[j]);


    }
    swap(nums[low],nums[j]);
    return j;
}
void qs(vector<int>&nums,int low, int high){
    if(low>high)return;
int partitionInd=partition(nums, low, high);
qs(nums,low,partitionInd-1);
qs(nums,partitionInd+1,high);
}

vector<int>quick_sort(vector<int>& nums) {
int n =nums.size();
qs(nums, 0,n-1);
return nums;
    }
//ending of sorting algorithm 
///pattern for display
void patternOne(){
    for(int i=0;i<10;i++){
    cout<<"=";
}
}
void displayAlgo(){
for(int i=1;i<=5;i++){
    if(i==1)cout<<"1=>SELECTION SORT"<<endl;
    else if(i==2)cout<<"2=>BUBBLE SORT"<<endl;
    else if(i==3)cout<<"3=>INSERTION SORT"<<endl;
     else if(i==4)cout<<"4=>MERGE SORT"<<endl;
     else cout<<"5=>QUICK SORT"<<endl;
    
}
  patternOne();
  patternOne();
  patternOne();
  patternOne();
  cout<<endl;

}
void heading(){
    cout<<" WELCOME TO SORTING \"ALGORITHMS MENU\" ";
}
vector<int>select_algo(int algo,vector<int>&nums){
    int n=nums.size();
    switch(algo){
        case 1:
        cout<<"YOU SELECTED SELECTION SORT.....\n";
       return selectionSort(nums);
      
       case 2:
        cout<<"YOU SELECTED BUBBLE SORT.....\n";
       return bubble_sort(nums);
     
       case 3:
         cout<<"YOU SELECTED INSERTION SORT.....\n";
       return insertion_sort(nums);
      
       case 4:
         cout<<"YOU SELECTED MERGE SORT.....\n";
       return merge_sort(nums,0,n-1);
  
       case 5:
         cout<<"YOU SELECTED QUICK SORT.....\n";
       return quick_sort(nums);
   
       default:
      cout<<"PLEASE ENTER NUMBER B/W 1-5";
      return nums;
    }
}
void output_ans(vector<int>&nums){
    int n=nums.size();
    
  
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
        
    }
  
   
    
    
}
// driver function 
int main() {
patternOne();
heading();
patternOne();
cout<<endl;
int n;
cout<<"PLEASE ENTER THE SIZE OF THE ARRAY YOU WANT TO SORT \n";
cin>>n;
vector<int>nums;
for(int i=0;i<n;i++){
    cout<<"Please enter num for index: "<<i<<endl;
    int x;

    cin>>x;
    nums.push_back(x);
    
}
patternOne();
cout<<"PLEASE SELECT THE ALGO ";
patternOne();
cout<<endl;

displayAlgo();
int algo;
cin>>algo;
nums=select_algo(algo,nums);

cout<<"Your output is :\n ";
output_ans(nums);

cout<<"\n.........🙏THANK-YOU FOR VISITING OUR SORTING PLATFORM....... ";


}

