#include<iostream>
#include<fstream>
using namespace std;

int main(int argc, char *argv[]){
    int sum=0,non_sum=0,non_file=0;
    char *new_file[argc];
    for(int i=0;i<argc;i++){
        ifstream file{argv[i]};
        string s;
        int num=0;
        file.exceptions ( ifstream::failbit | ifstream::badbit );
        try {
            while (file >> num) {
                sum+=num;
            }
            while(file >> s){
                non_sum+=1;
            }
        }
        catch (ifstream::failure e) {
            new_file[non_file]=argv[i];
            non_file++;
            throw;
        }

    }
    
    cout << "Non-existent files: ";
    for(int j=0;j<non_file-1;j++){
        cout << new_file[j] << " ";
    }
    if(non_file-1 >=0){
        cout << new_file[non_file-1] << endl;
    }
    cout << "Total of all numbers: " << sum << endl;
    cout << "Total number of non-numbers: " << non_sum << endl;
    return 0;
}
