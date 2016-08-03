package tree;

/**
 * Created by ankit.c on 15/07/16.
 */
public class BST {
    Node root;

    public BST(){}

    public BST(Node root){
        this.root = root;
    }

    public void insert(int val){
        insert(new Node(val));
    }

    public void insert(Node node){
        if(root == null) {
            this.root = node;
            return;
        }

        Node tmp = root;
        while(tmp != null){
            if(tmp.val > node.val) {
                if(tmp.left == null){
                    tmp.left = node;
                    return;
                }
                tmp = tmp.left;
            }
            else if(tmp.val < node.val) {
                if(tmp.right == null){
                    tmp.right = node;
                    return;
                }
                tmp = tmp.right;
            }
            else {
                throw new IllegalArgumentException("Values cannot be same in BST : " + node.val);
            }
        }
    }

    public void inorder(){
        System.out.println();
        TreeUtils.inorder(this.root);
        System.out.println();
    }
}
