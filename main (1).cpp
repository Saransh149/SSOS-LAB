// Made by Saransh Rajpurohit
// Roll No. 21UCSE4028

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;

string l,ins,o="";

void file_reader(ifstream& myfile){
    string myline;
    getline (myfile, myline);

string arr[3];

int i=0;
stringstream ssin(myline);
    while (ssin.good() && i < 3){
        ssin >> arr[i];
        ++i;
    }

if(arr[2]!="" ){
	l=arr[0];
	ins=arr[1];
	o=arr[2];
	
}
else if(arr[1]!=""){
	ins=arr[0];
	o=arr[1];
	
}
else{
	ins=arr[0];
	
}
    
}

bool isNum(string s){
int flag=0;	
for (int i = 0; i < s.length(); i++) {
      if(!isdigit(s[i])){flag++;}
}
if(flag==0){return true;}
else{return false;}
}

int numConvert(string s){
	if(isNum(s)){
		return stoi(s);
	}
	else{
		return 0;
	}
}

int main () {
unordered_map<string, int> symtable;
unordered_map<string, int> optable;

optable["MOV"]=001;
optable["ADD"]=010;
optable["SUB"]=011;


int loctr,sa=0;

ifstream myfile; 
myfile.open("12345.txt");
if ( myfile.is_open() ) {
file_reader(myfile);

if(ins=="START"){
	loctr=numConvert(o);
	sa=loctr;
}
else{
	loctr=0;
}

while(ins!="END"){

ins,o,l="";
file_reader(myfile);
if(l!=""){
  if (symtable.find(l) == symtable.end())
    symtable[l]=loctr;
  else
    cout << "Duplicate Label " << endl;
}

if (optable.find(ins) != optable.end()){
    loctr=loctr+3;
}
else if(ins=="WORD"){
	loctr=loctr+3;
}
else if(ins=="RESW"){
	loctr=loctr+3*numConvert(o);
}
else if(ins=="RESB"){
	loctr=loctr+numConvert(o);
}
else if(ins=="BYTE"){
	loctr=loctr+1;
}
else if(ins=="END"){
    break;
}
else{
    cout << "Invalid operation"  << endl;
}

}
cout << loctr - sa << "\n";

}
else {
cout << "Couldn't open file\n";
}
for(unordered_map<string,int>::iterator i=symtable.begin();i!=symtable.end();i++){
	cout << i->first << " " << i->second << "\n";
}
return 0;}
