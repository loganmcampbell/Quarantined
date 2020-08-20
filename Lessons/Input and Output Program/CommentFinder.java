import java.util.*;
import java.io.*;
public class CommentFinder
{
    public static String changeDirectory (String folderName, String currentDirectory)
    {

        currentDirectory += "\\" + folderName;
        System.setProperty("user.dir", currentDirectory );
        currentDirectory = System.getProperty("user.dir");
        File directory = new File(System.getProperty("user.dir"));
        System.out.println("-------------------------------------");
        String files [] = directory.list();
        for(String file : files)
        {
            System.out.println(file);
        }
        System.out.println("-------------------------------------");
        return currentDirectory;
    }
    public static void main (String[] args)
    {
        System.out.println(("======================"));
        System.out.println(("COMMENT FINDER PROGRAM"));
        System.out.println(("======================"));
        System.out.println("-------------------------------------");
        File directory = new File(System.getProperty("user.dir"));
        String currentDirectory = System.getProperty("user.dir");
        System.out.println("[CURRENT DIRECTORY] : " + currentDirectory);
        String files[] = directory.list();
        for(String file : files)
        {
            System.out.println(file);
        }
        System.out.println("-------------------------------------");
        Scanner userInput = new Scanner(System.in);  // Create a Scanner object
        System.out.print("Enter the folder name where this program is executed at : ");
        String folderName = userInput.nextLine();
        currentDirectory = changeDirectory(folderName, currentDirectory);
        System.out.println("CURRENT : " + currentDirectory);
        boolean pathstring = false;
        while (pathstring)
        {
            System.out.print("Is the path directed to the folder containing file? ");
            String choice = userInput.nextLine();
            choice = choice.toUpperCase();
            while (choice.equals("YES") || choice.equals("NO"))
            {
                if (choice.equals("YES"))
                {
                    pathstring = true;
                }
                else
                    {
                        System.out.println("Add the following file(s) to the path : ");
                        folderName = userInput.nextLine();
                        changeDirectory(folderName, currentDirectory);
                    }
            }
        }

        System.out.print("Enter the file name & file type ('filename.filetype') : ");
        String fileType = userInput.nextLine();
        System.out.println("[FILE TYPE :: "+ fileType + "]");

    }
}