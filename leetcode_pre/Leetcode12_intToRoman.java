package coding;

public class Leetcode12_intToRoman {
    public String intToRoman(int num) {
        
        String [] first = {"", "M", "MM", "MMM"};
        String [] second = {"","C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        String [] third = {"","X", "XX", "XXX", "XL", "L","LX","LXX","LXXX","XC"};
        String [] fouth = {"", "I", "II", "III", "IV", "V","VI","VII","VIII", "IX"};
        
        String res = "";
        if(num/1000 != 0)
            res += first[num/1000];
        if((num%1000)/100 != 0)
            res += second[(num%1000)/100];
        if((num%100)/10 != 0)
            res += third[(num%100)/10];
        if((num%10) != 0)
            res += fouth[num%10];
        return res;
    }
}
