import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

//Create a Class that uses ActionListener (Receiving Action events Interface)
public class Layouts implements ActionListener
{
    private JFrame frame;
    private JPanel panel1;
    private JPanel panel2;
    private JLabel topbar;
    private JTextArea textbox;
    private JButton wraptext;
    private JButton notwraptext;
    private JButton blank;
    private JButton cleartext;
    private JButton scrollv;
    private JButton scrollh;
    private JButton scrollb;
    private JButton scrolln;

    /*
        JAVA uses layout managers to have different Graphic User Interfaces.
        The four most used layout managers are BorderLayout/BoxLayout/FlowLayout/GridLayout.

        [BorderLayout]: divides its window into 5 parts that have fixed positions relative to each other. Each part can hold a component, and the size of the part controls the component's size.
            - BorderLayout region can only contain one component.
            - If one is left out empty then it will not show up in the window.
            - Even thought each region on holds one component; We can make a panel hold other components and use different layouts

        [BoxLayout]: allows each component to keep its own size. Stacks components in the order we add them and we can choose to stack them vertically or horizontally.
            - Components are the size of what is contained.
            - Can't be resized or rearranged.

        [FlowLayout]: like BoxLayout, places all components into the window by order we add them.
            - Dynamically changes position by wrapping components and centering them.

        [GridLayout]: puts components into a grid structure; we specify the number of rows and columns we want the grid to contain.
            - all components will have equal size based on the largest component

     */


    /*
        JAVA uses panels within layout managers.
        **Panels are used to add multiple components to a layout region that accepts only one**
        Panels can have their own layout managers and be used indifferently (like div).

     */

    public void start()
    {
        //CREATE WINDOW CONTAINS GUI
        frame = new JFrame("Layout Graphical User Interface Program");
        //SET DIMENSIONS
        frame.setPreferredSize(new Dimension(500, 500));
        //EXIT BUTTON TOOLBAR
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container contentPane = frame.getContentPane();
        frame.pack();


        topbar = new JLabel("Use the buttons to control the layout of the text you type.");
        frame.add(topbar, BorderLayout.NORTH);

        panel1  = new JPanel();
        panel1.setLayout(new BoxLayout(panel1, BoxLayout.Y_AXIS));
        wraptext = new JButton("Wrap Text");
        panel1.add(wraptext);
        notwraptext = new JButton (" Don't Wrap Text");
        panel1.add(notwraptext);
        blank = new JButton ("");
        panel1.add(blank);
        cleartext = new JButton ("Clear Text");
        panel1.add(cleartext);
        contentPane.add(panel1, BorderLayout.WEST);

        textbox = new JTextArea();
        contentPane.add(textbox, BorderLayout.CENTER);

        panel2 = new JPanel();
        panel2.setLayout(new BoxLayout(panel2, BoxLayout.Y_AXIS));
        scrollv = new JButton("Scroll Vertically");
        panel2.add(scrollv);
        scrollh = new JButton("Scroll Horizontally");
        panel2.add(scrollh);
        scrollb = new JButton("Scroll Both Ways");
        panel2.add(scrollb);
        scrolln = new JButton("Do Not Scroll");
        panel2.add(scrolln);

        contentPane.add(panel2, BorderLayout.EAST);

        // SET THE FRAME LOCATION IN CENTER OF SCREEN
        frame.setLocationRelativeTo(null);
        // AUTO SIZE AFTER CREATING GUI to DISPLAY
        frame.setVisible(true);

    }

    //START THE PROGRAM BY USING MAIN TO OPERATE GUI
    public static void main (String[] args)
    {
        System.out.println("starting gui objects");
        Layouts gui = new Layouts();
        gui.start();
    }

    public void actionPerformed(ActionEvent e)
    {

    }
}
