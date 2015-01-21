import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Iterator;

/**
 * @author FNU Saqiurila
 * @id 14227763
 * @data Dec.19 2014
 * @description Server side of chat room
 */
public class Server {
	final static int MAXCLIENT = 3;
	private static String usersFile = "users.txt";
	private static ArrayList<String> users = new ArrayList<String>();
	private static ArrayList<Socket> sockets = new ArrayList<Socket>();

	public static void main(String args[]) throws IOException, InterruptedException {
		// Create a server socket
		int port = 17763;
		ServerSocket server = new ServerSocket(port);
		// create at most 3 threads. Each one contains a socket connected to a
		// client.
		while (true) {
			if(users.size()<MAXCLIENT){
				Socket socket = server.accept();
				sockets.add(socket);
				new Thread(new Task(socket)).start();
			} else{
				Thread.sleep(1000);
			}
		}
	}

	/**
	 * Thread Class that deals with client's request
	 */
	static class Task implements Runnable {

		private Socket socket;
		private String me = ""; // the client of this thread

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
			// Every loop receives a request from client and deals with it.
			while (true) {
				BufferedReader br = new BufferedReader(new InputStreamReader(
						socket.getInputStream()));
				Writer writer = new OutputStreamWriter(socket.getOutputStream());
				String request = br.readLine();

				if (request.equals("logout")) {
					// Broadcast the client is leaving
					Iterator<Socket> it = sockets.iterator();
					while (it.hasNext()) {
						Socket socket = it.next();
						if (socket != this.socket) {
							PrintWriter out = new PrintWriter(
									socket.getOutputStream(), true);
							out.println(me + " left.");
						} else {
							// Remove the client from sockets list
							it.remove();
							
						}
					}
					// Remove the client from users list
					for (String user : users) {
						if (user.equals(me)) {
							users.remove(user);
							break;
						}
					}
					writer.write("logout\n");
					writer.flush();
					System.out.println(me + " logout");
					me = "";
					break;
				} else if (request.equals("who")) {
					String userlist = "";
					// Append all usernames to userlist
					for (String user : users) {
						userlist += user + " ";
					}
					writer.write(userlist + "\n");
				} else {
					String[] temp = request.split(" ");
					if (temp[0].equals("login")) {
						String username = temp[1];
						String pwd = temp[2];
						if (verifyUser(username, pwd)) {
							// Add to userlist
							users.add(username);
							// Broadcast the news
							for (Socket socket : sockets) {
								if (socket != this.socket) {
									PrintWriter out = new PrintWriter(
											socket.getOutputStream(), true);
									out.println(username + " joins.");
								}
							}
							me = username;
							writer.write("Login confirmed\n");
							System.out.println(username + " login");
						} else {
							writer.write("Username or password is not right!\n");
						}
					} else if (temp[0].equals("sendall")) {
						// Make sure the client's already login
						if (me != null || !me.equals("")) {
							String msg = "";
							// Put the message back together
							for (int i = 1; i < temp.length; i++) {
								msg += temp[i] + " ";
							}
							// Broadcast the message
							for (Socket socket : sockets) {
								if (socket != this.socket) {
									PrintWriter out = new PrintWriter(
											socket.getOutputStream(), true);
									out.println(me + ":" + msg);
								}
							}
							System.out.println(me + ":" + msg);
						} else {
							writer.write("Denied. Please login first.\n");
						}
					} else if (temp[0].equals("send")) {
						// Make sure the client's already login
						if (me != null || !me.equals("")) {
							String sendto = temp[1];
							String msg = "";
							// Put the message back together
							for (int i = 2; i < temp.length; i++) {
								msg += temp[i] + " ";
							}
							// Find the destination
							for (int i = 0; i < users.size(); i++) {
								// Unicast the message
								if (users.get(i).equals(sendto)) {
									PrintWriter out = new PrintWriter(sockets
											.get(i).getOutputStream(), true);
									out.println(me + ":" + msg);
									break;
								}
							}
							System.out.println(me + " (to " + sendto + ")"
									+ ":" + msg);
						} else {
							writer.write("Denied. Please login first.\n");
						}
					} else {
						writer.write("Wrong command!\n");
					}
				}
				writer.flush();
			}

		}

		private static boolean verifyUser(String user, String pwd) {
			try {
				BufferedReader br = new BufferedReader(
						new FileReader(usersFile));
				String s = br.readLine();
				while (s != null) {
					String[] users = s.split(" ");
					if (users[0].equals(user) && users[1].equals(pwd)) {
						br.close();
						return true;
					}
					s = br.readLine();
				}
				br.close();
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			} catch (IOException e) {
				e.printStackTrace();
			}

			return false;
		}
	}
}
