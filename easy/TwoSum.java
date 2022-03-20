import java.util.*;
import javafx.util.*;

/**
 * Link: https://leetcode.com/problems/two-sum/
 * 
 * Problem Statement
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 * 
 * Eg: 1
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 * 
 * Eg: 2
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 * 
 * Eg: 3
 * Input: nums = [2,7,11,15], target = 22
 * Output: [1,3]
 *
 */
public class TwoSum
{
    public static void main(String[] args) {
        int[] arr = {2,7,11,15};
        int target = 22;
        TwoSum obj = new TwoSum();
        System.out.println(obj.twoSumViaSorting(arr, target));
        System.out.println(obj.twoSumViaHashMap(arr, target));
    }
    
    /**
     * TC: O(nlogn)
     * SC: O(n)
     */
    private int[] twoSumViaSorting(int[] nums, int target) {
        ArrayList<Pair<Integer, Integer>> list = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            list.add(new Pair(i, nums[i]));
        }
        
        Collections.sort(list, new Comparator<Pair<Integer, Integer>>() {
            @Override
            public int compare(final Pair<Integer, Integer> p1, final Pair<Integer, Integer> p2) {
                return p1.getValue().compareTo(p2.getValue());
            }
        });

        int[] result = new int[2];
        int i = 0, j = nums.length - 1;
        int tempSum;
        while (i < j) {
            tempSum = list.get(i).getValue() + list.get(j).getValue();
            if (tempSum == target) {
                result[0] = list.get(i).getKey();
                result[1] = list.get(j).getKey();
                break;
            }
            else if (tempSum > target) {
                j--;
            }
            else {
                i++;
            }
        }
        
        return result;
    }
    
    /**
     * TC: O(n)
     * SC: O(n)
     */
    private int[] twoSumViaHashMap(int[] numbers, int target) {
        HashMap<Integer,Integer> indexMap = new HashMap<Integer,Integer>();
        for(int i = 0; i < numbers.length; i++){
            Integer requiredNum = (Integer)(target - numbers[i]);
            if(indexMap.containsKey(requiredNum)){
                int toReturn[] = {indexMap.get(requiredNum), i};
                return toReturn;
            }

            indexMap.put(numbers[i], i);
        }
        
        return null;
    }
}
