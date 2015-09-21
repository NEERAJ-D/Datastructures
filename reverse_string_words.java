///////Reversing a Strig///////
import java.io.*;
import java.util.*;
class Reverse{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		String str=sc.nextLine();
		char c[]=str.toCharArray();
		int i=0;
		int start=0,end=0;
		char temp=' ';
		for(i=0;i<c.length;i++){
			System.out.print(c[i]);
		}
		i=0;
		while(i<c.length){
			while(i<c.length && c[i]!=' ' ){
				i++;
			}
			//if(c[i]==' ')
				end=i-1;
			//else
			//	end=i;
			while(start<end){
				temp=c[end];
				c[end]=c[start];
				c[start]=temp;
				start++;
				end--;
			}
			start=i+1;
			i++;
		}
		for(i=0;i<c.length;i++){
			System.out.print(c[i]);
		}
	}
}