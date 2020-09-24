import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public int fibonacy(int x,int memo[n]){
    if(x<=0){
        return 0;
    }
    else if(x==1){
        return 1;
    }
    else if(memo[n]){
        memo[n] = fibonacy(x-1) + fibonacy(x-2);
    }
    return memo[n];
}