219. Contains Duplicate II
/*

Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/

/*SOLUTION: this problem can be solved very easy if we use hash table:
   traverse the nums, if (hash_table.count(nums[i]) >= 1) {// if nums[i] is present in the hash table
      if(i - hast_table[nums[i]] <= k) return true;
      
   } 
if nums[i] is not present in the hash_table hence add its and its postion (i) in the hash_table: hash_table[nums[i]] = i;
- time complexity O(n), space complexity O(n) we must use hash table for containing the elements. UNFORTUNATELY, C does not have build in hash table so ...

Second SOLUTION: use qsort (sort in C++)
  create a struct contain idx and value;
  traverse the nums and then add nums[i] and its index(i) to value and idx to the corresponding array
  then sort elements in array by value and by idx if the elements have the same value.
  finally, traverse the array, and check the condtion if match return true else return false
  TC O(nlogn) because we need to sort, SC O(n)
*/

typedef struct value_idx{
  int value;
  int idx;
} ITEM; 
 
static ITEM val_idx[100000];
/*to use qsort in C language we should create a comparator*/
/*in C++ we can do the same by struct comp{bool operator()(const ITEM& a, const ITEM& b){//logic here}   }*/

int comp(const void* a, const void* b){
  if ( (ITEM*)a)->value != (ITEM*)b)->value ){
    return (ITEM*)a)->value - (ITEM*)b)->value;
  }
  else{
    return (ITEM*)a)->idx - (ITEM*)b)->idx;
  }

}

bool containsNearbyDuplicate(int* nums, int numsSize, int k){

  /*traverse the nums and add nums[i] and i to the array*/
  for(int i = 0; i < numsSize; ++i){
    
    val_idx[i].value = nums[i];
    val_idx[i].idx = i;
  
  }
  /*sort the array*/
  qsort(val_idx, numsSize, size(ITEM), comp);
  
  /*traverse the array and check conditions*/
  
  for(int i = 0; i < numsSize  - 1; ++i){
    
    if (val_idx[i].value == val_idx[i+1].value){
      if(val_idx[i].idx - val_idx[i+1].idx <= k){
        return true;
      }
      
    
  }
  return false;
  
  
  
}
