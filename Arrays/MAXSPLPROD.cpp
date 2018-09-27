int Solution::maxSpecialProduct(vector<int> &A) {

    int size = A.size();
    long long int sum = 0;
    if(size<3) return 0;

    stack<int> st;
    vector<int> LSV (size);
    vector<int> RSV (size);

    for(int i = 0 ; i<size ; i++)
    {
        while(!st.empty() && A[i]>=A[st.top()]) st.pop();
        if(st.empty())
        {
            LSV[i] = 0;
        }
        else
        {
            LSV[i]=st.top();
        }
        st.push(i);
    }
    while(!st.empty()){ st.pop();}
    
    for(int i = size-1 ; i>=0 ; i--)
    {
        while(!st.empty() && A[i]>=A[st.top()]) st.pop();
        if(st.empty())
        {
            RSV[i] = 0;
        }
        else
        {
            RSV[i]=st.top();
        }
        st.push(i);
        sum = max(sum, ((long long int)LSV[i]*RSV[i]));
    }
    
    return sum % 1000000007;
}
