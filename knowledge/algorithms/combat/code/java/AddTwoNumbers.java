public class AddTwoNumbers {
	public static void addTwoNumber(List<Integer> num1, List<Integer> num2) {

        List<Integer> result = new LinkedList<Integer>();
        int i = num1.size();
        int j = num2.size();
        int overflow = 0;

        while (true) {
            if (i > 0) {
                overflow = overflow + num1.get(--i);
            }
            if (j > 0) {
                overflow = overflow + num2.get(--j);
            }
            result.add(0, overflow % 10);
            overflow = overflow / 10;
            if (i == 0 && j == 0 && overflow == 0) {
                break;
            }
        }
    }
}