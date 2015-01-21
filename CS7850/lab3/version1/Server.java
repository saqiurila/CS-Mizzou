

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * @author FNU Saqiurila
 * @id 14227763
 * @data Dec.19 2014
 * @description Server side of chat room
 */
public class Server {
	private static String usersFile = "users.txt";

	public static void main(String args[]) throws IOException {
		//Create a new server socket
		int port = 17763;
		ServerSocket server = new ServerSocket(port);
		// server waits for connection request from other socket
		while(true){
			System.out.println("Waiting for a client to connect..");
			Socket socket = server.accept();
			System.out.println("Client connected!");
			
			String user = "";
			BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			Writer writer = new OutputStreamWriter(socket.getOutputStream());
			//Every loop receives and deal with one request
			while (true) {			
				String request = br.readLine();		
				if (request.equals("logout")) {
					user = "";
					writer.write("Server:logout\n");
					writer.flush();
					break;
				} else {
					String[] temp = request.split(" ");
					if (temp[0].equals("login")) {
						String username = temp[1];
						String pwd = temp[2];
						if (verifyUser(username, pwd)) {
							//login
							user = username;
							writer.write("Server:" + user + " joins.\n");
							System.out.println(user + " login");
						} else {
							writer.write("Server:Username or password is not right!\n");
						}
					} else if (temp[0].equals("newuser")) {
						//Creating a new user
						String newUser = temp[1];
						String newPwd = temp[2];
						if(newUser.length()>=32){
							writer.write("Username should be less than 32!\n");
							writer.flush();
							continue;
						} else if(newPwd.length()>8||newPwd.length()<4){
							writer.write("Password should between 4 and 8!\n");
							writer.flush();
							continue;
						}
						if(checkNewUser(newUser)){
							createNewUser(newUser, newPwd);
						
							writer.write("New account has been create!\n");
							System.out.println("Create new account:" + newUser);
						} else{
							writer.write("The username already exists!\n");
						}
					} else if (temp[0].equals("send")) {
						// Make sure the client's already login
						if (user != null && !user.equals("")) {
							String msg = "";
							// Put the message back together
							for (int i = 1; i < temp.length; i++) {
								msg += temp[i] + " ";
							}
							writer.write(user + ":" + msg + "\n");
							System.out.println(user + ":" + msg);
						} else {
							writer.write("Server:Denied. Please login first.\n");
						}
					} else {
						writer.write("Server:Wrong command!\n");
					}
				}
				writer.flush();
			}
		}
	}

	private static boolean checkNewUser(String newUser) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(usersFile));
			String s = br.readLine();
			while (s != null) {
				String[] users = s.split(" ");
				if (users[0].equals(newUser)) {
					br.close();
					return false;
				}
				s = br.readLine();
			}
			br.close();
			return true;			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return false;
	}

	private static void createNewUser(String newUser, String newPwd) {
		try {
			FileWriter writer = new FileWriter(usersFile,true);
			writer.write(newUser + " " + newPwd + "\r\n");
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	private static boolean verifyUser(String user, String pwd) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(usersFile));
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