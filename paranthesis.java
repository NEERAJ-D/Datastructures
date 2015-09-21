/////////////////Program to print valid permuation of paranthesis///////////////////////////
import java.io.*;
import java.util.*;
class paranthesis{
	//int open,close;
	public static void main(String args[]){
		int n;
		Scanner sc=new Scanner(System.in);
		n=sc.nextInt();
		printBraces("",n,n);
	}
	public static void printBraces(String str,int open,int close){
		if(open==0 && close==0){
			System.out.println(str);
			return;
		}
		if(close<open){
			return;
		}
		if(open>0){
				//System.out.println(str);
				//str+="(";
					
				printBraces(str+"(",open-1,close);
				
			}
		if(close>open){
				//System.out.println(str);
				//str+=")";
				
				printBraces(str+")",open,close-1);
				//System.out.println(str);
			}

		

	}

	
}