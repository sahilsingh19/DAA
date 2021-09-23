  
#include<iostream> 
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        int key;
        cin >> key;
        bool found = 0;
        int comparisions = 0;
        for(int i = 0;i<n;i++){
            comparisions++;
            if(arr[i] == key){
                found = 1;
                break;
            }
        }
        if(found){
            cout << "Present ";
        } else {
            cout << "Not Present ";
        }
        cout << comparisions << endl;
    }
}
