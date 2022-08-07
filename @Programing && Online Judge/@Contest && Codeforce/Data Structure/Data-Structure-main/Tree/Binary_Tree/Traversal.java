import java.util.*;

public class Traversal {

    public Node root = null;
    class Node {
        int value;
        Node left, right;

        public Node(int value) {
            this.value = value;
            this.left = this.right = null;
        }
    }

    public void createTree() {
        root = null;
    }

    public void insert(int value) {
        Node newNode = new Node(value);
        if(root == null) {
            root = newNode;
            return;
        }
        else {
            Queue<Node> queue = new LinkedList<Node>();
            queue.add(root);
            while(!queue.isEmpty()) {
                Node tempNode = queue.remove();

                if(tempNode.left == null) {
                    tempNode.left = newNode;
                    return;
                }
                else if(tempNode.right == null) {
                    tempNode.right = newNode;
                    return;
                }
                else {
                    queue.add(tempNode.left);
                    queue.add(tempNode.right);
                }
            }
        }
    }
    // preorder traversing iterative method
    public List<Integer> preOrderTraversing() {
        List<Integer> list = new ArrayList<Integer>();

        if(root == null) return list;

        Stack<Node> stack = new Stack<Node>();
        stack.push(root);

        while(!stack.isEmpty()) {
            Node node = stack.peek();
            list.add(node.value);
            stack.pop();

            if(node.right != null) stack.push(node.right);
            if(node.left != null) stack.push(node.left);
        }

        return (list);
    }

    public List<Integer> inOrderTraversing() {
        List<Integer> list = new ArrayList<Integer>();

        if(root == null) return list;

        Stack<Node> stack = new Stack<Node>();
        Node currNode = root;

        while(!stack.isEmpty() || currNode != null) {
            while(currNode != null) {
                stack.push(currNode);
                currNode = currNode.left;
            }
            currNode = stack.pop();
            list.add(currNode.value);
            currNode = currNode.right;
        }
        return list;
    }

    public List<Integer> postOrderTraversing() {
        List<Integer> list = new ArrayList<Integer>();
        if(root == null) return list;

        Stack<Node> stack = new Stack<Node>();

        Node currNode;
        stack.push(root);
        while(!stack.isEmpty()) {
            currNode = stack.pop();
            list.add(currNode.value);
            if(currNode.left != null) stack.push(currNode.left);
            if(currNode.right != null) stack.push(currNode.right);
        }
        return list;
    }

    public static void main(String[] args) {
        Traversal tree = new Traversal();
        tree.createTree();
        //int a[] = new int[10];
        int a[] = {1,2,3,4,5,6,7,8,9,10};

        for(int i = 0; i < a.length; i++) {
            tree.insert(a[i]);
        }
        System.out.print("PreOrder Traversing : ");
        List<Integer> preList = new ArrayList<Integer>();
        preList = tree.preOrderTraversing();

        for(int i = 0; i < preList.size();  i++) {
            System.out.print(preList.get(i) + " ");
        }

        System.out.println();
        System.out.print("Inorder Traversing : ");
        List<Integer> inList = new ArrayList<Integer>();
        inList = tree.inOrderTraversing();

        for(int i = 0; i < inList.size();  i++) {
            System.out.print(inList.get(i) + " ");
        }
        System.out.println();
        System.out.print("Post Order Traversing : ");
        List<Integer> postList = new ArrayList<Integer>();
        postList = tree.postOrderTraversing();

        for(int i = 0; i < postList.size();  i++) {
            System.out.print(postList.get(i) + " ");
        }
    }
}
