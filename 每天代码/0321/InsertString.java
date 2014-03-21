public class InsertString{
	public String func(String str, int minLen, char c){
		int len = str.length();
		if (len >= minLen)
			return str;
		char temp[] = new char[minLen - len];
		for (int i = 0; i < minLen - len; ++i) temp[i] = c;
		String rlt = new String(temp);
		rlt += str;
		return rlt;
	}
	
	public static void main(String[] args){
		InsertString a = new InsertString();
		System.out.println(a.func("a", 3, '#'));
		System.out.println(a.func("abcd", 3, '#'));
	}
}