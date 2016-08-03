package tree;

/**
 * Created by ankit.c on 15/07/16.
 */
public class TreeUtils {
    public static void inorder(Node root){
        if(root == null) return;
        inorder(root.left);
        System.out.println(root.val + " ");
        inorder(root.right);
    }
}
