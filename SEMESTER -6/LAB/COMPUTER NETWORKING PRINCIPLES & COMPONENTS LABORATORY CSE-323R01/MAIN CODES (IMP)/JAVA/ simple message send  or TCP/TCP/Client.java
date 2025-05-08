import java.net.*;
import java.io.*;
class Client
{
    public static void main(String ar[])
    {
        try
        {
            Socket s=new Socket("localhost",2000);
            BufferedReader br=new BufferedReader(new InputStreamReader(s.getInputStream()));
            String s1=br.readLine();
            System.out.println(s1);
       
            PrintStream pr=new PrintStream(s.getOutputStream());
            pr.println("Thank u");
            s.close();
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
       
    }
}