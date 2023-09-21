package proj2;

import java.util.Arrays;

public class ArrayTest {

	public static void main(String[] args) {
		
		int[] a = {10,1,5,20,19,27,37};
		System.out.println("Array1 vals:" + a.toString());
		
		System.out.println("Array2 vals:" + Arrays.toString(a));
		
		System.out.println("print variable a:" + a);
		
		int sizeofa = a.length;
		for(int i = 0; i < sizeofa; i++) {
			System.out.println(a[i]);
		}
	}

}