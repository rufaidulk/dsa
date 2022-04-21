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

public class ConstructBinaryTreeFromInOrderAndPreOrderTraversal
{
    static int preorderIndex = 0;
    
    public static void main(String[] args) {
        int[] inorder = {40, 20, 60, 50, 70, 10, 80, 100, 30};
        int[] preorder = {10, 20, 40, 50, 60, 70, 30, 80, 100};
        Node root = generateBinaryTree(inorder, preorder, 0, inorder.length-1);
        levelOrderTraversal(root);
    }
    
    static Node generateBinaryTree(int[] inorder, int[] preorder, int inorderStartIdx, int inorderEndIdx)
    {
        if (inorderStartIdx > inorderEndIdx) {
            return null;
        }
        
        Node root = new Node(preorder[preorderIndex++]);
        int rootIndex = inorderStartIdx;
        for (int i = inorderStartIdx; i <= inorderEndIdx; i++) {
            if (root.data == inorder[i]) {
                rootIndex = i;
                break;
            }
        }
        
        root.left = generateBinaryTree(inorder, preorder, inorderStartIdx, rootIndex - 1);
        root.right = generateBinaryTree(inorder, preorder, rootIndex + 1, inorderEndIdx);
        
        return root;
    }
    
    static void inorder(Node root) {
        if(root!=null) {
            inorder(root.left);
            System.out.print(root.data+" ");
            inorder(root.right);    
        }
    } 
    
    static void levelOrderTraversal(Node root)
    {
        if (root == null) {
            return;
        }
        
        Queue<Node> que = new ArrayDeque<>();
        que.add(root);
        
        while (que.isEmpty() == false)
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                Node elem = que.poll();
                System.out.print(elem.data + " ");
                
                if (elem.left != null) {
                    que.add(elem.left);
                }
                if (elem.right != null) {
                    que.add(elem.right);
                }
            }
            System.out.println("");
        }
    }
}
