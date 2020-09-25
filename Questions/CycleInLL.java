import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Node{
    int data;
    Node next;
}

public boolean hasCycle(Node head){
    if(head == null){
        return false;
    }
    Node fast = head.next;
    Node slow = head;

    while(fast != null && fast.next != null && slow!=null){
        if(fast == slow){
            return true;
        }
        fast = fast.next.next;
        slow = slow.next;
    }
    return false;
}