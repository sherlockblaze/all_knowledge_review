/**
 * replace all space with "%02"
 */
public class ReplaceAllSpaces {
    public String replaceAllSpaces (String originStr) {
        char[] replaceStr = {'%', '0', '2'};
        char[] originChar = originStr.toCharArray();
        int spaceSize = 0;
        int strSize = originStr.length();
        //get space size in list
        for(char c : originChar) {
            if (c == ' ') {
                spaceSize ++;
            }
        }
        int newStrSize = strSize + 2 * spaceSize;
        char[] newChar = new char[newStrSize];
        for (int i = strSize - 1, j = newStrSize - 1; i > -1 ; i--) {
            char value = originStr.charAt(i);
            if ( value == ' ') {
                for (int n = replaceStr.length - 1; n > -1; n--) {
                    newChar[j--] = replaceStr[n];
                }
            } else {
                newChar[j--] = value;
            }
        }
        return String.valueOf(newChar);
    }
}