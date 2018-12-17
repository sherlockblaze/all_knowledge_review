import java.util.HashMap;
import java.util.Map;

/**
 * find two numbers in the arrays
 * where a number adds the other equals the target
 */
public class TwoSum {

    public static int[] twoSum (int[] arrays, int target) {
        Map<Integer, Integer> indexMap = new HashMap<Integer, Integer>(arrays.length);
        int[] result = new int[2];
        for (int i = 0; i < arrays.length; i++) {
            if (indexMap.get(arrays[i]) != null){
                continue;
            }
            indexMap.put(arrays[i], i);
            if (indexMap.get(target - arrays[i]) != null) {
                result[0] = indexMap.get(arrays[i]);
                result[1] = indexMap.get(target - arrays[i]);
                break;
            }
        }
        return result;
    }
}