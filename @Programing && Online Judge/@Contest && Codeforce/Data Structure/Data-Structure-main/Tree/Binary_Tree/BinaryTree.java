import java.util.Queue;
import java.util.LinkedList;

public class BinaryTree {

    Node root;

    class Node {
        int value;
        Node right, left;

        public Node(int value) {
            this.value = value;
        }
    }

    public void createBinaryTree() {
        root = null;
    }

    public void insert(int value) {
        Node newNode = new Node(value);

        if (root == null) {
            root = newNode;
        } else {
            Queue<Node> queue = new LinkedList<Node>();
            queue.add(root);

            while (!queue.isEmpty()) {
                Node currNode = queue.remove();
                if (currNode.left == null) {
                    currNode.left = newNode;
                    break;
                } else if (currNode.right == null) {
                    currNode.right = newNode;
                    break;
                } else {
                    queue.add(currNode.left);
                    queue.add(currNode.right);
                }
            }

        }
    }

    public boolean search(int value) {
        if (root == null)
            return false;
        Queue<Node> queue = new LinkedList<Node>();
        queue.add(root);

        while (!queue.isEmpty()) {
            Node currNode = queue.remove();

            if (currNode.value == value)
                return true;
            else {
                if (currNode.left != null)
                    queue.add(currNode.left);
                else if (currNode.right != null)
                    queue.add(currNode.right);
            }
        }
        return false;

    }

    public Node getDeepestNode() {

        Node currNode = root;

        Queue<Node> queue = new LinkedList<Node>();
        queue.add(root);
        while (!queue.isEmpty()) {
            currNode = queue.remove();
            if (currNode.left != null)
                queue.add(currNode.left);
            if (currNode.right != null)
                queue.add(currNode.right);
        }
        return currNode;
    }

    public void deleteDeepestNode() {
        if (root == null) {
            System.out.println("Tree is empty!");
            return;
        } else {
            Node currNode, prevNode;
            currNode = prevNode = null;
            Queue<Node> queue = new LinkedList<Node>();
            queue.add(root);
            while (!queue.isEmpty()) {
                prevNode = currNode;
                currNode = queue.remove();
                if(currNode.left == null) {
                    prevNode.right = null;
                    return;
                }
                else if(currNode.left == null) {
                    currNode.left = null;
                    return;
                }
                queue.add(currNode.left);
                queue.add(currNode.right);
            }
        }
    }

    public void deleteNodeValue(int value) {
        if (root == null) {
            System.out.println("Tree is empty");
            return;
        } else {
            Queue<Node> queue = new LinkedList<Node>();
            queue.add(root);

            while (!queue.isEmpty()) {
                Node currNode = queue.remove();
                if (currNode.value == value) {
                    System.out.println(currNode.value + " Deleted");
                    currNode.value = getDeepestNode().value;
                    deleteDeepestNode();
                    break;
                } else {
                    if (currNode.left != null) {
                        queue.add(currNode.left);
                    }
                    if (currNode.right != null) {
                        queue.add(currNode.right);
                    }
                }
            }
        }
    }

    public void inorder(Node root) {
        if (root == null)
            return;

        inorder(root.left);
        System.out.print(root.value + " ");
        inorder(root.right);
    }
    
    public void deleteBinaryTree() {
        root = null;
    }

    public static void main(String[] args) {
        BinaryTree bTree = new BinaryTree();

        bTree.createBinaryTree();
        bTree.insert(25);
        bTree.insert(26);
        bTree.insert(27);
        bTree.insert(28);
        bTree.insert(29);
        // System.out.println(bTree.root.value);

        System.out.print("Inorder : ");
        bTree.inorder(bTree.root);
        System.out.println();

        int value = 26;
        boolean s_value = bTree.search(value);
        if (s_value == true)
            System.out.println(value + " Found! in the Tree");
        else
            System.out.println(value + " Not found in the Tree");

    
        bTree.deleteNodeValue(25);
        System.out.print("Inorder Traversing : ");
        bTree.inorder(bTree.root);
        System.out.println();
        // System.out.println(bTree.root.value);
        bTree.deleteBinaryTree();
        bTree.deleteNodeValue(26);

        System.out.println("Tree was Deleted!");
    }
}
