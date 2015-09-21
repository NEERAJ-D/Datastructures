import java.io.*;
import java.util.*;
class palindrome{

	public static void main(String args[]) throws IOException{
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String str=br.readLine();			//Taking input and storing in string
		char[] array=str.toCharArray();		//Storing string as character array
		int left,right;						//Pointer to run and get palindromes
		Set<String> palindrome=new HashSet<String>();		//Storing all palindormes in a Set so that only distinct are saved
		
		//////////////////////////////////////Finding all palindromes//////////////////////////////////
		
		/**************************Checking odd length palindromes**********************************/ 
		for(int i=0;i<array.length;i++){
			pointer=i;
			left=i;
			right=i;
			while(left>-1 && right<array.length && array[left]==array[right]){
				palindrome.add(str.substring(left,right+1));	//Add string to hashset if not present
				left--;
				right++;
			}
		}
		
		/*************************Checking even length palindromes***********************************/
		for(int i=1;i<array.length;i++){
			left=i-1;
			right=i;
			while(left>-1 && right<array.length && array[left]==array[right]){
				palindrome.add(str.substring(left,right+1));
				left--;
				right++;
				
			}
		}
		int count=0;
		
		/*************************Counting and Printing all palindromes********************************/
		for(String pdrome : palindrome){
			count++;
			System.out.println(pdrome);
		}
		System.out.println(count);
	}	
}