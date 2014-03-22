import java.util.*;
import java.lang.*;
import java.io.*;

class Search
{
	//array为一个有序数组，若n存在则返回位置，若n不存在则返回插入位置
	public int getLoc(int[] array, int n)
	{
		int i = 0, j = array.length;
		while (i < j)
		{
			int mid = i + ((j - i)>>1);
			if (n == array[mid])
				return mid;
			else if (n < array[mid])
				j = mid - 1;
			else
				i = mid + 1;
		}
		if (array[i] >= n)
			return i;
		else 
			return i + 1;
	}
}

public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Search s = new Search();
		int []a = new int[]{1,3,6,9,13};
		System.out.println(s.getLoc(a, 3));
		System.out.println(s.getLoc(a, 5));
	}
}