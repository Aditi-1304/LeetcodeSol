class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int g=0;
        int d=0;
        
        int td=0;
        for(int i=0;i<garbage.size();i++)
        {
            int t=0;
            for(auto j:garbage[i])
            {
                if(j == 'G')
                {
                    t++;
                }
            }
            if(t != 0)
            {
                g += t;
                if(i != 0)
                {
                    d += travel[i-1];
                    d += td;
                    td = 0;
                }
            }
            else if(i!=0)
            {
                td += travel[i-1];
            }
        }

        int m=0;
        td=0;
        for(int i=0;i<garbage.size();i++)
        {
            int t=0;
            for(auto j:garbage[i])
            {
                if(j == 'M')
                {
                    t++;
                }
            }
            if(t != 0)
            {
                m += t;
                if(i != 0)
                {
                    d += travel[i-1];
                    d += td;
                    td = 0;
                }
            }
            else if(i!=0)
            {
                td += travel[i-1];
            }
        }

        int p=0;
        td=0;
        for(int i=0;i<garbage.size();i++)
        {
            int t=0;
            for(auto j:garbage[i])
            {
                if(j == 'P')
                {
                    t++;
                }
            }
            if(t != 0)
            {
                p += t;
                if(i != 0)
                {
                    d += travel[i-1];
                    d += td;
                    td = 0;
                }
            }
            else if(i!=0)
            {
                td += travel[i-1];
            }
        }
        
        return g+m+p+d;
    }
};
