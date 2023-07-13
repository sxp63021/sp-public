package proj2;

public class StringReverse {
	
	public static void main(String[] args) {
		String mystr = "SuperCali";
		
		System.out.println("Original:" + mystr);
	
		char[] mystrchar = mystr.toCharArray();
		int mystrchar_sz = mystrchar.length;
		// swap 0 and n-1, 1 and n-2
		for (int i = 0; i < mystrchar_sz/2; i++) {
			char tmp = mystrchar[i];
			mystrchar[i] = mystrchar[(mystrchar_sz - 1 - i)];
			mystrchar[(mystrchar_sz - 1 - i)] = tmp;
		}
		
		System.out.println("Reversed String: " + new String(mystrchar));
	}

}
