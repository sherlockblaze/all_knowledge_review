import java.util.HashMap;
import java.util.Map;

/**
 * find two numbers in the arrays
 * where a number adds the other equals the target
 */
public class TwoSum {

    public static int[] twoSum (int[] arrays, int target) {
        Map<Integer, Integer> targetMap = new HashMap<Integer, Integer>(arrays.length);
        int[] result = new int[2];
        for (int key : arrays) {
            targetMap.put(key, target-key);
            if (targetMap.containsValue(key)) {
                result[0] = target - key;
                result[1] = key;
                break;
            }
        }
        return result;
    }
}