package com.bingyu.foundation.algorithms;

import java.util.HashSet;
import java.util.Set;

/**
 * find two numbers in the arrays
 * where a number adds the other equals the target
 */
public class TwoSum {
    public static int[] tuoSum (int[] arrays, int target) {
        int arrLength = arrays.length;
        int[] result = new int[2];
        Set<Integer> passNum = new HashSet<Integer>(arrLength);
        for (int i = 0; i < arrLength; i++) {
            if (passNum.contains(arrays[i])) {
                continue;
            }
            int remain = target - arrays[i];
            for (int j = i + 1; j < arrLength; j++) {
                if (remain == arrays[j]) {
                    result[0] = arrays[i];
                    result[1] = arrays[j];
                    break;
                } else {
                    passNum.add(arrays[i]);
                }
            }
        }
        return result;
    }
}
