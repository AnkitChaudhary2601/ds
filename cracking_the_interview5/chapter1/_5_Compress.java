package cracking_the_interview5.chapter1;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.List;

/**
 * Created by ankit.c on 27/07/16.
 */
public class _5_Compress {
    public static int digits(int n){
        int d = 0;
        do{
            d++;
            n/=10;
        } while(n!=0);
        return d;
    }

    public static boolean isCompressable(String s){
        int count = 0;
        for(int i=0,j=0; i<s.length(); i=j){
            for(j=i+1; j<s.length() && s.charAt(i) == s.charAt(j); j++);
            int n = j-i;
            count += (n - 1 -  digits(n));
        }
        return count > 0;
    }

    public static String compress(String s){
        if(s == null || s.length()==0) return s;

        if(!isCompressable(s)) return s;

        StringBuilder b = new StringBuilder();
        for(int i=0, j=0; i<s.length(); i=j){
            b.append(s.charAt(i));

            for(j=i+1; j<s.length() && s.charAt(i)==s.charAt(j); j++);
            b.append(j-i);
        }

        return b.toString();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        System.out.println(compress(str));
        Integer i = 5;
        i.toString();

    }
}
