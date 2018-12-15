public class InsertSort{
	/**
     * find the key's position in the sequenced array
     * @param arrays
     */
    public static void insertSortMethod(int[] arrays) {
        int arrLength = arrays.length;
        for (int i = 1; i < arrLength; i++) {
            int key = arrays[i];
            int j = i - 1;
            while (j >= 0 && arrays[j] > key) {
                arrays[j + 1] = arrays[j];
                j--;
            }
            arrays[j + 1] = key;
        }
    }
}