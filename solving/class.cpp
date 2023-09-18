#include<bits/stdc++.h>

using namespace std;

struct Node
{
    char *studentName;
    int Total_marks;
    Node *left;
    Node *right;

    Node(int val , char *arr)
    {
        studentName = arr;
        Total_marks = val;
        left = NULL;
        right = NULL;
    }
};
int main()
{
    int val;
    char arr[20];

    cout<<"Enter the name : ";
    cin>>arr;
    cout<<"\nEnter the val : ";
    cin>>val;


    Node *r = new Node(val,arr);

    cout<<"\n\n";

    cout<<r->Total_marks<<" "<<r->studentName;
}