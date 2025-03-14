//1011001
import java.io.*;
import java.util.*;
class Hamming
{
    public static void main(String args[])throws IOException
    {
        Scanner sc=new Scanner(System.in);
        int m,h[],n,d[],i=0,j,k,x=0,sum=0,count=0;
        System.out.print("Enter no. of data bits : ");
        n=sc.nextInt();
        while(n>(Math.pow(2,i)))
        {
            i++;
        }
        x=i+1;
        m=x+n;
        d=new int[n+1];
        h=new int[m+1];
        System.out.print("Enter data bits : ");
        for(i=1;i<=n;i++)
            d[i]=sc.nextInt();
        for(i=1,j=0,k=1;k<=m;k++)
        {
            if (Math.pow(2,j)==k)
            {
                h[k]=0;j++;
            }
            else
            {
                h[k]=d[i];i++;
            }
        }
        for(j=0,k=1;k<=m;k++)
        {
            if (Math.pow(2,j)==k)
            {
                h[k]=0; count=0; sum=0;
                for(int c=k;c<=m;c++)
                {
                    if(count<k)
                    {
                        sum+=h[c];
                        count++;
                    }
                    else
                    {
                         c+=k-1;
                        count=0;
                    }
                }
                if(sum%2!=0)
                    h[k]=1;
                else
                    h[k]=0;
                j++;
            }
        }
        System.out.print("Transmitted codeword is : ");
        for(i=1;i<=m;i++)
            System.out.print(h[i]);
    }
}
