import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

//Create a Class that uses ActionListener (Receiving Action events Interface)
public class Layouts implements ActionListener
{
    private JFrame frame;
    private JLabel topbar;
    private JTextArea textbox;
    private JButton wraptext;
    private JButton notwraptext;
    private JButton blank;
    private JButton cleartext;
    private JButton scrollv;
    private JButton scrollh;
    private JButton nscroll;

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
        frame = new JFrame("Layout Graphical User Interface Program");
        frame.setPreferredSize(new Dimension(400, 300));
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        Container contentPane = frame.getContentPane();
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);

        topbar = new JLabel("Use the buttons to control the layout of the text you type.");
        frame.add(topbar, BorderLayout.PAGE_START);
    }

    //START THE PROGRAM BY USING MAIN TO OPERATE GUI
    public static void main (String args[])
    {
        System.out.println("starting gui objects");
        Layouts gui = new Layouts();
        gui.start();
    }

    public void actionPerformed(ActionEvent e)
    {

    }
}
