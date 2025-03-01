class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> a(boxes.size());
        for(int i=0;i<boxes.size();i++)
        {
            for(int j=0;j<boxes.size();j++)
            {
                if(j==i)continue;
                int x=0;
                if(boxes[j] == '0')continue;
                x=j-i;
                if(x<0)
                {
                    a[i] += (-1)*(x);
                }
                else
                {
                    a[i] += x;
                }
            }
        }
        return a;
    }
};
