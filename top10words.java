//////////////////Program to find count of each word in a document////////////////////////
import java.io.*;
import java.util.*;
class top10words{
	public static void main(String args[]) throws IOException{
		File f=new File("Reflections of Trusting Trust Summary.txt");
		BufferedReader br=new BufferedReader(new FileReader(f));
		//FileReader
		HashMap<String,Integer> hm=new HashMap<String, Integer>();

		String arr;
		String array[];
		while((arr=br.readLine())!=null){
			array=arr.split(" ");
			for(int i=0;i<array.length;i++){
				if(hm.containsKey(array[i])){
					int val=1+hm.get(array[i]);
					hm.put(array[i],val);
				}
				else{
					hm.put(array[i],1);
				}
			}

		}
		//Set set=hm.keySet();
		//Iterator i=set.iterator();
		

		for (Map.Entry<String, Integer> entry : hm.entrySet())
		{
		    System.out.println(entry.getKey() + "/" + entry.getValue());
		}
		System.out.print(hm.size());


	}
}