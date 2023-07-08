package proj2;

import java.util.*;

public class SetTest {

	public static void main(String[] args) {
		Set<String> myset = new HashSet<String>();
		
		myset.add("one"); myset.add("one");
		myset.add("two");
		myset.add("three");
		
		System.out.println("All elements:" + myset);
		
		//using iterator to print all the elements
		Iterator<String> mysetitr = myset.iterator();
		while (mysetitr.hasNext()) {
			System.out.println(mysetitr.next());
		}
		
		// using for loop to print all elements
		for(String str: myset) {
			System.out.println("forloop:" + str);
		}
		

	}

}
