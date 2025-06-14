class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);

        string mx = "", mn = "";
        int n = s.size();

        for(int i = 0; i < n; i++){
            if(s[i] != '9'){
                str = s[i];
                break;
            }
        }

        for(int i = 0; i < n; i++){
            if(str == s[i]) mx += '9';
            else mx += s[i];
        }

        cout << mx << endl;

        return 0;
    }
};