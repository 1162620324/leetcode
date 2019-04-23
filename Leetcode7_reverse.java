package coding;

public class Leetcode7_reverse {
	public static int reverse(int x) {
	boolean flag = false;
    if(x == Integer.MAX_VALUE || x == Integer.MIN_VALUE)
        return 0;
	if(x < 0) {
			x *= -1; 
			flag = false;
		}
		else
			flag = true;
	StringBuilder temp = new StringBuilder(((Integer)x).toString()).reverse();
	int ret = 0;
	if(Double.parseDouble(temp.toString()) > Integer.MAX_VALUE)
		return 0;
	else 
		 ret = Integer.parseInt(temp.toString());
	if(flag)
		return ret;
	else 
		return ret*-1;

}
}
