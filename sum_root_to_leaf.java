/**
Sum Root to Leaf Numbers

 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public int sumNumbers(TreeNode root) {
        return sum(root,0);
        
    }
    public int sum(TreeNode root,int val){
        if(root!=null && root.left == null && root.right==null  ){
            return val*10 + root.val;
        }
        else{
            if(root!=null && root.left!=null && root.right!=null){
                return sum(root.left,val*10+root.val) + sum(root.right,val*10+root.val);
            }
            else{
                if(root!=null && root.left!=null){
                    return sum(root.left,val*10+root.val);
                }
                else{
                    if(root!=null && root.right!=null){
                        return sum(root.right,val*10+root.val);
                    }
                    else{
                        return val;
                    }
                }
            }
        }
        
    }
}