package cracking_the_interview5.chapter1;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by ankit.c on 27/07/16.
 */
public class _4_ReplaceChar {
    private static void replace(char[] str1, char[] str2, char c){
        if(str1.length == 0 || str2.length == 0) return;
        int count = 0;
        for(int i=0; i<str1.length ;i++){
            if(str1[i] == c)
                count++;
        }

        int j = str1.length - 1 + (str2.length - 1)*count;
        for(int i = str1.length -1 ; j>i && i>=0; i--){
            if(str1[i]!=c)
                str1[j--] = str1[i];
            else{
                for(int k = str2.length - 1; k>=0 ; k--, j--)
                    str1[j] = str2[k];
            }
        }
    }

    public static void main(String[] args) throws IOException {
        InputStreamReader is = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(is);
        String str1 = br.readLine();
        String str2 = br.readLine();
        char[] arr1 = new char[str1.length() + 100];
        for(int i=0;i<str1.length();i++){
            arr1[i] = str1.charAt(i);
        }
        System.out.println(arr1 + "*");
        System.out.println("*" + str2 + "*");
        replace(str1.toCharArray(), str2.toCharArray(), ' ');
        System.out.println(arr1);
    }
}
