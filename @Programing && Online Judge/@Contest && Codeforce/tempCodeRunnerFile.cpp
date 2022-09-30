int a = 10, b = 20;
    vector <int*> v;
    v.push_back(&a);
    v.push_back(&b);
    *v[0] += 1;
    cout << a << en;