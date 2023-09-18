#include<bits/stdc++.h>

using namespace std;

/*
So accordinng to the Nim formula if there are 2 platers
who play optimally in the game of piles and stones then u take cummulative XOR of the entire array
if that XOR is 0 that means player will always lose and if non zero that means player 1 will always
win


MEX -> Smallest non negative number which is not present in the set


Grundy(N) = MEX(Grundy(N-1) , Grundy(N-2));
This is because according to the problem statement we can go from Nth state to N-1 and N-2 th state


Sprague Grundy Theroem

lets say they are N piles p1 , p2 , p3 - - - pn

p1 pile has p1 stones in it
p2 has p2 stones in it and so on

if Grundy(p1)^Grundy(p2)^ - - - ^Grundy(pn) = 0 player 1 will always lose
and if non zero player 1 will win
*/