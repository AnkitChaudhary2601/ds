package tree;

/**
 * Created by ankit.c on 15/07/16.
 */
public class Node {
    int val;
    Node left;
    Node right;

    public Node(int val){
        this.val = val;
    }

    @Override
    public String toString() {
        return "Node{" +
                "val=" + val +
                '}';
    }
}
