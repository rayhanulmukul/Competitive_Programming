#include<bits/stdc++.h>
using namespace std;
#define enter(x) for(int i = 0; i < x; i++) outputfile << "\n";

string copyfiles(string filename){
    fstream inputfile;
    inputfile.open(filename, ios::in);
    string page;
    string now;
    while(getline(inputfile, now)){
        page += now + "\n";
    }
    inputfile.close();
    return page;
}

int main(int argc, char** argv){
    string filename = argv[1];
    string page = copyfiles(filename);
    fstream inputfile;
    inputfile.open(filename, ios::in);
    if(!inputfile){
        cout << "Encountered problem with openning the file" << endl;
        cout << "May be the file doesn't exist" << endl;
        exit(0);
    }
    //get classname 
    deque<string>pq;
    string one;
    string classname;
    deque<string>params;
    bool isparam = false;
    while(inputfile >> one){
        if(isparam){
            if(one == "}" || one.back() == ')') break;
            else if(one.back() != ',') params.push_back(one);
        }
        pq.push_back(one);
        if(pq.size() > 3) pq.pop_front();
        if(pq[0] == "public:"){
            classname = one;
            isparam = true;
        }
    }
    int n = classname.size();
    for(int i = 0; i < n; i++){
        if(classname[i] == '('){
            string par = classname.substr(i+1, n-(i+1));
            params.push_front(par);
            while(classname.size() > i) classname.pop_back();
            break;
        }
    }
    inputfile.close();
    for(auto &a: params){
        if(a.back() == '&') a.pop_back();
        if(a != "vector<vector<int>>"){
            if(a != "vector<int>"){
                if(a != "int"){
                    if(a != "string"){
                        if(a != "vector<string>" && a != "vector<vector<string>>"){
                            cout << a << " is not supported yet" << endl;
                            exit(0);
                        }
                    }
                }
            }
        }
    }
    fstream outputfile;
    outputfile.open(filename, ios::out);
    outputfile << "#include<bits/stdc++.h>\nusing namespace std;\n#include\"leetcode.h\"\n";
    outputfile << "//copy the code below....\n///////////////////////////////////\n";
    enter(1);
    outputfile << "auto speed=[]()\n{\tstd::ios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tcout.tie(nullptr);\n\treturn nullptr;\n}();\n";
    enter(2);
    outputfile << page;
    enter(3);
    outputfile << "//copy the code above....\n///////////////////////////////////\n";
    outputfile << "int main(){\n\tfreopen(\"in\",\"r\",stdin);\n";
    vector<char>meta;
    char now = 'a';
    for(auto a: params){
        meta.push_back(now);
        outputfile <<"\t"<< a << " ";
        if(a == "int") a = "inpint()";
        if(a == "vector<int>") a = "inpvec()"; 
        if(a == "vector<vector<int>>") a = "inp2dvec()";
        if(a == "string") a = "inpstr()";
        if(a == "vector<string>") a = "inpvecstr()";
        if(a == "vector<vector<string>>") a = "inp2dvecstr()";
        outputfile << now ++ << " = " << a <<";\n";
    }
    outputfile << "\tSolution ashiq;\n\tcout << ashiq.";
    outputfile << classname << "(";
    int id = 0;
    for(auto a: meta){
        if(id) outputfile << ", ";
        outputfile << a ;
        id++;
    }
    outputfile << ") << endl;\n}\n";
}