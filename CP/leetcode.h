using namespace std;
int INPUT_LIMIT = 50000000;

int cnt = 0;

int inpint(){
    char ashiq;
    int nums = 0;
    bool isst = false;
    int sign = 1;
    while(true){
        ashiq = getchar();
        cnt++; 
        if(cnt > INPUT_LIMIT){
            cout << "INVALID INPUT!!" << endl;
            exit(0);
        }
        if(isdigit(ashiq)){
            isst = true;
            nums *= 10;
            nums += ashiq - '0';
        }
        else{
            if(ashiq == '-'){
                sign = -1;
            }
            if(isst) return nums*sign;
        }
    }
}

vector<int> inpvec(){
    char ashiq;
    vector<int>ans;
    int isst = 0;
    int nums = 0;
    int sign = 1;
    while(true){
        ashiq = getchar();
        cnt++; 
        if(cnt > INPUT_LIMIT){
            cout << "INVALID INPUT!!" << endl;
            exit(0);
        }
        if(ashiq == '['){
            isst = 1;
        }
        if(isdigit(ashiq) && isst){
            isst = 2;
            nums *= 10;
            nums += (ashiq - '0');
        }
        else{
            if(ashiq == '-'){
                sign = -1;
                continue;
            }
            if(isst == 2) ans.push_back(nums*sign);
            nums = 0;
            sign = 1;
        }
        if(ashiq == ']'){
            return ans;
        }
    }
}

vector<vector<int>> inp2dvec(){
    char ashiq;
    vector<vector<int>>ans;
    while(true){
        ashiq = getchar();
        cnt++; 
        if(cnt > INPUT_LIMIT){
            cout << "INVALID INPUT!!" << endl;
            exit(0);
        }
        if(ashiq == ']') return ans;
        else ans.push_back(inpvec());
    }
}

string inpstr(){
    string ans = "";
    char ashiq ;
    bool isst = false;
    while(true){
        ashiq = getchar();
        cnt++;
        if(cnt > INPUT_LIMIT){
            cout << "INVALID INPUT!!" << endl;
            exit(0);
        }
        if(ashiq == '\"'){
            if(isst) return ans;
            isst = true;
        }
        else {
            if(isst == true) ans += ashiq;
        }
    }
}
vector<string> inpvecstr(){
    vector<string>ans;
    char ashiq = 0;
    while(true){
        ashiq = getchar();
        if(ashiq == '[' || ashiq == ','){
            ans.push_back(inpstr());
        }
        else if(ashiq == ']'){
            return ans;
        }
    }
}
vector<vector<string>> inp2dvecstr(){
    vector<vector<string>>ans;
    char ashiq = 0;
    while(true){
        ashiq = getchar();
        if(ashiq == '[' || ashiq == ','){
            ans.push_back(inpvecstr());
        }
        else if(ashiq == ']'){
            return ans;
        }
    }
}