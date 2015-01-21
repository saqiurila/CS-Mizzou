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
		// New thread to receive user's command
		Thread thread = new Thread(new Task(socket));
		thread.start();

		BufferedReader br = new BufferedReader(new InputStreamReader(
				socket.getInputStream()));
		// Receive message from the server
		while (true) {
			String msg = br.readLine();
			if (msg.equals("logout")) {
				thread.interrupt();
				socket.close();
				System.exit(0);
			}
			System.out.println(msg);
		}

	}

	/**
	 * Thread Class that deals with user's command
	 */
	static class Task implements Runnable {

		private Socket socket;

		public Task(Socket socket) {
			this.socket = socket;
		}

		public void run() {
			try {
				handleSocket();
			} catch (Exception e) {
				e.printStackTrace();
			}
		}

		private void handleSocket() throws Exception {
			Writer writer = new OutputStreamWriter(socket.getOutputStream());
			Scanner scanner = new Scanner(System.in);

			System.out.println("Please input a command:");
			String command = "";
			// Every loop receives and deals with one command
			while (true) {
				command = scanner.next();
				if (command.equals("send")) {
					String next = scanner.next();
					// Broadcast
					if (next.equals("all")) {
						writer.write(command + "all" + " " + scanner.nextLine());
					}
					// unicast
					else {
						writer.write(command + " " + next + " "
								+ scanner.nextLine());
					}
				} else if (command.equals("login")) {
					String user = scanner.next();
					String psw = scanner.next();
					writer.write(command + " " + user + " " + psw);
				} else if (command.equals("logout")) {
					writer.write(command);
				} else if (command.equals("who")) {
					writer.write(command);
				}
				// send to server
				writer.write("\n");
				writer.flush();
			}
		}
	}
}