/*

piles = [3, 6, 7, 11], h = 8
output = 





[3, 6, 7, 11]


          v              
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]

output = 4 


My idea: the space of possible answers for the minimum speed that koko can eat all bananas is 
[1,2,..,piles_max]


So we can solve it trying for each possibilitie of solution check if it meet the requirement of time 
and pikcup the min solution that allows koko eat all bananas 

the time complexity for find the max to construct array of possible solutions is O(n) find the max value 

the time complexity for check each possibilitie is O(n) but in worst case we try logn possibilities so 
the big o for this algorithm would be nlogm, considering that m is the highest and this is going to be nlogn 

but since we have the complexity of nlogn, we could do a sort to make easier find the maximum, since its same big o, so we can sort piles

looks to me that this would work 

example


[2, 2, 5] h = 1000 
the ouptout here would be 1, that is not in the space of our array so creat the array that goes for [1, piles_max] is necessary

piles = [30,11,23,4,20], h = 6

after sorting would be 

[4, 11, 20, 23, 30], h = 6

we creat the vector space solution

it goes for [1, 2, ..., 29, 30]

we make a guess of 15, but eating at 15 speed koko cant eat in 6 hours, now we discard left part of the arry, now we have [15, 16, ..., 29, 30]

mid here is 22, at a speed 22 koko also cant eat, so again we discard left half 

[23, 24, ..., 30] here we have 26, koko can eat at the speed of 26, so it marks 26 as the best approach, and discard right half, in any possible solution for left dont work, we can say 26

the mid now would be 24, also work, follow the logic above 

guess 23, and now the array is size 1, so we are at our best guess, return 23

*/

class Solution {
public:
    bool kokoCanEat(const vector<int>& piles, int h, int guess) {
        
        long long hours = 0;

        for (int pile : piles) {
            hours += pile / guess;
            if (pile % guess > 0) ++hours;
            if (hours > h) return false;
        }
        
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = INT_MIN;
        for (int pile : piles) {
            if (pile > right) right = pile;
        }

        int best_guess = right;

        if (piles.size() == h) return best_guess;

        while (left <= right) {

            int mid = left + (right - left) / 2;
            
            if (!kokoCanEat(piles, h, mid)) {
                left = mid+1;
                continue;
            }

            best_guess = mid;
            right = mid-1;
        }

        return best_guess;
    }
};
