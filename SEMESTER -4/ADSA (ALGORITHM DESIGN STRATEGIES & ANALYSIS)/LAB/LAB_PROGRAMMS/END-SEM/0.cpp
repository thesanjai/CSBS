#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr, int &count){

    for(int i=1;i<arr.size();i++){
        count++;

        int j=i-1;
        int key=arr[i];

        while(j>-1 and key < arr[j]){
            count++;

            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void mSort(vector<int> &arr,int l,int mid,int r,int &mcount){
    int n1=mid-l+1;
    int n2=r-mid;

    vector<int> Larr(n1,0);
    vector<int> Rarr(n2,0);

    for(int i=0;i<n1;i++){
        Larr[i]= arr[l+i];
        mcount++;
    }
    for(int i=0;i<n2;i++){
        Rarr[i]= arr[mid+1+i];
        mcount++;
    }

    int i=0, j=0, k=l;

    while(i<n1 and j<n2){
        mcount++;
        if(Larr[i]<arr[j]){
            arr[k++]=Larr[i++];
        }else{
            arr[k++]=Rarr[j++];
        }
    }
    while(i<n1){
        mcount++;
        arr[k++]=Larr[i++];
    }
    while(j<n2){
        mcount++;
        arr[k++]=Rarr[j++];
    }
}

void merge(vector<int> arr,int l, int r,int &mcount){
    if(l<r){
        int mid= (l+r)/2;
        mcount++;

        merge(arr,l,mid,mcount);
        merge(arr,mid+1,r,mcount);
       
        mSort(arr,l,mid,r,mcount);
    }
}
int main(int argc, char** argv){
    srand(time(NULL));

    vector<int> size={1000,2000,5000};

    for(auto n:size){
        cout<<"\n\nINPUT SIZE: "<<n<<endl;
        vector<int> arr;

        for(int i=0;i<n;i++){
            int temp=rand()%n;
            arr.push_back(temp);
        }

        //random input

        cout<<setfill(' ')<<setw(30)<<"RANDOM ORDER INPUT\n";

        int Icount=0;
        insertionSort(arr,Icount);
        cout<<"insertion sort  : "<<Icount<<endl;

        int Mcount=0;
        merge(arr,0,arr.size()-1,Mcount);
        cout<<"merge sort  : "<<Mcount<<endl;

        //ordered input
        cout<<setfill(' ')<<setw(25)<<" ORDERED INPUT\n";
        sort(arr.begin(),arr.end());

        Icount=0;
        insertionSort(arr,Icount);
        cout<<"insertion sort  : "<<Icount<<endl;

        Mcount=0;
        merge(arr,0,arr.size()-1,Mcount);
        cout<<"merge sort  : "<<Mcount<<endl;

        //reverse input
        cout<<setfill(' ')<<setw(25)<<" REVERSE INPUT\n";
        reverse(arr.begin(),arr.end());

        Icount=0;
        insertionSort(arr,Icount);
        cout<<"insertion sort  : "<<Icount<<endl;

        Mcount=0;
        merge(arr,0,arr.size()-1,Mcount);
        cout<<"merge sort for : "<<Mcount<<endl;
    }
    return 0;
}