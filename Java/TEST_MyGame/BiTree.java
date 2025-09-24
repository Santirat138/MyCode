package MyCode.Java.TEST_MyGame;

public class BiTree {
    void showInorder(Node currNode){
        showInorder(currNode.left);
        System.out.print(currNode.num+" ");
        showInorder(currNode.right);
    }
    void insert(Node currNode, int newNum){
        if(currNode==null){
            currNode=new Node(newNum, null, null);
            return ;
        }
        if(currNode.num<newNum){
            insert(currNode.right, newNum);
        }
        else if(currNode.num>newNum){
            insert(currNode.left, newNum);
        }
    }
    void deleteNum(){
        
    }
}
