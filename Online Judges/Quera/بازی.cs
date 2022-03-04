/*
 * https://quera.org/problemset/52543/
 * Author: https://github.com/smh997/
 */
using System;

class Sum{
    public static void Main(){
        int n = int.Parse(Console.ReadLine());
        int [] a = new int[100];
        string[] s = Console.ReadLine().Split();
        for(int i = 0; i < n; i++){
            a[i] = int.Parse(s[i]);
        }
        int temp;
        for (int i = 0; i < n - 1; i++)  
        {
            for (int j = 0; j < n - i - 1; j++)  
            { 
                if (a[j] > a[j + 1])  
                { 
                    temp = a[j]; 
                    a[j] = a[j + 1]; 
                    a[j + 1] = temp;
                } 
            }
        }
        for(int i = 0; i < n / 2; i++){
            Console.Write(a[n - 1 - i] + " " + a[i] + " ");
        }
        if(n % 2 == 1){
            Console.WriteLine(a[n / 2]);
        }
        else{
            Console.WriteLine();
        }
        
    }
}