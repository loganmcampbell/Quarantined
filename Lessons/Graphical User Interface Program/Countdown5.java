import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Countdown5 implements ActionListener
{

        private JFrame frame;
        private JButton button;
        public static int counter = 1;

        public static void main (String[] args)
        {
            Countdown5 guiButton = new Countdown5();
            guiButton.start();
        }

        public void start()
        {
            frame = new JFrame("CountDown 5");
            frame.setPreferredSize(new Dimension(400, 300));
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            Container contentPane = frame.getContentPane();

            button = new JButton("Click on me!");
            button.addActionListener(this);
            contentPane.add(button);

            frame.pack();
            frame.setVisible(true);
        }

        public void actionPerformed(ActionEvent clicker)
        {

            JOptionPane.showMessageDialog(frame, " COUNTER => " + counter);
            counter++;
            if (counter > 5)
            {
                JOptionPane.showMessageDialog(frame, " YOU HIT 5 CLICKS!");
                frame.dispatchEvent(new WindowEvent(frame, WindowEvent.WINDOW_CLOSING));

            }


        }
}