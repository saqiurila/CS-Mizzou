import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.net.Socket;
import java.util.Scanner;

/**
 * @author FNU Saqiurila
 * @id 14227763
 * @data Dec.19 2014
 * @description Client side of chat room
 */
public class Client {
	public static void main(String args[]) throws Exception {
		String host = "127.0.0.1";
		int port = 17763;
		// build connection with server
		Socket socket = new Socket(host, port);
		Writer writer = new OutputStreamWriter(socket.getOutputStream());
		Scanner scanner = new Scanner(System.in);	
		BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
		System.out.println("Please input a command:");
		while (true) {			
			// Read commands from the current client
			String command = scanner.next();
			if (command.equals("send")) {
				writer.write(command + " " + scanner.nextLine());
			} else if (command.equals("login")) {
				String user = scanner.next();
				String psw = scanner.next();
				writer.write(command + " " + user + " " + psw);
			} else if (command.equals("logout")) {
				writer.write(command);
				//break;
			} else if (command.equals("newuser")) {
				String newUser = scanner.next();
				String newPsw = scanner.next();
				writer.write(command + " " + newUser + " " + newPsw);
			}
			writer.write("\n");
			writer.flush();
			// Receive msg from server
			String msg = br.readLine();
			System.out.println(msg);
			if (msg.equals("Server:logout")) {				
				break;
			}
		}
		scanner.close();
		socket.close();		
	}
}