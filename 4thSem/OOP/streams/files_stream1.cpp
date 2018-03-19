#include<bits/stdc++.h>
using namespace std;

int main() {

    // output file streams
    ofstream out_file_country("country.txt");
    ofstream out_file_capital("capital.txt");
    

    char inp[250];
    int i = 0;
    cout<<"ENTER COUNTRIES:\n";
    while(i++ < 3) {
    	cin.getline(inp, 100);
    	out_file_country<<inp<<endl;	
    } 
    out_file_country.close();

    i = 0;
    cout<<"ENTER CAPITALS: "<<endl;
    while(i++ < 3) {
    	cin.getline(inp, 100);
    	out_file_capital<<inp<<endl;	
    } 
    out_file_capital.close();


    // input file streams
    ifstream in_file_country("country.txt");
    ifstream in_file_capital("capital.txt");

    i = 0;
    cout<<"COUNTRIES\tCAPITALS"<<endl;
    while(i++ < 3) {
    	in_file_country.getline(inp, 100);
    	cout<<inp<<" \t\t ";
    	in_file_capital.getline(inp, 100);
    	cout<<inp;
    	cout<<endl;	
    } 
    
    in_file_country.close();
   	in_file_capital.close();

    return 0;
}
