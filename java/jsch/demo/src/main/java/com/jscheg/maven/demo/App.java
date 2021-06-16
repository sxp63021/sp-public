package com.jscheg.maven.demo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.InetAddress;
import java.net.UnknownHostException;

// http://tutorials.jenkov.com/java-howto/java-command-line-argument-parser.html


import org.apache.log4j.*;;

/**
 * Hello world!
 * compiling from commandline to get it working
 * mvn clean compile assembly:single
 *
 */
//todo - make changes to logging to a particular file
// logging example: https://www.javatpoint.com/log4j-maven

public class App 
{
	private static final Logger LOGGER = Logger.getLogger(App.class);
	private static String uname;			// username to access the system
	private static String uauth;			// authentication details to access the system
	private static String hostip;			// IP address of the host/cell
	private static String cmdtype;			// run a command on host -OR- transfer a file to host
	private static String cmdtorun;		// if cmdtype=="runcmd", this value will be populated
	private static String transferfile;	// if cmdtype=="copyfile", this value will be populated
	
	private static void printUsage() {
		LOGGER.info("Usage of this application");;
		LOGGER.info("java -jar filename.jar <username> <password> <ip address> [runcmd|copyfile] [command to run|file to transfer]");
		LOGGER.info("java -jar filename.jar \"unameabc\" \"passwordkey\"  \"192.168.2.10\" \"runcmd\" \"whoami\" ");
	}
	
	private static boolean parseCommandLineArgs(String[] args) {
		int i = 0, j;
		String arg;
		boolean returntype = true;
		String inputarg = null;
		
		if (5 != args.length) {
			LOGGER.info("insufficient number of arguments");
			printUsage();
			return false;
		}
		
		while (i < args.length) {
            arg = args[i];

            // use this type of check for "-help" in the arguments
            if (arg.equals("-help")) {
                LOGGER.info("Help command in argument");
                printUsage();
                returntype = false;
                return returntype;
            }
            
            switch (i) {
            case 0:
            		uname = arg;
            		break;
            case 1:
            		uauth = arg;
            		break;
            case 2:
            		hostip = arg;
            		break;
            case 3:
            		cmdtype = arg;
            		break;
            case 4:
            		inputarg = arg;
            		break;
            default:
            		LOGGER.error("Unknown case - " + arg);
            		returntype = false;
            		return returntype;
            }

            i++;
        }
		
		if (cmdtype.equals("runcmd")) {
			cmdtorun = inputarg;
		} else if (cmdtype.equals("copyfile")) {
			transferfile = inputarg;
		} else {
			LOGGER.error("Incorrect command type passed - " + cmdtype);
			printUsage();
			return false;
		}
		
		return returntype;
	}
	
    public static void main( String[] args )
    {
        System.out.println( "Hello World!" );
        
        
        // basic log4j configurator  
        BasicConfigurator.configure();  // print it to screen for now. 
        //todo figure out how to send it to a file later
        LOGGER.info("Hello world");  
        LOGGER.info("we are in logger info mode");  
        
        // Debug to see input args
//        for(int i = 0; i < args.length; i++) { LOGGER.info(i + " - " + args[i]); }

        // parse input arguments
        // need username, password, ip address, "runcmd/copyfile", "command to run / location to pick up the file from to copy"
        // call function to parse input arguments
        if (!parseCommandLineArgs(args)) {
        	LOGGER.error("Correct verbage not being followed, pass correct args");
        	return;
        }
        
        LOGGER.info("Running a small test");
        /*
         * Try to see if you can ping 192.168.2.11 before trying the next steps
         */
        
        try {
			InetAddress inet = InetAddress.getByName(hostip);
			boolean hostReachable = inet.isReachable(1000);
			if (hostReachable) {
				LOGGER.info("Able to reach host, proceeding with ssh test");
			} else {
				LOGGER.info("Not able to reach the host, skipping ssh test");
				return;
			}
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			LOGGER.error("Exception: " + e1);
		}
        
        if (cmdtype.equals("runcmd")) {
        	final InputStream is = SSHClient.runACommand(hostip, uname, uauth, cmdtorun);
            
            BufferedReader br = new BufferedReader(new InputStreamReader(is));
    		String line = null;
    		int count = 0;
    		try {
    			while ((line = br.readLine()) != null) {
    				count++;
    				LOGGER.info(count + " output: " + line);
    			}
    		} catch (IOException e) {
    			// TODO Auto-generated catch block
    			LOGGER.error("Exception: " + e);
    		}
        } else if (cmdtype.equals("copyfile")) { // copyfile
        	LOGGER.error("Not supporting copyfile yet");
        	
        }
        
	
		LOGGER.info("End of small test");
		return;
    }
    
}
