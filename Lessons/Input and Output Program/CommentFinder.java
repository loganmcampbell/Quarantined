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
        String[] files;
        files = directory.list();
        for(String file : files)
            System.out.println(file);
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
        String[] files;
        files = directory.list();
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
        String readFilePath;
        boolean pathString = false;
        while (!pathString)
        {
            System.out.print("Is the path directed to the folder containing file? ");
            String choice = userInput.nextLine();
            choice = choice.toUpperCase();
            while (choice.equals("YES") || choice.equals("NO"))
            {
                if (choice.equals("YES"))
                {
                    pathString = true;
                    break;
                }
                else
                    {
                        System.out.print("Add the following folder to the path : ");
                        folderName = userInput.nextLine();
                        currentDirectory = changeDirectory(folderName, currentDirectory);
                        choice = "";
                    }
            }
        }
        readFilePath = currentDirectory;
        System.out.print("Enter the file name & file type ('filename.filetype') : ");
        String fileType = userInput.nextLine();
        System.out.println("[FILE TYPE :: "+ fileType + "]");
        readFilePath += "\\" + fileType;
        System.out.println(readFilePath);
        try
        {
            Scanner read = new Scanner(new File(readFilePath));
            FileWriter comments = new FileWriter("comments.txt");
            FileWriter programming = new FileWriter("programming.txt");

            while (read.hasNext())
            {
                String words = read.nextLine();
                if (words.contains("//"))
                {
                    comments.write(words);
                    comments.write("\n");
                }
                else
                {
                    programming.write(words);
                    programming.write("\n");
                }
            }
            System.out.println("-------------------------------------------------");
            System.out.println("comments.txt and programming.txt has been created");
            System.out.println("-------------------------------------------------");
            programming.close();
            comments.close();
            read.close();
        }
        catch (IOException error)
        {
            System.out.println("ERROR IN IO");
        }

    }
}