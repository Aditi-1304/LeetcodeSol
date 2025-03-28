class BrowserHistory {
public:
    vector<string> s;
    int p=-1;
    BrowserHistory(string homepage) {
        s.push_back(homepage);
        p++;
        
    }
    
    void visit(string url) {
        s.erase(s.begin()+p+1,s.end());
        s.push_back(url);
        p++;
    }
    
    string back(int steps) {
        p -= steps;
        if(p < 0)
        {
            p = 0;
        }
        return s[p];
    }
    
    string forward(int steps) {
        p+=steps;
        if(p >= s.size())
        {
            p = s.size()-1;
        }
        return s[p];
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
