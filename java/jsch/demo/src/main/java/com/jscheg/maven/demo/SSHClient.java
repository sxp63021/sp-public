package com.jscheg.maven.demo;
//todo - to use the same API, everytime TM code changes, in this code change the package name
//   
import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

import org.apache.log4j.Logger;

import com.jcraft.jsch.*;

// http://www.jcraft.com/jsch/examples/

public class SSHClient {
	
	//todo
	private static final Logger LOGGER = Logger.getLogger(SSHClient.class);
	private static final int ConnectionPort = 22;
	private static final int ConnectionTimeOut = 60000; 
	
	// some of the methods needed in this class that need to be exposed or public
	// a. Run a commnad on the IP and capture the output, capture any error
	// b. scp a file or list of files to the IP
	// c. run a command/commands on the IP, capture output of the command, or timeout

	// default constructor
	private SSHClient() {	
	}
	
	/*Input variables:
	 * String ip - check for dot notation, IPv4 supported at this time
	 * String uname - username to connect with
	 * String credential - password to use
	 * String command - execute this command, after connecting to IP
	 * 
	 * Return value:
	 * a. success/error
	 * b. Capture of Stream (in success or failure case)
	 * c. 
	 * 
	 * Scenario:
	 * 1. Not able to establish ssh connection
	 * 2. Not able to run the command - no output
	 * 
	 * Description:
	 * todo - when writing an API, do i need to handle the exceptions or throw them, so the calling
	 *        method will take care of it
	 *        
	 */
	public static InputStream runACommand(String host, String uname, String credential, String commandtorun) {
		
		String returnval = null;
		
		// check if the host is not null
		// check if uname is not null
		// check if credential is not null
		// check if the commandlst is not empty
		
		// connect to the IP using ssh
		JSch jschSSHChannel;
		
		jschSSHChannel = new JSch();
		String knownhostfname = "C:\\temp\\jsch_knownhosts";
		
		try {
		      jschSSHChannel.setKnownHosts(knownhostfname);
		} catch(JSchException ex) {
		      LOGGER.error("Satish in catch when setting known host files: " + ex);
			  LOGGER.error(ex.getMessage());
			  return null;
		}
		
		// will throw exception if username or host is wrong
		Session session;
		try {
			
			session = jschSSHChannel.getSession(uname, host, ConnectionPort);
			session.setTimeout(10000); // 10 second timeout
		} catch (JSchException ex) {
			LOGGER.error("either host or username are wrong : " + ex);
			LOGGER.error(ex.getMessage());
			return null; // or throw exception
		}
		
		session.setPassword(credential);
		
		java.util.Properties config = new java.util.Properties(); 
	    config.put("StrictHostKeyChecking", "no");
	    session.setConfig(config);
	      
	      // UNCOMMENT THIS FOR TESTING PURPOSES, BUT DO NOT USE IN PRODUCTION
	      // sesConnection.setConfig("StrictHostKeyChecking", "no")
		try {
			session.connect(ConnectionTimeOut);
		} catch (JSchException ex) {
			LOGGER.error("Exception during connect : " + ex);
			LOGGER.error(ex.getMessage());
			return null; // or throw exception
		}
		
		// Open a channel
		Channel channel;
		InputStream commandOutput;
		StringBuilder outputBuffer = new StringBuilder();
		ByteArrayOutputStream baos =  new ByteArrayOutputStream();;
		
		try {
			channel= session.openChannel("exec");
			LOGGER.info("Executing Command: " + commandtorun);
			((ChannelExec)channel).setCommand(commandtorun);
			commandOutput = channel.getInputStream();
			// todo - process error stream as well
			channel.connect();
			
			//todo - start a thread to keep reading from commandOutput
			// so we get the entire output
			BufferedReader reader = new BufferedReader(new InputStreamReader(commandOutput));
			String s;
	    	int linecnt = 0;
	    	while ((s = reader.readLine()) != null) {
	    		linecnt += 1;
	    		//logger.info(myname + ":" + linecnt + ":" + s);
	    		//builder.add(s);
	    		baos.write(s.getBytes()); baos.write('\n');
	    	}
			/*
			int readByte = commandOutput.read();
			
			while(readByte != 0xffffffff) {
				
				//baos.write(s.getBytes()); baos.write('\n');
				
				outputBuffer.append((char)readByte);
				readByte = commandOutput.read();
			} */

			channel.disconnect();
		      
			
		} catch (IOException ex) { 
			LOGGER.error("Exception during getting channel or connect : " + ex);
			LOGGER.error(ex.getMessage());
			return null; // or throw exception
		} catch (JSchException ex) {
			LOGGER.error("Exception during getting input stream : " + ex);
			LOGGER.error(ex.getMessage());
			return null; // or throw exception
		}
		
		return new ByteArrayInputStream(baos.toByteArray());
	}
	
	public static void main(String[] args) {
		System.out.println("Hello World");
		

		String ip = "192.168.86.154";
		
		final InputStream is = SSHClient.runACommand(ip, "satishp", "wrong", "uname -a");
		
		BufferedReader br = new BufferedReader(new InputStreamReader(is));
		String line = null;
		try {
			while ((line = br.readLine()) != null) {
				System.out.println("IP: " + ip + " Readline: " + line);
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			System.out.println(e.toString());
		}
		
		
	}
}


