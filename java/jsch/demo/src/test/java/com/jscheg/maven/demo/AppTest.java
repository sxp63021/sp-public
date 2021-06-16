package com.jscheg.maven.demo;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

/**
 * Unit test for simple App.
 */
public class AppTest 
{
    /**
     * Rigorous Test :-)
     */
    @Test
    public void shouldAnswerWithTrue()
    {
        assertTrue( true );
    }
    
    /**
     * Test of sendCommand method, of class SSHManager.
     */
    /*
  @Test
  public void testSendCommand()
  {
     System.out.println("sendCommand");

     //
     // YOU MUST CHANGE THE FOLLOWING
     // FILE_NAME: A FILE IN THE DIRECTORY
     // USER: LOGIN USER NAME
     // PASSWORD: PASSWORD FOR THAT USER
     // HOST: IP ADDRESS OF THE SSH SERVER
     //
     String command = "ls examples.desktop";
     String userName = "test";
     String password = "test123";
     String connectionIP = "192.168.86.154";
     SSHManager instance = new SSHManager(userName, password, connectionIP, "");
     String errorMessage = instance.connect();

     if(errorMessage != null)
     {
        System.out.println(errorMessage);
        //fail();
        return;
     }

     String expResult = "examples.desktop\n";
     // call sendCommand for each command and the output 
     //(without prompts) is returned
     String result = instance.sendCommand(command);
     System.out.println("Value of Result: " + result);
     // close only after all commands are sent
     instance.close();
     assertEquals(expResult, result);
  }
  */
}
