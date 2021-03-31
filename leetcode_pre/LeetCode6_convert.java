package coding;

import java.util.ArrayList;
import java.util.List;

public class LeetCode6_convert {
	public String convert(String s, int numRows) {
        if(numRows == 1) 
        	return s;
        
        List<StringBuilder> rows = new ArrayList<>();
        boolean goningDown = false;
        int curRow = 0;
        
        for(int i =0; i < Math.min(numRows, s.length()); i++) {
        	rows.add(new StringBuilder());
        }
        
        for(char ch: s.toCharArray()) {
        	rows.get(curRow).append(ch);
        	if(curRow == 0 || curRow == numRows-1) 
        		goningDown = !goningDown;
        	curRow += goningDown ? 1 : -1;
        }
        
        StringBuilder ret = new StringBuilder();
        for(StringBuilder sb: rows) 
        	ret.append(sb);
        return ret.toString();
        
        } 
}
