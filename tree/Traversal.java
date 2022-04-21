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

public class Traversal
{
    static int postorderIndex = 8;
    
    public static void main(String[] args) {
        int[] inorder = {40, 20, 60, 50, 70, 10, 80, 100, 30};
        int[] postorder = {40, 60, 70, 50, 20, 100, 80, 30, 10};
        Node root = generateBinaryTree(inorder, postorder, 0, inorder.length-1);
        System.out.println("Post Order Traversal");
        postorder(root);
        System.out.println("\n\nLevel Order Traversal");
        levelOrderTraversal(root);
        System.out.println("\n\nLevel Order Traversal Method 2");
        levelOrderTraversalMethod2(root);
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
    
    static void levelOrderTraversalMethod2(Node root)
    {
        if (root == null) {
            return;
        }
        
        Queue<Node> que = new LinkedList<>();
        que.add(root);
        que.add(null);
        
        while (que.size() > 1)
        {
            Node elem = que.poll();
            if (elem == null) {
                System.out.println("");
                que.add(null);
                continue;
            }
            
            System.out.print(elem.data + " ");
            
            if (elem.left != null) {
                que.add(elem.left);
            }
            if (elem.right != null) {
                que.add(elem.right);
            }
        }
    }
    
    static void postorder(Node root) 
    {
        if(root != null) {
            postorder(root.left);
            postorder(root.right);    
            System.out.print(root.data+" ");
        }
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
    
}
