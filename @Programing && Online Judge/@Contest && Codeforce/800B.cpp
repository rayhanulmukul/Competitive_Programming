 while(t--){
    int a,b;
    cin>>a>>b;
    string s="";
    if(a<=b){
        for(int i=0;i<b;i++){
            s.append("1");
        }
        for(int i=0;i<a;i++){
            s.append("0");
        }
        cout<<s<<endl;
    }
    else{
        for(int i=0;i<a;i++){
            s.append("0");
        }
        for(int i=0;i<a;i++){
            s.append("1");
        }
        cout<<s<<endl;
    }
    }