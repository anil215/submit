stack<int>st;
vector< vector<int> >ans;

void push_into_ans()
{
    vector<int>temp;
    while(!st.empty()){
        temp.push_back(st.top());
        st.pop();
    }
    reverse(temp.begin(),temp.end());
    for(int i=0;i<temp.size();i++){
        st.push(temp[i]);
    }
    ans.push_back(temp);
}

void rec(TreeNode* root, int rem, int tot){
    st.push(root->val);
    if(rem+(root->val) == tot && root->left == NULL && root->right == NULL){
        // push into main vector
        push_into_ans();
        st.pop();
        return;
    }
    if(root->left != NULL){
        rec(root->left, rem+(root->val),tot);
    }
    if(root->right != NULL){
        rec(root->right, rem+(root->val),tot);
    }
    st.pop();
}

vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    ans.clear();
    rec(A,0,B);
    return ans;
}
