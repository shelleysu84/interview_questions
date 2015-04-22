//活动安排问题

public class Activearr
{
	public static int greedselector(int [] s,int [] f,boolean [] a)
	{
		int n = s.length - 1;
		a [0] = true;
		int j = 1;
		int count = 1;
		
		for (int i = 1;i <= n;i ++)
		{
			if (s [i] >= f [j])
		  {
		  	a [i] = true;
		  	j = i;
		  	count ++;
		  	 
		  }	
		  else a [i] = false;
		  		
        }
        
        return count;
    
	}
	public static void main(String args [])
	{
		int count;
		int s [] = {1,3,0,5,3,5,6,8,8,2,12};
		int f [] = {4,5,6,7,8,9,10,11,12,13,14};
		boolean a [] = new boolean [11];
		
		Activearr aa = new Activearr();
		count = aa.greedselector(s,f,a);
		System.out.println("共有" + count + "活动可以举行:");
		System.out.println();
		for (int i = 0;i <= 10;i ++)
		   if (a [i] == true)
		      System.out.println("第" + i + "活动可以举行");
		      
	}
		  
}