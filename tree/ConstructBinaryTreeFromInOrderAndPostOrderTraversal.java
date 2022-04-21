import java.util.*;

class Node {
	public int data;
	public Node left;
	public Node right;

	Node (int data) {
		this.data = data;
		this.left = null;
		this.right = null;
	}
}

public class ConstructBinaryTreeFromInOrderAndPostOrderTraversal
{
    static int postorderIndex = 8;
    
    public static void main(String[] args) {
        int[] inorder = {40, 20, 60, 50, 70, 10, 80, 100, 30};
        int[] postorder = {40, 60, 70, 50, 20, 100, 80, 30, 10};
        Node root = generateBinaryTree(inorder, postorder, 0, inorder.length-1);
        postorder(root);
    }
    
    static Node generateBinaryTree(int[] inorder, int[] postorder, int inorderStartIdx, int inorderEndIdx)
    {
        if (inorderStartIdx > inorderEndIdx) {
            return null;
        }
        
        Node root = new Node(postorder[postorderIndex--]);
        
        int rootIndex = inorderStartIdx;
        for (int i = inorderStartIdx; i <= inorderEndIdx; i++) {
            if (root.data == inorder[i]) {
                rootIndex = i;
                break;
            }
        }
        
        root.right = generateBinaryTree(inorder, postorder, rootIndex + 1, inorderEndIdx);
        root.left = generateBinaryTree(inorder, postorder, inorderStartIdx, rootIndex - 1);
        
        return root;
    }
    
    static void postorder(Node root) {
        if(root!=null) {
            postorder(root.left);
            postorder(root.right);    
            System.out.print(root.data+" ");
        }
    }
}
