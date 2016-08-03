package tree;

/**
 * Created by ankit.c on 15/07/16.
 */
public class KthSmallestInBST {
    private static int k;
    public static Node findKthSmallest(Node node){
        if(node == null) return null;
        if(node.left != null){
            Node tmp = findKthSmallest(node.left);
            if(tmp != null)
                return tmp;
        }

        if(--k == 0) return node;

        if(node.right != null){
            Node tmp = findKthSmallest(node.right);
            if(tmp != null)
                return tmp;
        }

        return null;
    }

    public static void main(String[] args){
        BST tree = new BST();
        tree.insert(20);
        tree.insert(10);
        tree.insert(30);
        tree.insert(5);
        tree.insert(15);
        tree.insert(25);
        tree.insert(35);
        tree.inorder();
        k = 5;
        Node kth = findKthSmallest(tree.root);
        System.out.println(kth);
    }
}
