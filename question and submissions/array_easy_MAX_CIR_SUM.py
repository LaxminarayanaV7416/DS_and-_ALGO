
def kadane(a): 
    n = len(a) 
    max_so_far = 0
    max_ending_here = 0
    for i in range(0, n): 
        max_ending_here = max_ending_here + a[i] 
        if (max_ending_here < 0): 
            max_ending_here = 0
        if (max_so_far < max_ending_here): 
            max_so_far = max_ending_here 
    return max_so_far 

def maxCircularSum(a): 
  
    n = len(a) 
  
    # Case 1: get the maximum sum using standard kadane's 
    # algorithm 
    max_kadane = kadane(a) 
  
    # Case 2: Now find the maximum sum that includes corner 
    # elements. 
    max_wrap = 0
    for i in range(0, n): 
        max_wrap += a[i] 
        a[i] = -a[i] 
  
    # Max sum with corner elements will be: 
    # array-sum - (-max subarray sum of inverted array) 
    max_wrap = max_wrap + kadane(a) 
  
    # The maximum circular sum will be maximum of two sums 
    if max_wrap > max_kadane: 
        return max_wrap 
    else: 
        return max_kadane 

if __name__ == '__main__':
    a = [10, -3, -4, 7, 6, 5, -4, -1]
    print(maxCircularSum(a))