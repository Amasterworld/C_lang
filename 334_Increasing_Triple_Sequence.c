/*C version for problem 334 - leetcode. The more detail and explanation to solve this problem pls see C++ version */

bool increasingtriplet(int* nums, int numsSize){
  
  int first  = INT_MAX, second = INT_MAX;
  for(int i = 0; i < numSize; ++i){// the array in C after passing to function, it is decayed into pointer, so we cannot get its size anymore
     
    if(nums[i] <= first){
      first = nums[i];
    }
    else if(nums[i] <= second){
      
      nums[i] = second;
    }
    else
        return true;
  }
  return false;
}
