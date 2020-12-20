import java.io.OutputStream;
import java.io.PrintStream;
import java.util.prefs.Preferences;
import static java.lang.System.setErr;
import static java.util.prefs.Preferences.systemRoot;

public class AdministratorChecker {
	
    public static final boolean IS_RUNNING_AS_ADMINISTRATOR;

    static
    {
        IS_RUNNING_AS_ADMINISTRATOR = isRunningAsAdministrator();
    }

    
    private static boolean isRunningAsAdministrator()
    {
        Preferences preferences = systemRoot();

        synchronized (System.err)
        {
            setErr(new PrintStream(new OutputStream()
            {
                @Override
                public void write(int b)
                {
                }
            }));

            try
            {
                preferences.put("acp_verizon", "admin_check"); // SecurityException on Windows
                preferences.remove("acp_verizon");
                preferences.flush(); // BackingStoreException on Linux
				System.out.println("running in admin");
                return true;
            } catch (Exception exception)
            {
				System.out.println("not running in admin");
                return false;
            } finally
            {
                setErr(System.err);
            }
        }
    }

}
