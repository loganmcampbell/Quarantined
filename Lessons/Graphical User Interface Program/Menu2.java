import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Menu2 implements ActionListener
{
    private JFrame frame;

    public static void main (String[] args)
    {
        Menu2 gui = new Menu2();
        gui.start();
    }

    public void start()
    {
        frame = new JFrame("GUI Menus");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container contentPane = frame.getContentPane();

        makeMenus();

        frame.setSize(300, 300);
        frame.setVisible(true);
    }

    private void makeMenus()
    {
        JMenuBar menuBar;
        JMenu menu;
        JMenuItem menuItem;

        menuBar = new JMenuBar();
        frame.setJMenuBar(menuBar);

        // set up the File menu
        menu = new JMenu("File");
        menuBar.add(menu);

        // add File menu items
        menuItem = new JMenuItem("New");
        menuItem.addActionListener(this);
        menu.add(menuItem);
        menuItem = new JMenuItem("Open...");
        menuItem.addActionListener(this);
        menu.add(menuItem);
        menuItem = new JMenuItem("Save");
        menuItem.addActionListener(this);
        menu.add(menuItem);
        menuItem = new JMenuItem("Save As...");
        menuItem.addActionListener(this);
        menu.add(menuItem);
        menu.addSeparator();
        menuItem = new JMenuItem("Exit");
        menuItem.addActionListener(this);
        menu.add(menuItem);
    }

    public void actionPerformed(ActionEvent e)
    {
        if (e.getActionCommand().equals("New"))
            newMethod();
        else if (e.getActionCommand().equals("Open..."))
            openMethod();
        else if (e.getActionCommand().equals("Save"))
            saveMethod();
        else if (e.getActionCommand().equals("Save As..."))
            saveAsMethod();
        else if (e.getActionCommand().equals("Exit"))
            exitMethod();
    }

    private void newMethod()
    {
        JOptionPane.showMessageDialog(frame,
                "The  File > New  menu option was clicked",
                "Menu Item Click",
                JOptionPane.INFORMATION_MESSAGE);
    }

    private void openMethod()
    {
        JOptionPane.showMessageDialog(frame,
                "The  File > Open...  menu option was clicked",
                "Menu Item Click",
                JOptionPane.INFORMATION_MESSAGE);
    }

    private void saveMethod()
    {
        JOptionPane.showMessageDialog(frame,
                "The  File > Save  menu option was clicked",
                "Menu Item Click",
                JOptionPane.INFORMATION_MESSAGE);
    }

    private void saveAsMethod()
    {
        JOptionPane.showMessageDialog(frame,
                "The  File > Save As...  menu option was clicked",
                "Menu Item Click",
                JOptionPane.INFORMATION_MESSAGE);
    }

    private void exitMethod()
    {
        System.exit(0);
    }
}