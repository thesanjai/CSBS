import java.io.*;
import java.net.*;
class Test2
{
    public static void main(String ar[])
    {    
        String x="";
        try
        {
            File x1=new File("TestReceiver.java");
            if(x1.exists())
            {
                FileInputStream fin=new FileInputStream(x1);    
                System.out.println((char)fin.read());
                byte b;
                while((b=(byte)fin.read())!=-1)
                {
                    x=x+(char)b;
                    System.out.print((char)b);
                }
            System.out.println(x);
            }
            else
            {
                System.out.println("File not found");
            }
            FileOutputStream fout=new FileOutputStream("csbs1.txt");
            fout.write(x.getBytes());
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }
}
