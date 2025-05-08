import java.net.*;
import java.io.*;

class Client {
    public static void main(String ar[]) {
        try {
            Socket socket = new Socket("localhost", 2000);
            BufferedReader bufferreader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            PrintStream printstream = new PrintStream(socket.getOutputStream());

            BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));
            System.out.print("Enter filename to request from server: ");
            String filename = userInput.readLine();
            printstream.println(filename);

            // Receive file content or error message from server
            InputStream inputStream = socket.getInputStream();
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            byte[] buffer = new byte[4096];
            int bytesRead;
            while ((bytesRead = inputStream.read(buffer)) != -1) {
                baos.write(buffer, 0, bytesRead);
            }
            String serverResponse = baos.toString();

            if (serverResponse.equals("File not found!")) {
                System.out.println("Server: " + serverResponse);
            } else {
                System.out.print("Enter filename to save the content: ");
                String outputFilename = userInput.readLine();
                FileOutputStream fos = new FileOutputStream(outputFilename);
                fos.write(baos.toByteArray());
                fos.close();
                System.out.println("File received and saved as " + outputFilename);
            }

            socket.close();
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}