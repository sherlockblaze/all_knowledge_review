/**
 * find the target in an increasing tow-dimension array
 */
public class SearchInTwoDimensionArray {
    public static int isExist (int[][]array, int target) {
        int rows = array.length;
        int columns = array[0].length;
        int j = columns - 1;
        for (int i = 0 ; i < rows; ) {
            if (target == array[i][j]) {
                return 1;
            }
            if (target < array[i][j]) {
                j--;
            } else {
                i++;
            }
            if (j < 0) {
                break;
            }
        }
        return 0;
    }
}

