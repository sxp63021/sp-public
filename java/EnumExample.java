import java.util.*;
import java.lang.*;
import java.io.*;

//public enum ErrorCode {
enum ErrorCode {
    ABC_ERROR_NEG_1("Negative One", -1),
    ABC_ERROR_0("Zero", 0),
    ABC_ERROR_1("One", 1),
    ABC_ERROR_2("Two", 2),
    ABC_ERROR_3("Three", 3),
    ABC_ERROR_10("Ten", 10),
    ABC_ERROR_NEG_50("Negative Fifty", -50);

    private final String description;
    private final int code;

    ErrorCode(String description, int code) {
        this.description = description;
        this.code = code;
    }

    public String getDescription() {
        return description;
    }

    public int getCode() {
        return code;
    }

    // Method to get ErrorCode by code
    public static ErrorCode getByCode(int code) {
        for (ErrorCode errorCode : values()) {
            if (errorCode.getCode() == code) {
                return errorCode;
            }
        }
        throw new IllegalArgumentException("No ErrorCode found for code: " + code);
    }

    // Method to get ErrorCode by description
    public static ErrorCode getByDescription(String description) {
        for (ErrorCode errorCode : values()) {
            if (errorCode.getDescription().equalsIgnoreCase(description)) {
                return errorCode;
            }
        }
        throw new IllegalArgumentException("No ErrorCode found for description: " + description);
    }
}


public class EnumExample {
    public static void main(String[] args) {
        // Using enum directly
        System.out.println(ErrorCode.ABC_ERROR_NEG_1.getCode());  // Output: -1
        System.out.println(ErrorCode.ABC_ERROR_NEG_1.getDescription());  // Output: Negative One

        // Getting ErrorCode by code
        ErrorCode error = ErrorCode.getByCode(-50);
        System.out.println("Error: " + error + ", Description: " + error.getDescription());
        // Output: Error: ABC_ERROR_NEG_50, Description: Negative Fifty

        // Getting ErrorCode by description
        ErrorCode errorByDesc = ErrorCode.getByDescription("Zero");
        System.out.println("Error: " + errorByDesc + ", Code: " + errorByDesc.getCode());
        // Output: Error: ABC_ERROR_0, Code: 0

        // Using in a switch statement
        ErrorCode testError = ErrorCode.ABC_ERROR_2;
        switch (testError) {
            case ABC_ERROR_NEG_1:
                System.out.println("Negative one error");
                break;
            case ABC_ERROR_0:
                System.out.println("Zero error");
                break;
            case ABC_ERROR_2:
                System.out.println("Error two occurred");
                break;
            default:
                System.out.println("Other error");
        }
        // Output: Error two occurred
    }
}

