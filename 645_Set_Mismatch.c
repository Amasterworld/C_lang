/* SOLUTION for this problem is almost the same for C++ version, the only a bit different is that  for C language,
we do not have a build in hastable(we can use hashtable from third party) hence we can use sort (qsort) instead and still using
sum of full elelemts in nums - sum of current elements in nums = missing number

time complexity is O(n*logn), if we use hashtable TC is O(n);
*/

int comp (const void * a, const void * b){
  return *((int *)a) - *((int *)b);
}
  int* findErrorNums(int* nums, int numsSize, int* returnSize){
    
    /*create dynamic ans array (in C++ vector ans) with size 2*/
    int * ans = (int*) malloc (sizeof(int) * 2);
    *returnSize = 2;
    int sum_miss_ele = 0;
    qsort(nums, numsSize, sizeof(int), comp);
    
  /*find the repeatable number, the repeatable number is: nums[i] == nums[i+1] after sorting*/   
    
    for(int i = 0; i < numsSize - 1; ++i){
      if (nums[i] == nums[i+1]){
        ans[0] = nums[i];
      }
      sum_miss_ele += nums[i];
    }
      /*but so far the sum miss to  + the last number in nums*/
      sum_miss_ele += nums[numsSize - 1];
    /*now finding the missing number */
    int sum_full_ele = numsSize*(numsSize + 1)/2;
    ans[1] = sum_full_ele - sum_miss_ele + ans[0];
    return ans;
    
 }
