package proj2;

public class IntegerReverse {

	public static void main(String[] args) {
		int num = 3789123;
		int rev_num = 0, tmp;
		
		tmp = num;
		while (tmp != 0) {
			int reminder = tmp % 10;
			rev_num = rev_num*10 + reminder;
			tmp = tmp/10;
		}
		
		System.out.println("Reversed Number: " + rev_num);
	}
}
