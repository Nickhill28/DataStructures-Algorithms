import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Stack{
    private int data;
    private Node next;
    private Node(int data){
        this.data = data;
    }
}

private Node top;

public boolean isEmpty(){
    return top==null;
}

public int peek(){
    return top.data;
}

public void push(int data){
    Node node = new Node(data);
    node.next = top;
    top = node;
}

public int pop(){
    int data = top.data;
    top = top.next;
    return data;
}