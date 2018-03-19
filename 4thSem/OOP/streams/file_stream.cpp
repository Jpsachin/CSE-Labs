#include<bits/stdc++.h>
using namespace std;

int main() {

    // write into the file
    ofstream out_file_stream("text.txt");
    out_file_stream<<"TEST TEXT"<<endl;
    out_file_stream<<"REALLY?!"<<endl;
    // out_file_stream.close();

    // read from the file
    char res[50];
    ifstream in_file_stream("text.txt");
    in_file_stream.getline(res, 50);
    cout<<res<<endl;
    in_file_stream.getline(res, 50);
    cout<<res<<endl;
    in_file_stream.close();

    // opening file without closing the previous stream
    // doe not give error but does not allow writing into the file        
    out_file_stream.open("text.txt");
    out_file_stream<<"NOPE"<<endl;
    out_file_stream.close();
    in_file_stream.open("text.txt");
    in_file_stream.getline(res, 50);
    cout<<res<<endl;

    return 0;
}
