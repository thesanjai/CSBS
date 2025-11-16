import java.io.*;
import java.net.*;
import java.util.Base64;

public class DirectoryServer {
    private static final String SECRET_KEY = "MySecretKey123";

    public static void main(String[] args) {
        int port = 5000;

        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Server started. Waiting for client...");

            while (true) {
                try (
                    Socket clientSocket = serverSocket.accept();
                    BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                    PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true)
                ) {
                    System.out.println("Connected to client: " + clientSocket.getInetAddress());

                    String encryptedRequest = in.readLine();
                    String request = decrypt(encryptedRequest);
                    System.out.println("Received request: " + request);

                    if (request.startsWith("list ")) {
                        String dirPath = request.substring(5);
                        File directory = new File(dirPath);

                        if (directory.exists() && directory.isDirectory()) {
                            StringBuilder response = new StringBuilder("Files and Directories in " + dirPath + ":\n");

                            String[] fileList = directory.list();
                            if (fileList != null) {
                                for (String file : fileList) {
                                    response.append(file).append("\n");
                                }
                            }
                            out.println(encrypt(response.toString()));
                        } else {
                            out.println(encrypt("Error: Directory does not exist - " + dirPath));
                        }
                    } else {
                        out.println(encrypt("Invalid request from client."));
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static String encrypt(String data) {
        StringBuilder encrypted = new StringBuilder();
        for (int i = 0; i < data.length(); i++) {
            encrypted.append((char) (data.charAt(i) ^ SECRET_KEY.charAt(i % SECRET_KEY.length())));
        }
        return Base64.getEncoder().encodeToString(encrypted.toString().getBytes());
    }

    private static String decrypt(String encryptedData) {
        byte[] decodedBytes = Base64.getDecoder().decode(encryptedData);
        String decoded = new String(decodedBytes);
        StringBuilder decrypted = new StringBuilder();
        for (int i = 0; i < decoded.length(); i++) {
            decrypted.append((char) (decoded.charAt(i) ^ SECRET_KEY.charAt(i % SECRET_KEY.length())));
        }
        return decrypted.toString();
    }
}
