#include<iostream>
#include<fstream>
#include<fstream>
#include<vector>
#include<cstdlib>//to generate random number
#include<algorithm>
#include<iomanip> 
#include<ctime>
using namespace std;


class SORT{

  public:
    
  static int merge_count;

      static int  insertion_sort(int a[],int n){
        
        int count=0;
        
        for(int i=1;i<n;i++){
          count++;
          int j=i-1;
          int temp=a[i];
          
          while(j>-1 and  temp<a[j]){
             count++;
            a[j+1]=a[j];
            j--;
          }
          a[j+1]=temp;
        }
        
        return count;
      
    }

    static void MergeSort(int a[],int l,int r){
        if(l<r){
          merge_count++;

          int mid=(l+r)/2;

          MergeSort(a,l,mid);
          MergeSort(a,mid+1,r);
        
          Merge(a,l,mid,r);

        }
    }

    static void Merge(int a[],int l,int mid,int r){

      int n1= mid - l +1;
      int n2= r - mid;

      int *Larr= new int[n1];
      int *Rarr= new int[n2];

      for(int i=0;i<n1;i++){
        Larr[i] = a[l+i];
        merge_count++;
      }
      for(int j=0;j<n2;j++){
        Rarr[j] = a[mid+1+j];
        merge_count++;
      }
      

      int i=0;
      int j=0;
      int k=l;

      while(i<n1 && j<n2){
        merge_count++;
        if(Larr[i] <= Rarr[j]){
          a[k++]=Larr[i++];
        }
        else{
          a[k++]=Rarr[j++];
        }
      }

      while(i<n1){
        merge_count++;
        a[k++]=Larr[i++];
      }

      while(j<n2){
        merge_count++;
        a[k++]=Rarr[j++];
      }      

    delete[] Larr;
    delete[] Rarr;
    }
};
int SORT::merge_count=0;

int main(){
    
   //getting input from the user
   int n;
   cout<<"Enter N: ";
   cin>>n;
   
   //setting seed value
   //srand((long int)clock());

   //creating random numbers into the file
    ofstream op("random_input.xlsx");
    for(int i=0;i<n;i++){
      op<<rand()%n<<"\t";
     }
     
    op.close();
    
    //get the random numbers from the file to program
     int *a= new int[n];
        ifstream ip("random_input.xlsx");
        for(int i=0;i<n;i++){
          ip>>a[i];
        }
        ip.close();
     
   
   //random array
   int random_count_insertion_sort=SORT::insertion_sort(a,n);

   SORT::MergeSort(a,0,n-1);
   int random_count_merge_sort=SORT::merge_count;
   SORT::merge_count=0;
   

   
   //sorted array
    sort(a,a+n);

    ofstream op1("sorted_input.xlsx");
    for(int i=0;i<n;i++){
      op1<<a[i]<<"\t";
    }
    op1.close();
    
    int sorted_count_insertion_sort=SORT::insertion_sort(a,n);

    SORT::MergeSort(a,0,n-1);
    int sorted_count_merge_sort=SORT::merge_count;
    SORT::merge_count=0;
    
    
    //reverse array
    reverse(a,a+n);

    ofstream op2("reverse_input.xlsx");
    for(int i=0;i<n;i++){
      op1<<a[i]<<"\t";
    }
    op2.close();
      
     int reverse_count_insertion_sort=SORT::insertion_sort(a,n);
     
     SORT::MergeSort(a,0,n-1);
     int reverse_count_merge_sort=SORT::merge_count;
     SORT::merge_count=0;
   
     
    //printing the result
        cout<<setw(40)<<setfill('-')<<"INSERTION SORT OPERATIONS"<<setw(15)<<setfill('-')<<"-"<<endl;
        cout<<"NO. OF INTERAIONS OF ORDERD NUMBERS: "<<sorted_count_insertion_sort<<endl;
        cout<<"NO. OF INTERAIONS OF REVERSE_ORDEREED NUMBERS: "<<reverse_count_insertion_sort<<endl;
        cout<<"NO. OF INTERAIONS OF RANDOM NUMBERS: "<<random_count_insertion_sort<<endl;
        

        cout<<setw(100)<<setfill('*')<<"*"<<endl;
        cout<<setw(25)<<setfill('-')<<"MERGE SORT"<<setw(25)<<setfill('-')<<"-"<<endl;
        cout<<"NO. OF INTERAIONS OF ORDERD NUMBERS: "<<sorted_count_merge_sort<<endl;
        cout<<"NO. OF INTERAIONS OF REVERSE_ORDEREED NUMBERS: "<<reverse_count_merge_sort<<endl;
        cout<<"NO. OF INTERAIONS OF RANDOM NUMBERS: "<<random_count_merge_sort<<endl;
        
    
     
    
   delete[] a;
   return 0;
}
//g++ -std=c++11 programname.cpp

