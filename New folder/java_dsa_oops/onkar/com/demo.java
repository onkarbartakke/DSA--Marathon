package onkar.com;

import java.util.Scanner;
import java.util.Stack;

public class demo {
    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);

        System.out.println("Enter the size of the arr : ");
        int n = scn.nextInt();

        int []a = new int[n];
        System.out.println("Enter the n numbers : ");

        for(int i = 0 ; i < n ; i++)
        {
            a[i] = scn.nextInt();
        }

        int res  = 0;

        Stack<Integer> st = new Stack<>();
        st.push(Integer.MAX_VALUE);

        for(int i = 0 ; i < n ; i++)
        {
            while(!st.empty() && st.peek() <= a[i])
            {
                int minEle = st.peek();
                st.pop();

                res += (minEle * Math.min(st.peek() , a[i]));
            }

            st.push(a[i]);
        }

        while(st.size() > 2)
        {
            int minEle = st.peek();
            st.pop();

            res += (minEle * st.peek());
        }

        System.out.println("Result is : "+res);
    }
}
