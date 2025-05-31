import java.util.Map;
import java.util.Vector;

class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Vector <Integer> v = new Vector<>();
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i = 0; i < nums1.length; i++){
            mp.put(nums1[i], mp.getOrDefault(nums1[i], 0) + 1);
        }
        for(int i = 0; i < nums2.length; i++){
            if(mp.containsKey(nums2[i]) && mp.get(nums2[i]) > 0){
                v.addElement(nums2[i]);
                mp.put(nums2[i], mp.get(nums2[i]) - 1);
            }
        }
        int[] result = new int[v.size()];
        for(int i = 0; i < v.size(); i++){
            result[i] = v.get(i);
        }
        return result;
    }
}