import java.io.IOException;
import java.lang.management.ManagementFactory;
import java.net.ServerSocket;

public class JustOneProcess {
	static ServerSocket serverSocket = null;
	final static int port = 1024;
	
	public static void isAnotherSimilarProcessRunning() {
		String pname = "";
		try {
			pname = ManagementFactory.getRuntimeMXBean().getName();
		    System.out.println("Process ID for this app = " + pname);
		    serverSocket = new ServerSocket(port);
		    System.out.println(pname + " Able to bind to port:" + port);
		} catch (IOException e) {
		    System.out.println(pname + " Could not listen on port: " + port);
		    System.out.println(pname + " another instance must be running, exiting");
		    // ...
		    System.exit(1);
		}
	
	}

}
