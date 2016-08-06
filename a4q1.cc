#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

int main(int argc, char *argv[]){
    cin.exceptions(ios::eofbit|ios::failbit);
    int sum=0,non_sum=0,non_file=0;
    vector<string> new_file;
    for(int i=1,pos=0;i<argc;i++){
        try {
            ifstream file{argv[i]};
            if(!file){
                throw argv[i];
            }
            string s;
            int num;
            char c;
            while(file >> s){
                istringstream ss{s};
                if(ss >> num){
                    sum+=num;
                    ss.ignore();
                    if(ss >> c){
                        non_sum+=1;
                    }
                }
                else{
                    non_sum+=1;
                }
            }
        }
        catch (char* file_name) {
            new_file.push_back(file_name);
            non_file+=1;
            pos+=1;
        }
    }
    
    cout << "Non-existent files: ";
    for(int j=0;j<non_file-1;j++){
        cout << new_file[j] << " ";
    }
    if(non_file-1 >=0){
        cout << new_file[non_file-1] << endl;
    }
    else{
        cout << endl;
    }
    cout << "Total of all numbers: " << sum << endl;
    cout << "Total number of non-numbers: " << non_sum << endl;
    

}

