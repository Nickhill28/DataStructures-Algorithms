import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution{
    public private static Char[][] TOKENS = {{'{','}'},{'(',')'},{'['.']'}};
    
    public static boolean isOpen(char c){
        for(char[] array:TOKENS){
            if(array[0]==c){
                return true;
            }
        }
        return false;
    }

    public static boolean mathches(char open,char close){
        for(char[] array:TOKENS){
            if(array[0]==open){
                return array[1]==close;
            }
        }
        return false;
    }

    public static boolean isBalanced(String exp){
        Stack<character> stack = new Stack<character>();
        for(char c:exp.toCharArray()){
            if(isOpen(c)){
                stack.push(c);
            }
            else{
                if(stack.isEmpty() || !mathches(stack.pop(),c)){
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }
}