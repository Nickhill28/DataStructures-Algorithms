import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Node{
    int data;
    Node left;
    Node right;
}

public boolean checkBST(Node root,int min,int max){
    if(root == null){
        return true;
    }
    if(root.data < min || root.data > max){
        return false;
    }
    return checkBST(root.left,min,root.data-1) && checkBST(root.right,root.data+1,max);
}

public boolean checkBST(Node root){
    return checkBST(root,INTEGER.min_value,INTEGER.max_vale);
}