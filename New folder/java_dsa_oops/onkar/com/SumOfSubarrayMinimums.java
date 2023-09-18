package onkar.com;

import java.util.Scanner;
import java.util.Stack;

public class SumOfSubarrayMinimums {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.println("Enter the size of arr : ");

        int n = scn.nextInt();

        int []a = new int[n];

        System.out.println("Enter the nums of arr : ");

        for(int i = 0 ; i < n ; i++)
        {
            a[i] = scn.nextInt();
        }

        Stack<Integer>st = new Stack<>();
        int sum = 0;
        for(int i = 0 ; i < n; i++)
        {
            while(!st.empty() && a[st.peek()] > a[i])
            {
                int idx = st.peek();
                st.pop();

                int right = i - idx;
                int prevStop = -1;

                if(!st.empty())
                    prevStop = st.peek();

                int left = idx - prevStop;

                sum += (left*right*a[idx]);
            }

            st.push(i);
        }


    }
}
