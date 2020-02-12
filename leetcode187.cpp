int charToBit(char c){
    switch (c){
        case 'A': return 0;
        case 'G': return 1;
        case 'C': return 2;
        case 'T': return 3;
    }
    return -1;  // never happened
}

vector<string> findRepeatedDnaSequences(string s) {
    vector<string> res;
    if(s.size() < 10) return res;
    bitset<1<<20> S1;
    bitset<1<<20> S2; // to avoid dulplication
    //init
    int val = 0;
    for(int i=0;i<10;i++){
        val = val << 2 | charToBit(s[i]);
    }
    S1.set(val);
    int mask = (1 << 20) - 1;
    for(int i=10;i<s.size();i++){
        val = ((val << 2) & mask) | charToBit(s[i]);
        if(S1[val]) {
            if (!S2[val]) {
                res.push_back(s.substr(i - 9, 10));
                S2.set(val);
            }
        }
        else{
            S1.set(val);
        }
    }
    return res;
}
