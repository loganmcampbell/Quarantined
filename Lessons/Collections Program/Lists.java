import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Lists
{
    // window frame
    private JFrame frame;
    private JPanel contentPane;

    public static void main (String[] args)
    {
        Lists listGUI = new Lists();
        listGUI.start();
    }

    public void start()
    {
        frame = new JFrame("Lists");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        contentPane = (JPanel)frame.getContentPane();

        makeMenus();
        makeContent();

        frame.pack();
        frame.setVisible(true);
    }

    private void makeMenus()
    {
        JMenuBar menuBar;

        menuBar = new JMenuBar();
        frame.setJMenuBar(menuBar);

        // set up menus
        menuBar.add(makeFileMenu());
        menuBar.add(makeViewMenu());
        menuBar.add(makeHelpMenu());
    }

    private JMenu makeFileMenu()
    {
        JMenu menu;
        JMenuItem menuItem;

        // set up the File menu
        menu = new JMenu("File");
        menu.setMnemonic(KeyEvent.VK_F);

        // add Open menu item
        menuItem = new JMenuItem("Open...");
        menuItem.setMnemonic(KeyEvent.VK_O);
        menuItem.addActionListener(new OpenMenuItemListener());
        menuItem.setAccelerator(
                KeyStroke.getKeyStroke(KeyEvent.VK_O,
                        InputEvent.CTRL_MASK));
        menu.add(menuItem);

        // add Exit menu item
        menu.addSeparator();
        menuItem = new JMenuItem("Exit");
        menuItem.setMnemonic(KeyEvent.VK_X);
        menuItem.addActionListener(new ExitMenuItemListener());
        menuItem.setAccelerator(
                KeyStroke.getKeyStroke(KeyEvent.VK_Q,
                        Event.CTRL_MASK));
        menu.add(menuItem);

        return menu;
    }

    private JMenu makeViewMenu()
    {
        JMenu menu;
        JMenuItem menuItem;

        // set up the View menu
        menu = new JMenu("View");
        menu.setMnemonic(KeyEvent.VK_V);

        // add Next Player menu item
        menuItem = new JMenuItem("Next Player");
        menuItem.addActionListener(new NextMenuItemListener());
        menuItem.setAccelerator(
                KeyStroke.getKeyStroke(KeyEvent.VK_DOWN,
                        Event.ALT_MASK));
        menu.add(menuItem);

        // add Previous Player menu item
        menuItem = new JMenuItem("Previous Player");
        menuItem.addActionListener(new PrevMenuItemListener());
        menuItem.setAccelerator(
                KeyStroke.getKeyStroke(KeyEvent.VK_UP,
                        Event.ALT_MASK));
        menu.add(menuItem);

        // add Team View
        menu.addSeparator();
        menuItem = new JMenuItem("Team View");
        menuItem.addActionListener(new TeamMenuItemListener());
        menu.add(menuItem);

        // add Player View
        menuItem = new JMenuItem("Player View");
        menuItem.addActionListener(new PlayMenuItemListener());
        menu.add(menuItem);

        return menu;
    }

    private JMenu makeHelpMenu()
    {
        JMenu menu;
        JMenuItem menuItem;

        // set up the Help menu
        menu = new JMenu("Help");
        menu.setMnemonic(KeyEvent.VK_H);

        // add About menu item
        menuItem = new JMenuItem("About Lists");
        menuItem.setMnemonic(KeyEvent.VK_A);
        menuItem.addActionListener(new AboutMenuItemListener());
        menu.add(menuItem);

        return menu;
    }

    private void makeContent()
    {
        contentPane.setLayout(new BoxLayout(contentPane, BoxLayout.Y_AXIS));
        contentPane.setBorder(BorderFactory.createEmptyBorder(6,6,6,6));

        // player name
        JLabel nameLabel = new JLabel("Player Name:");
        nameLabel.setFont(new Font("Trebuchet MS",Font.BOLD + Font.ITALIC,14));
        contentPane.add(nameLabel);
        JTextField playerName = new JTextField();
        playerName.setFont(new Font("Trebuchet MS",Font.PLAIN,14));
        playerName.setForeground(Color.BLUE);
        contentPane.add(playerName);

        // player number
        JLabel numLabel = new JLabel("Player Number:");
        numLabel.setFont(new Font("Trebuchet MS",Font.BOLD + Font.ITALIC,14));
        contentPane.add(numLabel);
       JTextField playerNum = new JTextField();
        playerNum.setFont(new Font("Trebuchet MS",Font.PLAIN,14));
        playerNum.setForeground(Color.BLUE);
        contentPane.add(playerNum);

        // player position
        JLabel positionLabel = new JLabel("Position:");
        positionLabel.setFont(new Font("Trebuchet MS",Font.BOLD + Font.ITALIC,14));
        contentPane.add(positionLabel);
        JTextField playerPosition = new JTextField();
        playerPosition.setFont(new Font("Trebuchet MS",Font.PLAIN,14));
        playerPosition.setForeground(Color.BLUE);
        contentPane.add(playerPosition);

        // average points
        JLabel avgPtsLabel = new JLabel("Average Points per Game:");
        avgPtsLabel.setFont(new Font("Trebuchet MS",Font.BOLD + Font.ITALIC,14));
        contentPane.add(avgPtsLabel);
        JTextField playerAvgPts = new JTextField();
        playerAvgPts.setFont(new Font("Trebuchet MS",Font.PLAIN,14));
        playerAvgPts.setForeground(Color.BLUE);
        contentPane.add(playerAvgPts);

        // average rebounds
        JLabel avgReboundsLabel = new JLabel("Average Rebounds per Game:");
        avgReboundsLabel.setFont(new Font("Trebuchet MS",Font.BOLD + Font.ITALIC,14));
        contentPane.add(avgReboundsLabel);
        JTextField playerAvgRebounds = new JTextField();
        playerAvgRebounds.setFont(new Font("Trebuchet MS",Font.PLAIN,14));
        playerAvgRebounds.setForeground(Color.BLUE);
        contentPane.add(playerAvgRebounds);

        // average assists
        JLabel avgAssistsLabel = new JLabel("Average Assists per Game:");
        avgAssistsLabel.setFont(new Font("Trebuchet MS",Font.BOLD + Font.ITALIC,14));
        contentPane.add(avgAssistsLabel);
        JTextField playerAvgAssists = new JTextField();
        playerAvgAssists.setFont(new Font("Trebuchet MS",Font.PLAIN,14));
        playerAvgAssists.setForeground(Color.BLUE);
        contentPane.add(playerAvgAssists);
    }

    private class AboutMenuItemListener implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            JOptionPane.showMessageDialog(frame,
                    "Lists\n\nVersion 1.0\nBuild B200803275-1720\n\n" +
                            "(c) Copyright Merrill Hall 2008\nAll rights reserved\n\n" +
                            "Visit /\nEducation To Go\n" +
                            "Intermediate Java Course",
                    "About Lists",
                    JOptionPane.INFORMATION_MESSAGE);
        }
    }

    private class OpenMenuItemListener implements ActionListener
    {
        public void actionPerformed(ActionEvent ae)
        {
            JOptionPane.showMessageDialog(frame,
                    "The Open... menu item was selected",
                    "Open Menu Item",
                    JOptionPane.INFORMATION_MESSAGE);
        }
    }

    private class ExitMenuItemListener implements ActionListener
    {
        public void actionPerformed(ActionEvent e)
        {
            System.exit(0);
        }
    }

    private class NextMenuItemListener implements ActionListener
    {
        public void actionPerformed(ActionEvent ae)
        {
            JOptionPane.showMessageDialog(frame,
                    "The Next menu item was selected",
                    "Next Menu Item",
                    JOptionPane.INFORMATION_MESSAGE);
        }
    }

    private class PrevMenuItemListener implements ActionListener
    {
        public void actionPerformed(ActionEvent ae)
        {
            JOptionPane.showMessageDialog(frame,
                    "The Previous menu item was selected",
                    "Previous Menu Item",
                    JOptionPane.INFORMATION_MESSAGE);
        }
    }

    private class TeamMenuItemListener implements ActionListener
    {
        public void actionPerformed(ActionEvent ae)
        {
            JOptionPane.showMessageDialog(frame,
                    "The Team View menu item was selected",
                    "Team View Menu Item",
                    JOptionPane.INFORMATION_MESSAGE);
        }
    }

    private class PlayMenuItemListener implements ActionListener
    {
        public void actionPerformed(ActionEvent ae)
        {
            JOptionPane.showMessageDialog(frame,
                    "The Player View menu item was selected",
                    "Player View Menu Item",
                    JOptionPane.INFORMATION_MESSAGE);
        }
    }

}