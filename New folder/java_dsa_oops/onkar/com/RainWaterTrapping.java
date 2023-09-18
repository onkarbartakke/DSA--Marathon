package onkar.com;

import java.util.Scanner;
import java.util.Stack;

public class RainWaterTrapping {

    public static int RainWaterTrap(int []a, int n)
    {
        int res = 0;

        Stack<Integer> st = new Stack<>();

        for(int i = 0 ; i < n ; i++)
        {
            while(!st.empty() && a[st.peek()] < a[i])
            {
                int idx = st.peek();
                st.pop();
                //System.out.println("****        Popped "+a[idx]);
                if(st.empty())
                {
                    //System.out.println("Breaking out");
                    break;
                }


                int h = Math.min(a[st.peek()] , a[i]) - a[idx];
                //System.out.println("hts min among"+a[i]+"   "+st.peek());
                int len = (i - st.peek() - 1);
                //System.out.println("Height : "+h);
                //System.out.println("Length "+len);
                if(h > 0)
                    res += (len*h);
            }

            st.push(i);
            //System.out.println("Pushed "+a[i]);
        }
        //System.out.println("Res : "+res);
        return res;
    }


    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        System.out.println("Enter the num of ele : ");
        int n = scn.nextInt();

        int []a = new int[n];

        System.out.println("Enter the numbers : ");

        for(int i = 0 ; i < n ; i++)
        {
            a[i] = scn.nextInt();
        }

        System.out.println("Water trapped is : "+ RainWaterTrap(a,n));
    }
}
