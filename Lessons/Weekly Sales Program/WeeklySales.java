import java.util.Scanner;

public class WeeklySales
{



    public class Sale
    {
        // Name of Sale
        private String saleName = "";
        // Amount of Sale
        private double saleAmount = 0;
        // Day of Sale
        private String saleDay;
        // Number of Sale
        private int saleNumber = 0;

        public void setSaleAmount(double amount)
        {
            saleAmount = amount;
        }
        public double getSaleAmount()
        {
            return saleAmount;
        }
        public void setSaleDay(String day)
        {
            saleDay = day;
        }
        public String getSaleDay()
        {
            return saleDay;
        }
        public String getSaleName()
        {
            return saleName;
        }

        public void setSaleName(String name)
        {
            saleName = name;
        }

    }

    public double calculateTotalSales(Sale[] sales, char certainDay) {

        return 0;
    }




    public static void main(String[] args)
    {
        System.out.println("* * W E E K L Y  S A L E S * *");

        System.out.println("Enter in the sale name: ");
        System.out.println("Enter in the sale amount : ");
        System.out.println("Enter in the sale day (M TU W TH F SA SU) : ");
        System.out.println(" [x] S A L E [] P R O C E S S E D [x] ");

    }


}
