import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Scanner;

public class DNSLookupAnalysis {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("=== DNS Lookup Analysis ===");
        System.out.print("Enter a hostname or IP address: ");
        String input = scanner.nextLine();

        try {
            // Forward lookup: Hostname to IP
            InetAddress[] addresses = InetAddress.getAllByName(input);
            System.out.println("\nForward Lookup (Hostname to IP):");
            for (InetAddress address : addresses) {
                System.out.println("Host: " + address.getHostName());
                System.out.println("IP  : " + address.getHostAddress());
                System.out.println("-----------------------------");
            }

            // If input is IP, try reverse lookup
            if (input.matches("\\d+\\.\\d+\\.\\d+\\.\\d+")) {
                InetAddress addr = InetAddress.getByName(input);
                System.out.println("Reverse Lookup (IP to Hostname): " + addr.getCanonicalHostName());
            }

        } catch (UnknownHostException e) {
            System.out.println("Error: Unable to resolve " + input);
        }

        scanner.close();
    }
}
