import java.io.*;
import java.net.*;

class CRCServer {
    public static void main(String[] args) {
        try (ServerSocket server = new ServerSocket(5000)) {
            System.out.println("Server is waiting for connection...");
            Socket socket = server.accept();
            System.out.println("Client connected!");

            BufferedReader userInput = new BufferedReader(new InputStreamReader(System.in));
            PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

            System.out.print("Enter data bits (e.g., 1011001): ");
            String dataStr = userInput.readLine();
            int[] data = new int[dataStr.length()];
            for (int i = 0; i < dataStr.length(); i++)
                data[i] = dataStr.charAt(i) - '0';

            System.out.print("Enter divisor bits (e.g., 10011): ");
            String divisorStr = userInput.readLine();
            int[] divisor = new int[divisorStr.length()];
            for (int i = 0; i < divisorStr.length(); i++)
                divisor[i] = divisorStr.charAt(i) - '0';

            int[] transmitted = appendCRC(data, divisor);

            out.println(divisorStr);
            StringBuilder transmittedBuilder = new StringBuilder();
            for (int bit : transmitted) transmittedBuilder.append(bit);
            out.println(transmittedBuilder.toString());

            System.out.println("Sent Divisor   : " + divisorStr);
            System.out.println("Sent Data+CRC  : " + transmittedBuilder.toString());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static int[] appendCRC(int[] data, int[] divisor) {
        int[] extended = new int[data.length + divisor.length - 1];
        System.arraycopy(data, 0, extended, 0, data.length);
        int[] rem = divide(extended.clone(), divisor);
        for (int i = 0; i < rem.length; i++) {
            extended[data.length + i] = rem[i];
        }
        return extended;
    }

    static int[] divide(int[] div, int[] divisor) {
        for (int i = 0; i <= div.length - divisor.length; ) {
            for (int j = 0; j < divisor.length; j++) {
                div[i + j] ^= divisor[j];
            }
            while (i < div.length && div[i] == 0) i++;
        }
        int[] rem = new int[divisor.length - 1];
        System.arraycopy(div, div.length - rem.length, rem, 0, rem.length);
        return rem;
    }
}
