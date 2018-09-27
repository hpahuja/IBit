//Max Sum Without Adjacent Elements
int Solution::adjacent(vector<vector<int> > &A) {
    int col = A[0].size();
    vector< vector<int> >  vec(2);
    vec[0] = vector<int>(col); 
    vec[1] = vector<int>(col); 
    int sum = 0;
    for(int i = 0 ; i< col ; i++)
    {
        if(i<2)
        {
            vec[0][i] = A[0][i];
            vec[1][i] = A[1][i];
        }
        else
        {
            int maxVal = 0;
            if(i == 2)
            {
                maxVal = max(vec[0][0],vec[1][0]);
            }
            else
            {
                maxVal = max(max(vec[0][i-2],vec[0][i-3]),max(vec[1][i-2],vec[1][i-3]));
            }
            vec[0][i] = A[0][i] + maxVal;
            vec[1][i] = A[1][i] + maxVal;
        }
        sum = max(sum, max(vec[0][i], vec[1][i]));
    }
    return sum;
}
