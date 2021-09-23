
#include<iostream> 
using namespace std;
int main(){
    int testcases;
    cin >> testcases;
    while(testcases--){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        int key;
        cin >> key;
        bool found = 0;
        int high = n - 1 , low = 0 , comparisions = 0;
        while(high >= low){
            int mid = (high + low)/2;
            comparisions++;
            if(arr[mid] == key){
                found = 1;
                break;
            } 
            if(arr[mid] > key){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if(!found)
            cout << "Not "; 
        cout << "Present " << comparisions << endl;
    }
}
