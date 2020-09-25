import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Node {
    int data;
    Node left,right;
    public Node (int data){
        this.data = data;
    }
}

public void insert(int value){
    if(value <= data){
        if(left == null){
            left = new Node(value);
        }
        else{
            left.insert(value);
        }
    }
    else{
        if(right == null){
            right = new Node(value);
        }
        else{
            right.insert(value);
        }
    }
}

public boolean contains(int value){
    if(value == data){
        return true;
    }
    else if(value < data){
        if(left == null){
            return false;
        }
        else{
            left.contains(value);
        }
    }
    else{
        if(right == null){
            return false;
        }
        else{
            right.contains(value);
        }
    }
}

public void PrintInOrder(){
    if (left != null){
        left.PrintInOrder();
    }
    System.Out.Println(data);
    if (right != null){
        right.PrintInOrder();
    }
}

public void PrintPreOrder(){
    System.Out.Println(data);
    if (left != null){
        left.PrintPreOrder();
    }
    if (right != null){
        right.PrintPreOrder();
    }
}

public void PrintPostOrder(){
    if (left != null){
        left.PrintPostOrder();
    }
    if (right != null){
        right.PrintPostOrder();
    }
    System.Out.Println(data);
}