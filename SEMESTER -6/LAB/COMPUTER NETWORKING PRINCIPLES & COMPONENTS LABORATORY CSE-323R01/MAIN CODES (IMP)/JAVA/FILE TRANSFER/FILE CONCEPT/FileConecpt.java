import java.io.*;
import java.net.*;

public class FileConecpt {
    public static void main(String[] args) {
        try{
            String str = "";
            File file = new File("FileTransferServer.java");

            if(file.exists()){
                FileInputStream fis = new FileInputStream(file);
                byte b;
                while((b = (byte)fis.read()) != -1){
                    str += (char)b;
                }
                System.out.println(str);
                fis.close();
            }
            else{
                System.out.println("File not found!");
            }
            
            FileOutputStream fos = new FileOutputStream("Example.txt");
            fos.write(str.getBytes());
            fos.close();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}