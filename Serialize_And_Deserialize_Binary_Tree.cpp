/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    vector<string> split( string s , char del )
    {
        vector<string> ans ;
        stringstream ss(s) ;
        string word ;
        
        while( !ss.eof() )
        {
            getline( ss , word , del ) ;
            ans.push_back( word ) ;
        }
        return ans ;
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if ( root == NULL ) return "" ;
        queue<TreeNode*> qu ;
        string ans = to_string(root->val)+"," ;
        qu.push(root) ;

        while(!qu.empty())
        {
            TreeNode* head = qu.front() ;
            qu.pop() ;

            if ( head ->left == NULL ) ans += "#," ;
            else 
            {
                ans += to_string(head->left->val)+",";
                qu.push(head->left) ;
            }

            if ( head->right == NULL ) ans += "#," ;
            else
            {
                ans += to_string(head->right->val)+"," ;
                qu.push(head->right) ;
            }
        }

        return ans ;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if ( s.size() == 0 ) return nullptr ;
        vector<string> data = split(s,',') ;
       
        TreeNode* root = new TreeNode( stoi(data[0]) );
        queue<TreeNode*> qu;
        qu.push(root) ;
        int k = 0 ;
        while( !qu.empty())
        {
            TreeNode* pointer = qu.front() ;
            qu.pop() ;

            ++k ;
            if ( data[k] == "#" ) 
            pointer->left = NULL;
            else 
            {
                TreeNode* ll = new TreeNode(stoi(data[k])) ;
                pointer->left = ll;
                qu.push(ll) ;
            }

            ++k ;

            if ( data[k] == "#" ) 
            pointer->right = NULL;
            else 
            {
                TreeNode* ll = new TreeNode(stoi(data[k])) ;
                pointer->right = ll;
                qu.push(ll) ;
            }
        }

        return root ;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
